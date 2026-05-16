#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define N 10


void *rourine(void *argP) {
    int *time_sleep = (int*)argP;

    
    sleep(*time_sleep);
    printf(" %d", *time_sleep);
    fflush(stdout); 

    return NULL;
}

int main(void) {
    srand(time(NULL));
    int arr[N];

    printf("[");
    for(int i = 0; i < N; i++){
        arr[i] = rand()%10+1;
        printf(" %d", arr[i]);
    }
    printf(" ]\n");

    pthread_t tids[N];

    int number_thread[N];
    printf("[");
    for (int i = 0; i < N; i++) {
        number_thread[i] = arr[i];
        pthread_create(&tids[i], NULL, rourine, &arr[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(tids[i], NULL);
    }
    printf(" ]\n");
    return 0;
}