// PROGRAMA p01.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10000

void * thrfunc_a(void * arg) {
    int i;
    fprintf(stderr, "Starting thread %d\n", *(int *) arg);
    for (i = 1; i <= NUMITER; i++)
        printf("%d", *(int *)arg);
        //write(STDERR, arg,1);
    return NULL;
}

void * thrfunc_b(void * arg) {
    int i;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);
    for (i = 1; i <= NUMITER; i++)
        printf("%s", (char *)arg);
        //write(STDERR, arg,1);
    return NULL;
}

int main() {
    pthread_t ta, tb;

    /*
    When passing arguments maybe it is a good idea to
    cast the referencing variable as a void pointer
    only if we are not passing the same variable as
    an argument to another thread

    int i = 42;
    pthread_create(&ta, NULL, thrfunc_a, (void *)&i);
    // (void *)&i -> void pointer
    // &i -> integer pointer
    */

    // works
    int i = 1;
    pthread_create(&ta, NULL, thrfunc_a, &i);

    // does not work
    char t = 2;
    pthread_create(&tb, NULL, thrfunc_b, &t);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    return 0;
}