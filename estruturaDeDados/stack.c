#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct Stack{
    int top;
    size_t size;
    int *array;
};

typedef struct Stack Stack;

void init_stack(Stack *stack, size_t size){
    if (size <= 0){
        printf("Invalid size!\n");
        return;
    }

    stack->top = -1;
    stack->size = size;
    stack->array = (int*)malloc(stack->size * sizeof(int));
}

void delete_stack(Stack *stack){
    free(stack->array);
    stack->array = NULL;
}

int is_empty(Stack *stack){
    return stack->top == -1;
}

void push(Stack *stack, int x){
    if(stack->top == stack->size){
        printf("The stack is full!\n");
        return;
    }

    stack->top = stack->top + 1;
    stack->array[stack->top] = x; 
}

void pop(Stack *stack){
    if(is_empty(stack)){
        printf("The stack is already empty!\n");
        return;
    }

    --stack->top;
}

int top(Stack *stack){
    assert(stack->top != -1);
    return stack->array[stack->top];
}



void hack_see_all_value(Stack *stack){
    for(size_t i = 0 ; i <= stack->top; i++){
        printf("%d ", stack->array[i]);
    }

    printf("\n");
}


int main(int argc, char const *argv[]){
    Stack stack;
    init_stack(&stack, 5);
    pop(&stack);

    for(int i = 1 ;i  <= 5 ; i++){
        printf("%d\n", i);
        push(&stack, i);
    }

    hack_see_all_value(&stack);

    
    while(!is_empty(&stack)){
        pop(&stack);
        printf("Pop ");
    }
    
    printf("\n");

    delete_stack(&stack);
    return 0;
}