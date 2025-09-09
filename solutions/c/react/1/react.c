#include "react.h"

#include <stdlib.h>

static unsigned long long ID = 0;

struct reactor *create_reactor(void) {
    struct reactor *new_reactor = calloc(1, sizeof(struct reactor));
    return new_reactor;
}

void destroy_reactor(struct reactor *r) {
    while (r->cells) {
        struct child *child = r->cells->children;
        while (child) {
            struct child *temp = child->next;
            free(child);
            child = temp;
        }

        struct callback *callback = r->cells->callbacks;
        while (callback) {
            struct callback *temp = callback->next;
            free(callback);
            callback = temp;
        }

        struct cell *temp = r->cells->next;
        free(r->cells);
        r->cells = temp;
    }

    free(r);
}

static struct cell *create_new_generic_cell(struct reactor *r) {
    struct cell *new_cell = calloc(1, sizeof(struct cell));
    new_cell->next = r->cells;
    r->cells = new_cell;
    return new_cell;
}

static void add_child(struct cell *p, struct cell *c) {
    struct child *new_child = calloc(1, sizeof(struct child));
    new_child->cell = c;
    new_child->next = p->children;
    p->children = new_child;
}

struct cell *create_input_cell(struct reactor *r, int initial_value) {
    struct cell *new_cell = create_new_generic_cell(r);
    new_cell->value = initial_value;
    new_cell->type = INPUT_CELL;
    return new_cell;
}

struct cell *create_compute1_cell(struct reactor *r, struct cell *c,
                                  compute1 f) {
    struct cell *new_cell = create_new_generic_cell(r);
    new_cell->cell1 = c;
    new_cell->f1 = f;
    new_cell->value = f(c->value);
    new_cell->type = COMPUTE1_CELL;
    add_child(c, new_cell);
    return new_cell;
}

struct cell *create_compute2_cell(struct reactor *r, struct cell *c1,
                                  struct cell *c2, compute2 f) {
    struct cell *new_cell = create_new_generic_cell(r);
    new_cell->cell1 = c1;
    new_cell->cell2 = c2;
    new_cell->f2 = f;
    new_cell->value = f(c1->value, c2->value);
    new_cell->type = COMPUTE2_CELL;
    add_child(c1, new_cell);
    add_child(c2, new_cell);
    return new_cell;
}

int get_cell_value(struct cell *c) { return c->value; }

static int update_cell_value(struct cell *c) {
    int old_value = c->value;

    switch (c->type) {
        case COMPUTE1_CELL:
            c->value = c->f1(c->cell1->value);
            break;
        case COMPUTE2_CELL:
            c->value = c->f2(c->cell1->value, c->cell2->value);
        case INPUT_CELL:
            break;
    }

    c->updated = 1;
    return old_value != c->value;
}

static void update_all_cell_children(struct cell *c) {
    if (c->cell1 && !c->cell1->updated) return;
    if (c->cell2 && !c->cell2->updated) return;

    if (update_cell_value(c)) {
        struct callback *callback = c->callbacks;

        while (callback) {
            callback->f(callback->arg, c->value);
            callback = callback->next;
        }
    }

    struct child *child = c->children;
    while (child) {
        child->cell->updated = 0;
        child = child->next;
    }

    child = c->children;
    while (child) {
        update_all_cell_children(child->cell);
        child = child->next;
    }
}

void set_cell_value(struct cell *c, int new_value) {
    c->value = new_value;
    update_all_cell_children(c);
}

callback_id add_callback(struct cell *c, void *v, callback f) {
    struct callback *new_callback = calloc(1, sizeof(struct callback));
    new_callback->f = f;
    new_callback->arg = v;
    new_callback->id = ID++;
    new_callback->next = c->callbacks;
    c->callbacks = new_callback;
    return new_callback->id;
}

void remove_callback(struct cell *c, callback_id id) {
    struct callback *callback = c->callbacks;

    while (callback) {
        if (callback->next && callback->next->id == id) {
            struct callback *to_free = callback->next;
            callback->next = callback->next->next;
            free(to_free);
            return;
        }

        callback = callback->next;
    }
}