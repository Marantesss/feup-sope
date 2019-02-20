#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// also works int main(int argc, char **argv, char **envp) {
int main(int argc , char* argv[], char* envp[]) {

    // a) & b)
    char user[30];
    for (int i = 0; envp[i] != NULL; i++) {
        // to print all environment variables
        // printf("%s\n", envp[i]);
        if (!strncmp("USER", envp[i], 4)) {
            strcpy(user, envp[i]);
        }
    }
    /*
    Also works :)
    for (char **env = envp; *env != NULL; env++) {
        printf("%s\n", *env);  
    }
    */

    char username[25];
    strcpy(username, user + 5);
    printf("Hello %s\n", username);

    // c)
    printf("PATH: %s\n", getenv("PATH"));
    printf("HOME: %s\n", getenv("HOME"));
    printf("USER: %s\n", getenv("USER"));
    printf("ROOT: %s\n", getenv("ROOT"));
    printf("Hello again %s, this time using getenv :)\n", getenv("USER"));

    // d)
    // we need to export USER_NAME="INSERT NAME HERE" -> You can use spaces as ling as you write it between ""
    printf("USER_NAME: %s\n", getenv("USER_NAME"));

    printf("Hello there General %s\n", getenv("USER_NAME"));
    
    return 0;
}
