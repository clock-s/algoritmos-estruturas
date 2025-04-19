#include <stdio.h>
#include <stdlib.h>

struct Double_link{
    
    struct Double_link* prev;
    int key;
    struct Double_link* next;
    

};


typedef struct Double_link Double_link;

//                   head in reference
void add(Double_link **head, int key){
    Double_link *link = (Double_link*)malloc(sizeof(Double_link));

    link->prev = NULL;
    link->next = NULL;
    
    link->key = key;

    link->next = *head;

    if(*head != NULL){
        (*head)->prev = link;
    }

    *head = link;


    printf("add!\n");

}

void see_list(Double_link *head){
    Double_link *pass = head;

    if(head == NULL){
        printf("Empty list!\n");
        return;
    }

    
    while (pass != NULL){
        printf("%d ", pass->key);
        pass = pass->next;
    }
    
    
    printf("\n");
    
}


Double_link* search(Double_link *head, int key){
    Double_link *target = NULL;
    Double_link *pass = head;

    while (pass != NULL){
        if(pass->key == key){
            target = pass;
            break;
        }
        pass = pass->next;
    }

    if(target == NULL){
        printf("The key %d doesn't exist in this list!\n", key);
    }
    
    return target;
}

void remove_key(Double_link **head, int key){
    Double_link *target = search(*head, key);

    if(target == NULL) return;

    if(target->prev != NULL) (target->prev)->next = target->next;
    else (*head) = target->next;

    if(target->next != NULL) (target->next)->prev = target->prev;
    
    //free(target);
    target = NULL;
}

int main(int argc, char const *argv[]){
    
    Double_link *head = NULL;

    see_list(head);

    add(&head, 5);
    add(&head, 6);
    //add(&head, 7);

    see_list(head);

    Double_link *test = search(head, 8);

    remove_key(&head, 6);
    remove_key(&head, 5);
    remove_key(&head, 7);

    


    see_list(head);

    return 0;
}
