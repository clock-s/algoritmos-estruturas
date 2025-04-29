#include <stdio.h>
#include <stdlib.h>


/*
Escreva um algoritmo não-recursivo de tempo O(n) que inverta uma lista simplesmente ligada de n
elementos, sem criar mais mem´oria.
*/

struct Link{
    struct Link* next;
    int x;
};


typedef struct Link Link;


void add(Link **head, int x){
    Link *link = (Link*)malloc(sizeof(Link));
    
    link->x = x;
    link->next = NULL;

    Link *jumper = *head;

    while(jumper->next != NULL){
        jumper = jumper->next;
    }

    jumper->next = link;

    jumper = NULL;

}

void print(Link *head){
    Link *jumper = head;



    while(jumper->next != NULL){
        jumper = jumper->next;
        printf("%d ", jumper->x);
    }
    printf("\n");
}



void invert(Link **head){
    Link *save_next;
    Link *swaper;

    //Lista com 1 elemento
    if((*head)->next->next == NULL) return;

    


    //Lista com 2 ou mais elementos
    swaper = (*head)->next->next; // Guarda o elemento que invertera a lista
    save_next = swaper->next; //Guarda o proximo elemento da proxima iteração
    
    swaper->next = (*head)->next; //Primeira iteração é diferente, inverte parte da lista e
    (*head)->next->next = NULL; //faz com que o primeiro elemento aponte para nulo
 
    while(swaper != NULL){
        (*head)->next = swaper; //Indo para o proximo elemento alvo (Com o ponteiro já trocado)
        swaper = save_next; //Indo para o elemento que fara a troca
        if(swaper == NULL) break; //Se o próximo elemento for nulo, acaba com a iteração
        save_next = save_next->next;

        swaper->next = (*head)->next;

    }
}

void delete_list(Link **head){
    
    if((*head)->next != NULL) delete_list(&(*head)->next);
    if((*head)->next != NULL) free((*head)->next);

}

int main(int argc, char const *argv[]){
    Link *head;
    head->next = NULL;
    

    for(int i  = 1 ; i <= 10 ; i++){
        add(&head, i);
    }

    print(head);

    invert(&head);

    

    print(head);

    delete_list(&head);

    return 0;
}
