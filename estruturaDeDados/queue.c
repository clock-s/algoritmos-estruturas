#include <stdio.h>
#include <stdlib.h>

struct Queue{
    size_t head;
    size_t tail;
    size_t size;
    int *array;
};


typedef struct Queue Queue;


void init_queue(Queue *queue, size_t size){
    queue->head = 0;
    queue->tail = 0;
    queue->size = size + 1;
    queue->array = (int*)malloc((queue->size) * sizeof(int));
}

void delete_queue(Queue *queue){
    free(queue->array);
    queue->array = NULL;
}

int is_empty(Queue *queue){
    return queue->head == queue->tail;
}

void dequeue(Queue *queue){
    if(is_empty(queue)){
        printf("The queue is empty!");
        return;
    }

    queue->head = (queue->head + 1)%(queue->size);
}

int front(Queue *queue){
    return(queue->array[queue->head]);
}

void enqueue(Queue *queue, int x){
    if((queue->tail + 1)%(queue->size) == queue->head){
        printf("The queue is full already!\n");
        return;
    }
    
    queue->array[queue->tail] = x;

    queue->tail = (queue->tail + 1) % (queue->size);
}


int main(int argc, char const *argv[]){
    Queue queue;

    init_queue(&queue, 5);

    for(int i = 1 ; i <= 5 ; i++){
        enqueue(&queue, i);
    }


    while (!is_empty(&queue)){
        printf("%d ", front(&queue));
        dequeue(&queue);
    }

    printf("\n");
    dequeue(&queue);

    for(int i = 1 ; i <= 5 ; i++){
        enqueue(&queue, i);
    }


    printf("\n%d \n", front(&queue));
    


    delete_queue(&queue);
    return 0;
}
