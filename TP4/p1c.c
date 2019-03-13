#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void sigint_handler(int signo) {
    printf("\nIn SIGINT handler ...\n");
    printf("%d\n", signo); // output is 2... because SIGINT => 2
}

int main (int argc, char** argv) {

    struct sigaction sa; // Declaracao da estrutura sigaction
    sa.sa_handler = sigint_handler; // or = SIG_IGN

    if (sigaction(SIGINT, &sa, NULL) < 0) {
        fprintf(stderr,"Unable to install SIGINT handler... Now using sigaction :)\n");
        exit(1);
    }

    printf("Sleeping for 30 seconds ...\n");

    sleep(30);
    printf("Waking up ...\n");

    exit(0);
}
