#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int seconds = 0;

void alarm_handler(int sig) {
    seconds++;
    printf("Hello World!\n");
    alarm(1); // trigger again in 1 second
}

void int_handler(int sig) {
    printf("\nProgram ran for %d seconds.\n", seconds);
    exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, int_handler); // handle Ctrl + C

    alarm(1); // start the timer

    while (1) {
        pause(); // wait for signal
    }

    return 0;
}
