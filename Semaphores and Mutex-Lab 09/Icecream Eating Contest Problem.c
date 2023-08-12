/*Task1:
a. Create an icecream eating contest problem protected by a semaphore lock. Use global variables icecreamremaining. Create 3 threads for 3 persons to eat icecreams until all are finished. But only one person will be given icecreamcone at a time by the salesman. So restrict access to icecreams so that only one thread can decrement it by using a semaphor. So use sem_wait and Sem_post in thread. b. get each person to count money from his wallet for the icecream payment which can take one to 2 seconds during which other person can acquire the salesman to sell him icecream. Redo the coding to accommodate this condition in your threads as well.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include<time.h>
#include <semaphore.h>
#include <sys/types.h>
#define persons 3
int icecreams_remaining = 10;
sem_t semaphore;
void ICECREAM_CONTEST(void *);
int main(int argc, char *argv[])
{
    pthread_t p[persons];
    int i[persons] = {1, 2, 3};
    sem_init(&semaphore, 0, 1);
    for (int j = 0; j < persons; j++)
    {
        pthread_create(&p[j], 0, (void *)&ICECREAM_CONTEST, (void *)&i[j]);
    }

   for (int j = 0; j < persons; j++)
    {
        pthread_join(p[j], NULL);
    }

    printf("    All Ice-Creams Have Been Eaten.\n");
    sem_destroy(&semaphore);
    return 0;
}
void ICECREAM_CONTEST(void *ptr)
{
    int person_id = *((int *)ptr);
    srand(time(NULL));
    while(icecreams_remaining>0){
        sem_wait(&semaphore);
        if(icecreams_remaining == 0){
            sem_post(&semaphore);
            break;
        }
        printf("    Person# %d is eating Ice-cream# %d\n", person_id, icecreams_remaining);
        icecreams_remaining--;
        sem_post(&semaphore);
        printf("    Person# %d waits to find money in wallet.\n\n",person_id);
        sleep(rand()%2);
    }
    pthread_exit(0);
}