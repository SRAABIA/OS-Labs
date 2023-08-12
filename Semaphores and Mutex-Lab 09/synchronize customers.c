/*Task 2:
You need to synchronize customers at boarding lounge of an airport using semaphore. where there are 10 customers, each needs to weight his luggage, get it checked and get a boarding pass. During each task passengers are too bored that they sleep, weighting luggage takes 4 seconds sleep, security check for luggage needs 7 seconds sleep and getting boarding pass needs 3 seconds sleep.*/
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#define customers 10

sem_t weighing_luggage;
sem_t check_luggage;
sem_t counter;
sem_t boarding_pass;

void counter_1(void *);
void weighing_counter(int);
void checking_counter(int);
void boarding_pass_counter(int);

int main(int argc, char *argv[])
{
    printf("    ** Welcome To Airlines. **\n");
    printf("  - Wait till you go through the check-in procedure. -\n\n");
    pthread_t c[customers];
    int id[customers];
    sem_init(&weighing_luggage, 0, 1);
    sem_init(&check_luggage, 0, 1);
    sem_init(&boarding_pass, 0, 1);
    sem_init(&counter, 0, 1);

    for (int i = 0; i < customers; i++)
    {
        id[i] = i + 1;
        pthread_create(&c[i], NULL, (void *)&counter_1, (void *)&id[i]);
    }
    for (int i = 0; i < customers; i++)
    {
        pthread_join(c[i], NULL);
    }
    printf("    - All Customers Have Been Boarded. Enjoy Your Flight. -\n");

    sem_destroy(&weighing_luggage);
    sem_destroy(&check_luggage);
    sem_destroy(&boarding_pass);
    return 0;
}
void counter_1(void *arg)
{
    int Passenger_ID = *(int *)arg;

    printf("Customer %d is in the queue.\n", Passenger_ID);

    sem_wait(&weighing_luggage);
    weighing_counter(Passenger_ID);
    sem_post(&weighing_luggage);

    sem_wait(&check_luggage);
    checking_counter(Passenger_ID);
    sem_post(&check_luggage);

    sem_wait(&boarding_pass);
    boarding_pass_counter(Passenger_ID);
    sem_post(&boarding_pass);

    printf("\nCustomer %d PASSED all counters. You may proceed board an airplane.\n\n", Passenger_ID);

    pthread_exit(NULL);
}
void weighing_counter(int argv)
{
    int Passenger_ID = argv;
    printf("Customer %d is WEIGHING luggage.\n", Passenger_ID);
    sleep(4);
    printf("\nCustomer %d is DONE WEIGHING luggage.\n", Passenger_ID);
    return;
}

void checking_counter(int argv)
{
    int Passenger_ID = argv;
    printf("Customer %d is getting luggage CHECKED.\n", Passenger_ID);
    sleep(7);
    printf("\nCustomer %d is DONE getting luggage CHECKED.\n", Passenger_ID);
    return;
}

void boarding_pass_counter(int argv)
{
    int Passenger_ID = argv;
    printf("Customer %d is getting BOARDING-PASS.\n", Passenger_ID);
    sleep(3);
    printf("\nCustomer %d is DONE getting BOARDING-PASS.\n", Passenger_ID);
    return;
}
