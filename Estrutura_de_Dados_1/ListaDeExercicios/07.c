/*Escreva uma função, em C, para somar dois números inteiros. Cada número
está armazenado em uma lista simplesmente encadeada dinâmica, e cada nó
da lista contém um dígito de um número e um apontador para o próximo nó. O
primeiro nó de cada lista contém o dígito mais significativo (dígito mais à
esquerda do número) e o último nó de cada lista contém o dígito menos
significativo (dígito mais à direita do número). A função deve receber como
parâmetros o endereço do início da lista que contém o primeiro número e o
endereço do início da lista que contém o segundo (as duas listas já existem). À
função deve retomar o endereço do início da lista que conterá o número
correspondente à soma dos dois números. Veja o exemplo abaixo que soma os
números 581133 e 118:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int data;
    struct Nodo *next;
}Nodo;

Nodo* sum(Nodo* list1, Nodo* list2){
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    int num1 = 0;
    Nodo *runner = list1;
    while(runner != NULL){
        num1 = num1 * 10 + runner->data;
        runner = runner->next;
    }

    int num2 = 0;
    runner = list2;
    while(runner != NULL){
        num2 = num2 * 10 + runner->data;
        runner = runner->next;
    }
    
    int sumResult = num1 + num2;

    Nodo *newList = NULL;
    Nodo *tail = NULL;
    
    int temp = sumResult;
    int digitCount = 0;
    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }
    
    int divisor = 1;
    for (int i = 1; i < digitCount; i++) {
        divisor *= 10;
    }
    
    for(; divisor > 0; divisor /= 10){
        int digit = (sumResult / divisor) % 10;
        
        Nodo *newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->data = digit;
        newNode->next = NULL;
        
        if(newList == NULL){
            newList = newNode;
            tail = newNode;
        } 
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return newList;
}
