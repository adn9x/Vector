#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#define INIT_CAPACITY 4

struct vector {

    void **items;
    int capacity;
    int total;
};

typedef struct vector Vector;

void vector_init(Vector *);
int vector_total(const Vector *);
void vector_add(Vector *, void *);
static void vector_resize(Vector *, int );
void *vector_get(Vector *, int);
void vector_remove(Vector *, int);
void vector_free(Vector *);
void vector_set(Vector *, int, void *);
int vector_capacity(const Vector *);


#endif // VECTOR_H_INCLUDED
