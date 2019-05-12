// PROGRAMA p02.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 10


void * thrfunc(void * arg) {

    sleep(1);
    printf("Starting thread no. %d with ID %ld!\n", *(int *) arg, pthread_self());
    pthread_exit(arg); // same is writting return &arg
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threads_arg[NUM_THREADS];
    int threads_ret[NUM_THREADS];
    void * ret;

    int rc, t;

    for(t=0; t< NUM_THREADS; t++) {
        threads_arg[t] = t;
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, thrfunc, (void *)&threads_arg[t]);
        /*
        On success, pthread_create() returns 0; on error,
        it returns an error number, and the contents of *thread are undefined.
        */
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(1);
        } 
    }

    for(t=0; t< NUM_THREADS; t++) {
        pthread_join(threads[t], &ret);
        threads_ret[t] = *(int *)ret;
        printf("Thread %d return value: %d\n", t, threads_ret[t]);
    }

    return 0;
}
