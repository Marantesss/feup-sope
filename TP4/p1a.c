// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void sigint_handler(int signo) {
    printf("\nIn SIGINT handler ...\n");
    //printf("%d\n", signo); // output is 2... because SIGINT => 2
}

void sigusr1_handler(int signo) {
    printf("\nIn SIGUSR1 handler ...\n");
    //printf("%d\n", signo); // output is 10... because SIGUSR1 => 10
}

int main (int argc, char** argv) {
    if (signal(SIGINT, sigint_handler) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }

    if (signal(SIGUSR1, sigusr1_handler) < 0) {
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");
        exit(1);
    }

    printf("Sleeping for 30 seconds ...\n");
    // Comment this...
    raise(SIGUSR1);

    sleep(30);
    printf("Waking up ...\n");
    exit(0);
}
