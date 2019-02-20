#include <stdio.h>
#include <string.h>

// also works int main(int argc, char **argv, char **envp) {
int main(int argc , char* argv[], char* envp[]) {

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

    return 0;
}
