// PROGRAMA p3.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int v = 1;

void sigint_handler(int signo) {
    printf("\nIn SIGINT handler ...\n");
}

void sigusr_handler(int signo) {
    if (signo == SIGUSR1) {
        printf("\nIn SIGUSR1 handler ...\n");
        v++;
    }
    else if (signo == SIGUSR2) {
        printf("\nIn SIGUSR2 handler ...\n");
        v--;
    }
}


int main(int argc, char** argv) {

    // sets the output buffer size to null, so it can print without a newline :) - MMC <3
    //setbuf(stdout, NULL);
    
    //... Installing SIGINT handler
    struct sigaction action_int;
    action_int.sa_handler = &sigint_handler;

    sigemptyset(&action_int.sa_mask);
    action_int.sa_flags = 0;

    if (sigaction(SIGINT, &action_int, NULL) < 0) {
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }
    
    //... Installing SIGUSR1 and SIGUSR2 handler
    struct sigaction action_usr;
    action_usr.sa_handler = &sigusr_handler;

    sigemptyset(&action_usr.sa_mask);
    action_usr.sa_flags = 0;

    if (sigaction(SIGUSR1, &action_usr, NULL) < 0 || sigaction(SIGUSR2, &action_usr, NULL) < 0) {
        fprintf(stderr, "Unable to install SIGUSR handler\n");
        exit(1);
    }
    
    while(1) {
        printf("%d\n", v);
        sleep(1);
    }

    exit(0);
}