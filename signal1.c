#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int flag = 0;

void handler(int sig) {
    printf("Hello World!\n");
    flag = 1;
}

int main() {
    signal(SIGALRM, handler);
    alarm(5); // trigger in 5 seconds

    while (!flag) {
        pause(); // wait for signal
    }

    printf("Turing was right!\n");
    return 0;
}

