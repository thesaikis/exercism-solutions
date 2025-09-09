#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <inttypes.h>

typedef int buffer_value_t;

typedef struct {
    int capacity;
    int size;
    int start;
    int end;
    buffer_value_t* values;
} circular_buffer_t;

/*
 * Function: new_circular_buffer
 * ----------------------------
 * Creates a new circular buffer with the specified capacity.
 *
 * capacity: The maximum number of elements the buffer can hold.
 *
 * Returns: A pointer to the newly allocated circular buffer, or NULL if memory allocation fails.
 */
circular_buffer_t *new_circular_buffer(int capacity);


/*
 * Function: write
 * ----------------
 * Writes a value to the circular buffer.
 *
 * buffer: Pointer to the circular buffer.
 * value:  The value to be written to the buffer.
 *
 * Returns: 0 on success, or EXIT_FAILURE if the buffer is full (errno set to ENOBUFS).
 */
int16_t write(circular_buffer_t *buffer, buffer_value_t value);

/*
 * Function: overwrite
 * -------------------
 * Writes a value to the circular buffer, overwriting the oldest element if the buffer is full.
 *
 * buffer: Pointer to the circular buffer.
 * value:  The value to be written to the buffer.
 *
 * Returns: 0
 */
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value);

/*
 * Function: read
 * --------------
 * Reads the oldest value from the circular buffer.
 *
 * buffer: Pointer to the circular buffer.
 * value:  Pointer to store the read value.
 *
 * Returns: 0 on success, or EXIT_FAILURE if the buffer is empty (errno set to ENODATA).
 */
int16_t read(circular_buffer_t *buffer, buffer_value_t *value);

/*
 * Function: delete_buffer
 * -----------------------
 * Deletes the circular buffer and frees the allocated memory.
 *
 * buffer: Pointer to the circular buffer to be deleted.
 */
void delete_buffer(circular_buffer_t *buffer);

/*
 * Function: clear_buffer
 * ----------------------
 * Clears the circular buffer by setting all elements to zero and resetting the indices.
 *
 * buffer: Pointer to the circular buffer to be cleared.
 */
void clear_buffer(circular_buffer_t *buffer);
#endif
