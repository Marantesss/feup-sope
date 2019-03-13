// PROGRAMA p02a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("Entering SIGINT handler ...\n");
    sleep(2);
    printf("Exiting SIGINT handler ...\n");
}

void sigterm_handler(int signo) {
    printf("Entering SIGTERM handler ...\n");
    sleep(2);
    printf("Exiting SIGTERM handler ...\n");
}

int main(void) {
    struct sigaction action_int;
    action_int.sa_handler = sigint_handler;

    sigemptyset(&action_int.sa_mask);
    action_int.sa_flags = 0;

    if (sigaction(SIGINT, &action_int, NULL) < 0) {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    struct sigaction action_term;
    action_term.sa_handler = sigterm_handler;

    sigemptyset(&action_term.sa_mask);
    action_term.sa_flags = 0;

    if (sigaction(SIGTERM, &action_term, NULL) < 0) {
        fprintf(stderr, "Unable to install SIGTERM handler\n");
        exit(1);
    }

    printf("Try me with CTRL-C ...\n");
    while (1)
        pause();
    exit(0);
}