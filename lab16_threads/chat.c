#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h> 


#define N 10
#define CLIENTS 2
#define SERVERS 2
#define MSGSIZE 128

typedef struct elem {
    char msg[MSGSIZE + 1];
} elem_t;





typedef struct fifo {

    pthread_mutex_t lock;
    pthread_cond_t cond;
    int length;
    int start;

    int fifo_max_queue_size;
    elem_t *elems;

    int is_running;

} fifo_t;

typedef struct data {
    fifo_t *fifo;
    int id;
} data_t;

fifo_t *init_fifo(int size_fifo){
    fifo_t *fifo = malloc(sizeof(fifo_t));
    if (fifo == NULL){
        return NULL;
    }

    if (pthread_mutex_init(&fifo->lock, NULL) != 0){
        free(fifo);
        return NULL;
    }

    if (pthread_cond_init(&fifo->cond, NULL) != 0){
        free(fifo);
        return NULL;
    }

    fifo->elems = malloc(size_fifo * sizeof(elem_t));
    if (fifo->elems == NULL){
        free(fifo);
        return NULL;
    }

    fifo->fifo_max_queue_size = size_fifo;

    fifo->length = 0;
    fifo->start = 0;

    return fifo;
}

void fifo_deinit(fifo_t *fifo) {
    if (fifo){
        free(fifo->elems);
    }
    free(fifo);
}

int msgSend(fifo_t *fifo, char *msg){

    if (pthread_mutex_lock(&fifo->lock) != 0) abort();

    while (fifo->length >= fifo->fifo_max_queue_size){
        if (pthread_cond_wait(&fifo->cond, &fifo->lock) != 0) abort();
    }


    char buff[MSGSIZE + 1];

    int idx = (fifo->start + fifo->length) % fifo->fifo_max_queue_size;

    strncpy(fifo->elems[idx].msg, msg, MSGSIZE);
    fifo->elems[idx].msg[MSGSIZE] = '\0';
    fifo->length++;

    pthread_cond_signal(&fifo->cond);
    pthread_mutex_unlock(&fifo->lock);

    return strlen(fifo->elems[idx].msg);
}

int msgRecv(fifo_t *fifo, char *buf, size_t bufsize){

    if (pthread_mutex_lock(&fifo->lock) != 0) abort();

    while (fifo->length == 0){
        if (pthread_cond_wait(&fifo->cond, &fifo->lock) != 0) abort();
    }

    strncpy(buf, fifo->elems[fifo->start].msg, bufsize - 1);

    buf[bufsize - 1] = '\0';

    fifo->start = (fifo->start + 1) % fifo->fifo_max_queue_size;
    fifo->length--;

    pthread_cond_signal(&fifo->cond);
    pthread_mutex_unlock(&fifo->lock);

    return strlen(buf);
}

void print_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    struct tm* tm_local = localtime(&tv.tv_sec);
    char buffer[26];
    
    strftime(buffer, 26, "%H:%M:%S", tm_local);
    
    printf("[%s.%03d] ", buffer, (int)(tv.tv_usec / 1000));
}


void *server(void *argP){
    data_t *data = (data_t*)argP;
    fifo_t *fifo = data->fifo;
    int server_id = data->id;
    char buf[1000];

    while (fifo->is_running){
        int rec_len = msgRecv(fifo, buf, sizeof(buf));
        print_time();
        printf("Сервер %d принял сообщение %s, длинной %d\n", server_id, buf, rec_len);
        usleep(rand() % 4000000 + 1000000);
    }


    return NULL;
}

void *client(void *argP){
    data_t *data = (data_t*)argP;
    fifo_t *fifo = data->fifo;
    int client_id = data->id;
    char msg[1000];

    while (data->fifo->is_running){
        sprintf(msg, "Message from client %d: %d", client_id, rand()%1000);
        int send_len = msgSend(fifo, msg);
        print_time();
        printf("Клиент %d отправил сообщение %s, длинной %d\n", client_id, msg, send_len);
        usleep(rand() % 1000000 + 1000000);
    }


    return NULL;
}

int main(){
    srand(time(NULL));

    fifo_t *fifo = init_fifo(N);
    fifo->is_running = 1;

    pthread_t servers_thread[SERVERS];
    pthread_t client_thread[CLIENTS];

    data_t servers_data[SERVERS];
    data_t client_data[CLIENTS];

    for (int i = 0; i < SERVERS; i++){
        servers_data[i].fifo = fifo;
        servers_data[i].id = i;
        pthread_create(&servers_thread[i], NULL, server, &servers_data[i]);
    }

    for (int i = 0; i < CLIENTS; i++){
        client_data[i].fifo = fifo;
        client_data[i].id = i;
        pthread_create(&client_thread[i], NULL, client, &client_data[i]);
    }

    sleep(10);

    fifo->is_running = 0;

    for (int i = 0; i < SERVERS; i++){
        pthread_join(servers_thread[i], NULL);
    }

    for (int i = 0; i < CLIENTS; i++){
        pthread_join(client_thread[i], NULL);
    }


    fifo_deinit(fifo);
}