// PROGRAMA p02.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_ITER 50000

int global = NUM_ITER;

void * thrfunc(void * arg) {
    int *count = (int *) malloc(sizeof(int)); // necessary
    *count = 0;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);

    for (; global > 0; global--) {
        printf("%s", (char *)arg);
        *count += 1;
    }

    pthread_exit(count); // same is writting return &count
}

int main() {
    pthread_t ta, tb;
    void * statusa;
    void * statusb;

    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");
    pthread_join(ta, &statusa);
    pthread_join(tb, &statusb);

    /* Will print some value between 0 and NUM_ITER */
    printf("\nTotal chars written by thread A: %d\n", *(int *)statusa);
    printf("Total chars written by thread B: %d\n", *(int *)statusb);

    /* Result is close but not equal to NUM_ITER */
    printf("Total ammount of written chars: %d\n", *(int *)statusa + *(int *)statusb);
    
    /* Avoid memory leaks */
    free(statusa);
    free(statusb);
    return 0;
}
