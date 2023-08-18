#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *function()
{
    long int x = pthread_self();
    printf("Function Thread.\n");
    pthread_exit((void *)x);
}
int main()
{
    pthread_t t1, t2, t3;
    if (pthread_create(&t1, NULL, function, NULL) == 0)
    {
        printf("Thread# 1\n");
    }
    else
    {
        printf("Error!");
    }
    if (pthread_create(&t2, NULL, function, NULL) == 0)
    {
        printf("Thread# 2\n");
    }
    else
    {
        printf("Error!");
    }
    if (pthread_create(&t3, NULL, function, NULL) == 0)
    {
        printf("Thread# 3\n");
    }
    else
    {
        printf("Error!");
    }
    long int *y;
    pthread_join(t1, (void *)&y);
    printf("Terminating Thread#1 with Return value [%ld]\n", *y);
    pthread_join(t2, (void *)&y);
    printf("Terminating Thread#2 with Return value [%ld]\n", *y);
    pthread_join(t3, (void *)&y);
    printf("Terminating Thread#3 with Return value [%ld]\n", *y);

    return 0;
}