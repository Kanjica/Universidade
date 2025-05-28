/*
Considere uma lista simplesmente encadeada que armazene números em
ordem crescente. Escreva uma função, em C, que receba esta lista, e remova o
nó antecessor e o sucessor a um determinado nó contendo um elemento X
(inteiro).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int data;
    struct Nodo *next;
}Nodo;

void beforeAndAfter(Nodo *head, int x){
    if(head == NULL) return;

    Nodo *current = head;
    Nodo *previous = NULL;
    Nodo *previousToPrevious = NULL;

    while(current != NULL && current->data != x){
        previousToPrevious = previous;
        previous = current;
        current = current->next;
    }

    if(current == NULL){printf("Tem esse número não.\n");return;}

    if(previous == NULL){
        if(current->next != NULL){
            Nodo *temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        return;
    }

    if(current->next == NULL){
        if (previousToPrevious != NULL){
            previousToPrevious->next = current;
            free(previous);
        } 
        else{
            head->next = current;
            free(previous);
        }
        return;
    }

    if(previousToPrevious != NULL){
        previousToPrevious->next = current;  
    } 
    else{
        head = current;  
    }

    Nodo *temp = current->next;
    current->next = temp->next;
    free(temp);
}
