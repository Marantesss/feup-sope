// PROGRAMA p07_server.c 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int readline(int fd, char *str);

int main(void) {
	int   fifo_req; 
	char  strLine1[100]; 
	char  strLine2[100];

    printf("Creating FIFO communication channels...");
	mkfifo("/tmp/fifo_req",0660); 
	fifo_req=open("/tmp/fifo_req",O_RDONLY);

	//Retorna os resultados
	int   fifo_ans; 
	//char  str_2[100]; 
	mkfifo("/tmp/fifo_ans",0660); 
	fifo_ans=open("/tmp/fifo_ans",O_WRONLY);

    printf("\nChannels created.");
    
	printf("\nWaiting query...");
	readline(fifo_req, strLine1);
	readline(fifo_req, strLine2);

	int number1, number2;
	number1 = atoi(strLine1);
	number2 = atoi(strLine2);

	char message[100];
	printf("\nMaking calculations...");
	int sum = number1 + number2;
	int diff = number1 - number2;
	int product = number1 * number2;
	float quocient = number1 /(double) number2;

	printf("\nSending data to FIFO...");
	
	// SUM
	sprintf(message,"Sum: %d",sum);
	int messagelen = strlen(message) + 1;
	write(fifo_ans, message, messagelen);

	// DIFF
	sprintf(message,"Diff: %d", diff);
	messagelen = strlen(message) + 1;
	write(fifo_ans, message, messagelen); 

	// PRODUCT
	sprintf(message,"Product: %d", product);
	messagelen = strlen(message) + 1;
	write(fifo_ans, message, messagelen); 

	// QUOCIENT
	sprintf(message,"Quocient: %f", quocient);
	messagelen = strlen(message) + 1;
	write(fifo_ans, message, messagelen); 
	
	printf("\nSent data to FIFO.\n");

	// Not necessary, just cause :)
	sleep(1);

	printf("Closing FIFO communication channels...");
	close(fifo_ans);
	close(fifo_req); 
    printf("\nChannels closed.\n");

	return 0; 
} 

int readline(int fd, char *str) {
	int n;

	do { 
		n = read(fd,str,1); 
	} while (n>0 && *str++ != '\0');

	return (n>0); 
}