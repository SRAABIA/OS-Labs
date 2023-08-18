#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int arr[10] ={1,2,3,4,5,6,7,8,9,10};
void* sum(void *x){
    int k = *(int*)x;
    int total =0;
    for(int j=0;j<5;j++){
        total+=arr[k+j];
    }
    *(int*)x = total;
    return x;
}
int main(){
    pthread_t th[2];
    int Tsum = 0;
    for(int i=0;i<2;i++){
        int *a = malloc(sizeof(int));
        *a = i*5;
        pthread_create(&th[i],NULL,&sum,a);
    }
    for(int i=0;i<2;i++){
        int* ret;
        pthread_join(th[i],(void**) &ret);
        Tsum += *ret;
        free(ret);
    }
    printf("\n\n\t[Main] Array Sum from %d to %d = %d\n",arr[0],arr[9],Tsum);
    return 0;
}