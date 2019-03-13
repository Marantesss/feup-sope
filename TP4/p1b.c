#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo) {
    printf("\nIn SIGINT handler ...\n");
    printf("%d\n", signo); // output is 2... because SIGINT => 2
}

int main (int argc, char** argv) {

    if (signal(SIGINT, SIG_IGN) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }

    printf("Sleeping for 30 seconds ...\n");

    sleep(10);

    printf("Waking up ...\n");

    exit(0);
}
