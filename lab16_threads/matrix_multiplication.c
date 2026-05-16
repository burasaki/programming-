#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

typedef struct arrs{
    int **arr1;
    int **arr2;
    int **arr_result;
    int arr_size;
} arrs_t;


typedef struct thread_data{
    arrs_t *arrs;
    int line_start;
    int line_end;
} thread_data_t;



void print_arr( int size, int **arr){
   for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void *rourine(void *argP) {
    thread_data_t *thread_data = (thread_data_t*)argP;

    for(int i = thread_data->line_start; i < thread_data->line_end; i++){
        for(int j = 0; j < thread_data->arrs->arr_size; j++){
            for( int k = 0; k < thread_data->arrs->arr_size; k++){
                thread_data->arrs->arr_result[i][j] += thread_data->arrs->arr1[i][k] * thread_data->arrs->arr2[k][j];
            }
        }

    }
    free(thread_data);
    
    return NULL;
}

int main(int argc, char *argv[]){
    int matrix_size = argc > 1 ? atoi(argv[1]) : 5;
    int nof_threads = argc > 2 ? atoi(argv[2]) : 2;

    // FILE *file = fopen("data.txt", "w");
    // if (file == NULL) {
    //     printf("In %s:%d Error opening file\n", __FILE__, __LINE__);
    //     exit(1);
    // }
    // for (matrix_size = 100; matrix_size <= 1000; matrix_size += 100){
    //     for( nof_threads = 1; nof_threads <= 128; nof_threads *= 2){

    struct timespec start, end;


    arrs_t *arrs = malloc(sizeof(arrs_t));

    arrs->arr1 = malloc(matrix_size * sizeof(int *));
    arrs->arr2 = malloc(matrix_size * sizeof(int *));
    arrs->arr_result = malloc(matrix_size * sizeof(int *));
    arrs->arr_size = matrix_size;

    for (int i = 0; i < matrix_size; i++){
        arrs->arr1[i] = malloc(matrix_size * sizeof(int));
        arrs->arr2[i] = malloc(matrix_size * sizeof(int));
        arrs->arr_result[i] = malloc(matrix_size * sizeof(int));

        for (int j = 0; j < matrix_size; j++){
            arrs->arr1[i][j] = 1;
            arrs->arr2[i][j] = 1;
            arrs->arr_result[i][j] = 0;
        }
    }

    
    clock_gettime(CLOCK_MONOTONIC, &start);

    pthread_t tids[nof_threads];


    for (int i = 0; i < nof_threads; i++) {
        thread_data_t *thread_data = malloc(sizeof(thread_data_t));
        thread_data->arrs = arrs;
        thread_data->line_start = (matrix_size / nof_threads) * i;
        thread_data->line_end = (matrix_size / nof_threads) * (i + 1);
        pthread_create(&tids[i], NULL, rourine, thread_data);
    }

    
    for (int i = 0; i < nof_threads; i++) {
        pthread_join(tids[i], NULL);
    }
    
    
    for( int i = arrs->arr_size - (arrs->arr_size % nof_threads); i < arrs->arr_size; i++){
        for(int j = 0; j < arrs->arr_size; j++){
            for( int k = 0; k < arrs->arr_size; k++){
                arrs->arr_result[i][j] += arrs->arr1[i][k] * arrs->arr2[k][j];
            }
        }
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (matrix_size < 6){
        printf("Массив A\n");
        print_arr(matrix_size, arrs->arr1);
        printf("\n");
        printf("Массив B\n");
        print_arr(matrix_size, arrs->arr2);
        printf("Массив C\n");
        print_arr(matrix_size, arrs->arr_result);
    }
    printf("Размер матрицы: %d;Количество потоков: %d;Время выполнения: %f\n", matrix_size, nof_threads, time_taken);
    // fprintf(file,"Размер матрицы: %d;Количество потоков: %d;Время выполнения: %f\n", matrix_size, nof_threads, time_taken);
//}}
}