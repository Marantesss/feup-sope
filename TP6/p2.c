// PROGRAMA p02.c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global = 50000;

void * thrfunc(void * arg) {
    int count = 0;
    fprintf(stderr, "Starting thread %s\n", (char *) arg);

    for (; global > 0; global--) {
        printf("%s", (char *)arg);
        count++;
    }

    pthread_exit(&count);
}

int main() {
    pthread_t ta, tb;
    void * statusa;
    void * statusb;

    pthread_create(&ta, NULL, thrfunc, "1");
    pthread_create(&tb, NULL, thrfunc, "2");
    pthread_join(ta, &statusa);
    pthread_join(tb, &statusb);

    printf("\nTotal chars written by thread A: %d\n", *(int *)statusa);
    printf("Total chars written by thread B: %d\n", *(int *)statusb);

    printf("Total ammount of written chars: %d\n", *(int *)statusa + *(int *)statusb);
    
    return 0;
}
