#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarm_received = 0;
int interrupted = 0;
int alarm_count = 0;

void alarm_handler(int signum)
{
    printf("Hello World!\n");
    alarm_received = 1;
    alarm_count++;
}

void interrupt_handler(int signum)
{
    interrupted = 1;
}

int main(void)
{
    time_t start_time;
    time_t end_time;

    start_time = time(NULL);

    signal(SIGALRM, alarm_handler);
    signal(SIGINT, interrupt_handler);

    alarm(1);

    while (!interrupted)
    {
        while (!alarm_received && !interrupted);

        if (interrupted)
            break;

        printf("Turing was right!\n");

        alarm_received = 0;

        alarm(1);
    }

    end_time = time(NULL);

    printf("Total alarms: %d\n", alarm_count);
    printf("Total execution time: %ld seconds\n",
           end_time - start_time);

    return 0;
}