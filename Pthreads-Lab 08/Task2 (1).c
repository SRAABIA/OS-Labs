#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Table_5()
{
    printf("\n");
    int i = 1;
    while (1)
    {
        printf(" %d * %d = %d\n", 5, i, 5 * i);
        i++;
        if (i > 1000)
        {
            pthread_exit(NULL);
        }    
    }
}
void *Table_6()
{
    printf("\n");
    int i = 1;
    while (1)
    {
        printf(" %d * %d = %d\n", 6, i, 6 * i);
        i++;
        if (i > 1000)
        {
            pthread_exit(NULL);
        }
    }
}
void *Table_7()
{
    printf("\n");
    int i = 1;
    while (1)
    {
        printf(" %d * %d = %d\n", 7, i, 7 * i);
        i++;
        if (i > 1000)
        {
            pthread_exit(NULL);
        }
    }
}
void *Table_8()
{
    printf("\n");
    int i = 1;
    while (1)
    {
        printf(" %d * %d = %d\n", 8, i, 8 * i);
        i++;
        if (i > 1000)
        {
            pthread_exit(NULL);
        }
    }
}
int main()
{
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, Table_5, NULL);
    pthread_create(&t2, NULL, Table_6, NULL);
    pthread_create(&t3, NULL, Table_7, NULL);
    pthread_create(&t4, NULL, Table_8, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}