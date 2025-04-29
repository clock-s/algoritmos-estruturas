#include <stdio.h>
#include <stdlib.h>


/*

Escreva uma implementação de um deque, que é uma estrutura de dados com duas extremidades, que
permite inserir e remover elementos em ambas as extremidades. Sua implementação deve ter as operações
Insert e Delete executando em tempo O(1). Sua implementação deve ser feita usando um vetor de no máximo
50 inteiros.

*/


typedef struct {
    int size;
    int empty;
    int head;
    int tail;
    int *array;
}Deque;


void init_deque(Deque *deque, int size){
    if(size > 50) return;

    deque->size = size;
    deque->head = 0;
    deque->tail = 0;
    deque->empty = 1;

    deque->array = (int*)malloc(sizeof(int) * deque->size);

}

void delete_deque(Deque *deque){
    free(deque->array);
}

void first_push(Deque *deque, int x){
    deque->array[deque->head] = x;
}

void push_front(Deque *deque, int x){
    if((deque->head + 1)%deque->size == deque->tail){
        printf("Deque full!\n");
        return;
    }

    if(deque->empty){
        first_push(deque, x);
        deque->empty = 0;
        return;
    }

    deque->head = (deque->head + 1) % deque->size;
    deque->array[deque->head] = x;

}

void push_back(Deque *deque, int x){
    if((deque->tail == 0 && deque->head == deque->size - 1) || (deque->tail - 1) == deque->head){
        printf("Deque full!\n");
        return;
    }

    if(deque->empty){
        first_push(deque, x);
        deque->empty = 0;
        return;
    }

    if(deque->tail == 0) deque->tail = deque->size - 1;
    else deque->tail -= 1;
    deque->array[deque->tail] = x;

}

int front(Deque deque){
    if(deque.empty){
        printf("The deque is empty!\n");
        return NULL;
    }else{
        return deque.array[deque.head];
    }
}

int back(Deque deque){
    if(deque.empty){
        printf("The deque is empty!\n");
        return NULL;
    }else{
        return deque.array[deque.tail];
    }
}

void delete_front(Deque *deque){
    if(deque->empty){
        printf("The deque is already empty!\n");
        return;
    }


    if(deque->head == deque->tail){
        deque->empty = 1;
        return;
    }

    if(deque->head == 0) deque->head = deque->size - 1;
    else deque->head -= 1;

}

void delete_back(Deque *deque){
    if(deque->empty){
        printf("The deque is already empty!\n");
        return;
    }

    if(deque->head == deque->tail){
        deque->empty = 1;
        return;
    }

    deque->tail = (deque->tail + 1)%deque->size;

}


int main(int argc, char const *argv[]){
    Deque deque;

    init_deque(&deque, 5);

    delete_back(&deque);
    delete_front(&deque);

    push_front(&deque, 1);
    push_front(&deque, 2);
    push_back(&deque, 3);
    push_back(&deque, 4);
    push_back(&deque, 5);
    
    delete_front(&deque);
    delete_back(&deque);
    delete_front(&deque);
    delete_back(&deque);
    delete_front(&deque);
    delete_back(&deque);

    //int x = front(deque);


    printf("%d %d\n", back(deque), front(deque));


    delete_deque(&deque);
    return 0;
}

