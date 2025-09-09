#ifndef REACT_H
#define REACT_H

typedef int (*compute1)(int);
typedef int (*compute2)(int, int);

typedef void (*callback)(void *, int);
typedef int callback_id;

enum type {
    INPUT_CELL,
    COMPUTE1_CELL,
    COMPUTE2_CELL
};

struct reactor {
    struct cell *cells;
};

struct cell {
    struct cell *next;
    compute1 f1;
    compute2 f2;

    struct cell *cell1;
    struct cell *cell2;

    int value;
    int updated;
    enum type type;

    struct child *children;
    struct callback *callbacks;
};

struct child {
    struct child *next;
    struct cell *cell;
};

struct callback {
    struct callback *next;
    callback f;
    void* arg;
    callback_id id;
};

struct reactor *create_reactor(void);
// destroy_reactor should free all cells created under that reactor.
void destroy_reactor(struct reactor *);

struct cell *create_input_cell(struct reactor *, int initial_value);
struct cell *create_compute1_cell(struct reactor *, struct cell *, compute1);
struct cell *create_compute2_cell(struct reactor *, struct cell *,
                                  struct cell *, compute2);

int get_cell_value(struct cell *);
void set_cell_value(struct cell *, int new_value);

// The callback should be called with the same void * given in add_callback.
callback_id add_callback(struct cell *, void *, callback);
void remove_callback(struct cell *, callback_id);

#endif
