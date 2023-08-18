#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define No_of_Participants 10

void *registration(void *arg) {
    int id = *((int*) arg);
    printf("Participant %d is getting registered.\n\n", id);
    // Perform registration process
    pthread_exit(NULL);
}

void *announcement(void *arg) {
    int id = *((int*) arg);
    printf("Participant %d is listening to announcements.\n\n", id);
    // Listen to announcements
    pthread_exit(NULL);
}

void *sponsor(void *arg) {
    int id = *((int*) arg);
    printf("Participant %d is meeting with sponsors.\n\n", id);
    // Meet with sponsors
    pthread_exit(NULL);
}

void *queries(void *arg) {
    int id = *((int*) arg);
    printf("Participant %d is getting queries resolved.\n\n", id);
    // Resolve queries
    pthread_exit(NULL);
}

int main() {
    int i;
    printf("\n\t**Volunteers at PROCOM Event**\n\n");
    pthread_t threads[No_of_Participants];
    int ids[No_of_Participants];
    for (i = 0; i < No_of_Participants; i++) {
        ids[i] = i+1;
        if (i % 4 == 0) {
            pthread_create(&threads[i], NULL, registration, &ids[i]);
        } else if (i % 4 == 1) {
            pthread_create(&threads[i], NULL, announcement, &ids[i]);
        } else if (i % 4 == 2) {
            pthread_create(&threads[i], NULL, sponsor, &ids[i]);
        } else {
            pthread_create(&threads[i], NULL, queries, &ids[i]);
        }
    }
    for (i = 0; i < No_of_Participants; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
