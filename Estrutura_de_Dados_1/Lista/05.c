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
  Nodo *previus, *previusToPrevius;
  
  while(current != NULL && current->data != x){
    previusToPrevius = previus;
    previus = current;
    current = current->next;
  }
  if(current==NULL){std::cout << "Tem esse número não." std::endl; return;}
  
  if(current == head){
    current->next = current->next->next;
  }
  else if(current == head->next){
    head = head->next;
    if(current->next != NULL){
      current->next = current->next->next;
    }
  }
  else if(current->next == NULL){
    previus->next = current->next;
  }
  else{
    previusToPrevius->next = current;
    current->next = current->next->next;
  }
}
