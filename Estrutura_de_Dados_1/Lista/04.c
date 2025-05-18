/*
Escreva uma função, em C, para eliminar todos os elementos inteiros
repetidos em uma lista simplesmente encadeada. Considere que os elementos
nesta estrutura não estão ordenados.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int data;
    struct Nodo *next;
}Nodo;

void deleteRepeats(Nodo *head){
    if (head == NULL) return; 
    
    Nodo *current = head; 
    
    while(current != NULL && current->next != NULL){ 
        Nodo *runner = current; 
        
        while(runner->next != NULL){  
            if(runner->next->data == current->data){ 
                Nodo *lixo = runner->next;
                runner->next = runner->next->next;  
                free(lixo);  
            } 
            else{
                runner = runner->next; 
            }
        }
        current = current->next;
    }
}
