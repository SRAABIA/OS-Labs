/*Task 3:
Imagine you are designing a ticketing system for a popular concert. The system will have multiple ticket sellers, each running on a separate thread. To prevent overselling, you need to ensure that no two sellers can sell the same ticket at the same time. How would you use semaphores in C to ensure that only one ticket seller can access the ticket database at a time, while the others wait until the resource becomes available? (Create a code based implementation)*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int Tickets = 14;
sem_t semaphore;
void* Ticket_Seller(void *argv){
    int seller_ID = *(int*)argv;
    while(1){
        sem_wait(&semaphore);
        if(Tickets == 0){
            sem_post(&semaphore);
            break;
        }

        printf("   Seller# %d is selling Ticket# %d\n", seller_ID, Tickets);
        Tickets--;
        sem_post(&semaphore);
        sleep(1);
    }
}
int main(int argc, char* argv[]){
    printf("\n    **WELCOME TO POPULAR CONCERT.**\n\n");
    pthread_t seller1, seller2;
    int id1 = 1;
    int id2 = 2;
    sem_init(&semaphore,0,1);
    pthread_create(&seller1,NULL,(void*)&Ticket_Seller,(void*)&id1);
    pthread_create(&seller2,NULL,(void*)&Ticket_Seller,(void*)&id2);
    pthread_join(seller1,NULL);
    pthread_join(seller2,NULL);

    printf("\n  --ALL TICKETS HAVE BEEN SOLD OUT.--\n");
    sem_destroy(&semaphore);
    return 0;
}