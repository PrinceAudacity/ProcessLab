#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;

void handler(int sig) {
    printf("Hello World!\n");
    flag = 1;  // signal main to print next line
}

int main() {
    signal(SIGALRM, handler);

    while (1) {
        alarm(5);        // trigger SIGALRM every 5 seconds
        pause();         // wait for it
        printf("Turing was right!\n");
        flag = 0;        // reset flag (optional here)
    }

    return 0;
}

