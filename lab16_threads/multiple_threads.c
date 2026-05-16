#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define NOF_THREADS 4

pthread_mutex_t mutex_main = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_thread = PTHREAD_MUTEX_INITIALIZER;

void end_thread(void *argP){
    int *number_thread = (int*) argP;
    printf("Поток %d завершил работу\n", *number_thread);
}


void *rourine(void *argP) {
    int *number = (int*)argP;

    pthread_cleanup_push(end_thread, number);


    pthread_mutex_lock(&mutex_thread);
    printf("Число из потока %d: %d\n", *number, rand()%10);
    pthread_mutex_unlock(&mutex_main);
    sleep(1);
    pthread_mutex_lock(&mutex_thread);
    printf("Число из потока %d: %d\n", *number, rand()%10);
    pthread_mutex_unlock(&mutex_main);

    pthread_cleanup_pop(1); 
    
    
    return NULL;
}

int main(void) {
    pthread_mutex_lock(&mutex_thread);

    pthread_t tids[NOF_THREADS];

    int number_thread[NOF_THREADS];

    for (int i = 0; i < NOF_THREADS; i++) {
        number_thread[i] = i;
        pthread_create(&tids[i], NULL, rourine, &number_thread[i]);
    }

    for(int i = 0; i < NOF_THREADS*2 + 1; i++){
        pthread_mutex_lock(&mutex_main);
        printf("Число из main: %d\n", rand()%10);
        fflush(stdout);
        sleep(1);
        pthread_mutex_unlock(&mutex_thread);
    }
    pthread_mutex_unlock(&mutex_thread);

    for (int i = 0; i < NOF_THREADS; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("main process завершил работу\n");
    return 0;
}