#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid1, pid2;

	pid1 = fork();
	switch (pid1) {
		case 0: //Processo filho escreve hello
			printf("Hello ");
			break;
		default: // filho do pai
			pid2 = fork();
			switch (pid2) {
				case 0: // filho do filho
                    wait(NULL); // espera pelo filho
					printf("my");
					break;
				default: // pai
					wait(NULL); // espera pelo filho
					printf(" friends!\n");
					break;
			}
	}
	return 0;
} 
