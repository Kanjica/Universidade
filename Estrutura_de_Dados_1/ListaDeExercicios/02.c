/*
2. Escreva uma função, em C, que receba uma lista simplesmente encadeada, e
retome uma lista ordenada (crescente) sem alocar espaços para novos
elementos da lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int data;
    struct Nodo *next;
} Nodo;

Nodo* sortList(Nodo *head) {
    if(head == NULL){return head;}

    Nodo *sorted = NULL; 
    Nodo *current = head; 

    while(current != NULL){
        Nodo *next = current->next; 

        if(sorted == NULL){
            current->next = sorted;
            sorted = current;
        } 
        else{
            Nodo *temp = sorted;
            while(temp->next != NULL && temp->next->data < current->data){
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next; 
    }
    return sorted; 
}
