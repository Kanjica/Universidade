/*
Escreva uma função, em C, que receba uma lista simplesmente
encadeada contendo em cada nó um inteiro, e retorne uma outra lista contendo nas
primeiras posições os elementos pares em ordem decrescente, seguidos dos 
elementos ímpares em ordem crescente.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int data;
    struct Nodo *next;
} Nodo;

Nodo* madness(Nodo *head){
  if(head==NULL)return NULL;
  
  Nodo *current = head;
  Nodo *evenList, *oddList, *runnerEven, *runnerOdd;
  evenList = oddList = runnerEven = runnerOdd = NULL;
  
  while(current!=NULL){
    if(current->data%2==0){
      if(evenList == NULL){ 
        evenList = current; 
        runnerEven = evenList;
      }
      else{   
        runnerEven = evenList;
        Nodo *previusRuEven = NULL;
        while(runnerEven != NULL && current->data < runnerEven->data){
          previusRuEven = runnerEven;
          runnerEven = runnerEven->prox;
        }
        if(runnerEven == NULL){
          previusRuEven->prox = current;
          //runnerEven->prox = NULL;
        } 
        else if(runnerEven == evenList){
          runnerEven->next = evenList;
          evenList = runnerEven;
        }
        else{
          Nodo* temp = runnerEven;
          runnerEven = current;
          previusRuEven->next = runnerEven;
          runnerEven->next = temp;
        }
      }
    }
    else{
      if(oddList == NULL){ 
        oddList = current; 
        runnerOdd = oddList;
      }
      else{
        runnerOdd = oddList;
        Nodo *previusRuOdd = NULL;
        while(runnerOdd != NULL && current->data > runnerOdd->data){
          runnerOdd = runnerOdd->prox;
        }
        if(runnerOdd == NULL){
          previusRuOdd->prox = current;
          //runnerOdd->prox = NULL
        } 
        else if(runnerOdd == oddList){
          runnerOdd->next = oddList;
          oddList = runnerOdd;
        }
        else{
          Nodo* temp = runnerOdd;
          runnerOdd = current;
          previusRuOdd->next = runnerOdd;
          runnerOdd->next = temp;
        }
      }
    }
    current=current->next;
  }
  runnerEven->next = oddList;
  Nodo *madnessList = evenList;
  return madnessList;
}
