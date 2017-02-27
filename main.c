#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main()
{
    Vector vector;
    vector_init(&vector);
    vector_add(&vector, (void *) 4);
    vector_add(&vector, (void *) 5);
    vector_add(&vector, (void *) 6);
    vector_add(&vector, (void *) 7);
    vector_remove(&vector, 0);



    int i = 0;
    for (i = 0; i < vector_total(&vector); i++) {
        printf("%d - %d \n", vector_get(&vector, i), vector_capacity(&vector));

    }



    free(&vector);

    return 0;
}
