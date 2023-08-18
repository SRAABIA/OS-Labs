#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* func(void* i){
    printf("Hello!! Thread %ld created in iteration %d\n",pthread_self(),i);
}
int main(){
    int N;
    printf("Enter Number Of Threads: ");
    scanf("%d",&N);
    pthread_t th[N];
    for(int i=0;i<N;i++){
        pthread_create (&th[i],NULL,func,&i);
        printf("Main Thread#1 : Created thread %ld in iteration %d\n",th[i],i);
    }
    for(int i=0;i<N;i++){     
        pthread_join(th[i],NULL);
    }
    return 0;
}