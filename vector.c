#include <stdlib.h>
#include "vector.h"


void vector_init(Vector *vector) {
    vector->capacity = INIT_CAPACITY;
    vector->total = 0;
    vector->items = malloc(sizeof(void *) * vector->capacity);
}

int vector_total(const Vector * vector) {
    return vector->total;
}

int vector_capacity(const Vector * vector) {
    return vector->capacity;
}

void vector_remove(Vector * vector, int index) {
    if (index < 0 || index >= vector->total) {
        return;
    }

    int i = 0;

    for (i = index; i < vector->total - 1; i++) {
        vector->items[i] = vector->items[i + 1];
    }


    vector->total--;
    if (vector->total > 0 && vector->total == vector->capacity / 4) {
        vector_resize(vector, vector->capacity / 2);
    }
}



void vector_resize(Vector *vector, int capacity) {

    void **items = realloc(vector->items, sizeof(void *) * capacity);

    if (items) {
        vector->items = items;
        vector->capacity = capacity;

    }
}

void vector_add(Vector *vector, void *item) {

    Vector *oldVector = vector;

    if (vector->capacity == vector->total) {

        vector_resize(vector, vector->capacity * 2);
    }

    vector->items[vector->total++] = item;
}

void * vector_get(Vector *vector, int index) {

    if (index >= 0 && index < vector->total) {
        return vector->items[index];
    }
    return NULL;
}

void vector_set(Vector *vector, int index, void *item) {

        if (index >= 0 && index < vector->total) {
            vector->items[index] = item;
        }
}


// free memory of items, call it when vector is no longer used
void vector_free(Vector *vector) {
    free(vector->items);

}


