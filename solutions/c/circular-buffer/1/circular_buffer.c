#include "circular_buffer.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

circular_buffer_t *new_circular_buffer(int capacity) {
    circular_buffer_t *buffer = malloc(sizeof(circular_buffer_t));

    if (!buffer) return NULL;
    
    buffer->capacity = capacity;
    buffer->size = 0;
    buffer->start = 0;
    buffer->end = 0;
    buffer->values = calloc(sizeof(buffer_value_t), capacity);

    if (!(buffer->values)) {
        free(buffer);
        return NULL;
    }

    return buffer;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
    // Check if buffer is empty
    if (buffer->size == 0) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    // Change pointer to buffer value
    *value = buffer->values[buffer->start];
    buffer->start = (buffer->start + 1) % buffer->capacity;
    buffer->size -= 1;

    return 0;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
    // Check if buffer is full
    if (buffer->size == buffer->capacity) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    // Set buffer value to given value
    buffer->values[buffer->end] = value;
    buffer->end = (buffer->end + 1) % buffer->capacity;
    buffer->size += 1;
    
    return 0;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
    // Check if buffer is full
    // Will discard value if needed
    if (buffer->size == buffer->capacity) {
        buffer_value_t trash;
        read(buffer, &trash);
    }

    return write(buffer, value);
}

void delete_buffer(circular_buffer_t *buffer) {
    free(buffer->values);
    free(buffer);
}

void clear_buffer(circular_buffer_t *buffer) {
    memset(buffer->values, 0, buffer->capacity);
    buffer->start = 0;
    buffer->end = buffer->start;
    buffer->size = 0;
}