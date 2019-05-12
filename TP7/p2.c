// PROGRAMA p02.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_ITER 50000

// variaveis partilhadas
int num_iter = NUM_ITER;
int buf[NUM_ITER], pos = 0, val = 0;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER; // mutex p/a sec.critica

void * thrfunc(void * arg) {
    int *count = (int *) malloc(sizeof(int)); // necessary
    *count = 0;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);

    /*
    We need a while(1) loop because we must lock the thread
    before we check if we want to end the loop.
    And with a for loop that is impossible
    */
    while(1) {
        pthread_mutex_lock(&mut);

        if (num_iter <= 0) {
            pthread_mutex_unlock(&mut);
            pthread_exit(count); // same is writting return &count
        }

        printf("%s", (char *)arg);
        *count += 1;

        num_iter--;

        buf[pos] = val;
        pos++;
        val++;

        pthread_mutex_unlock(&mut);
    }
    /*
    Does not work for the reason explained above
    for (; num_iter > 0; num_iter--) {
        pthread_mutex_lock(&mut);

        printf("%d", num_iter);
        printf("%s", (char *)arg);
        *count += 1;

        buf[pos] = val;
        pos++;
        val++;

        pthread_mutex_unlock(&mut);
    }
    
    pthread_exit(count); // same is writting return &count
    */
}

void *verify() {
    int k;

    for (k=0; k < NUM_ITER; k++)
        if (buf[k] != k) // detecta valores errados
            printf("ERROR: buf[%d] = %d\n", k, buf[k]);

    return NULL;
}

int main() {
    pthread_t ta, tb, tidv;
    void * statusa;
    void * statusb;

    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");


    /* Will print some value between 0 and NUM_ITER */
    pthread_join(ta, &statusa);
    printf("\nTotal chars written by thread A: %d\n", *(int *)statusa);
    pthread_join(tb, &statusb);
    printf("Total chars written by thread B: %d\n", *(int *)statusb);

    /* Result is now equal to NUM_ITER :) */
    printf("Total ammount of written chars: %d\n", *(int *)statusa + *(int *)statusb);
    
    pthread_create(&tidv, NULL, verify, NULL);
    pthread_join(tidv, NULL); // espera thread 'verify'
    
    /* Avoid memory leaks */
    free(statusa);
    free(statusb);
    return 0;
}
