#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PASSWD_LEN 20

int main(void) {
    struct termios term, oldterm;
    char pass[MAX_PASSWD_LEN+1], ch, echo = '*';
    
    write(STDOUT_FILENO, "\nPassword? ", 11);

    // get termios struct STDIN_FILENO saving the oldterm
    tcgetattr(STDIN_FILENO, &oldterm);
    term = oldterm;
    /*
    ECHO   Echo input characters.

    ECHOE  If  ICANON is also set, the ERASE character erases the preceding
            input character, and WERASE erases the preceding word.

    ECHOK  If ICANON is also set, the KILL  character  erases  the  current
            line.

    ECHONL If ICANON is also set, echo the NL character even if ECHO is not
            set.
    */
    term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    // set termios struct STDIN_FILENO with the changes above
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    int i=0;
    // enquanto o i nao passa do MAX_LEN, le chars e o char nao e \n
    while (i < MAX_PASSWD_LEN && read(STDIN_FILENO, &ch, 1) && ch != '\n') {
        pass[i] = ch;
        write(STDOUT_FILENO, &echo, 1);
        i++;
    }
    pass[i] = 0;

    // set attribute back to normal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
    write(STDOUT_FILENO, "\n\nPassword: ", 12);
    write(STDOUT_FILENO, pass, strlen(pass));
    write(STDOUT_FILENO, "\n", 1);
    
    return 0;
} 