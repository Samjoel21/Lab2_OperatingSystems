#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int signal_received = 0;

void handler(int signum)
{
    printf("Hello World!\n");
    signal_received = 1;
}

int main(void)
{
    signal(SIGALRM, handler);
    alarm(5);

    while (signal_received == 0);

    printf("Turing was right!\n");

    return 0;
}