//  This program creates and joins two threads and prints 100 iterations.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

void *newThread(int n)
{
    int i;
    for (i=0; i<100; i++)
    {
        printf("Thread 1 Process %d \n", i);
        usleep(n);
    }
    return NULL;
}

void *newThread2(int n)
{
    int i;
    for (i=0; i<100; i++)
    {
        printf("\t \t \t Thread 2 Process %d \n", i);
        usleep(n);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    //  Initialize variables
    pthread_t tid, tid2;
    int i;

    //  Sleep timer
    int n = 100;

    //  Print before threading
    printf("\nBefore threading.\n");

    //  Create threads
    pthread_create(&tid, NULL, newThread, n);
    pthread_create(&tid2, NULL, newThread2, n);

    //  Join threads
    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
