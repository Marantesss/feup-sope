// PROGRAMA p03.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

void *PrintHello(void *threadnum) {
    printf("Hello from thread no. %d!\n", *(int *) threadnum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    /*
    It is a good idea to use an array instead of a single variable
    because the main thread may change the value of the variable passed
    s argument in the middle of the previous thread's execution
    */
    int threads_arg[NUM_THREADS];
    
    int t;

    for(t=0; t< NUM_THREADS; t++) {
        threads_arg[t] = t;
        printf("Creating thread %d\n", t);
        pthread_create(&threads[t], NULL, PrintHello, (void *)&threads_arg[t]);
    }

    pthread_exit(0);
}