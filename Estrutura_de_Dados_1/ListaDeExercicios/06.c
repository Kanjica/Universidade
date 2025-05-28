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

Nodo* madness(Nodo *head) {
    if (head == NULL) return NULL;

    Nodo *evenList = NULL;  // Lista de pares (ordem decrescente)
    Nodo *oddList = NULL;   // Lista de ímpares (ordem crescente)
    Nodo *current = head;

    while (current != NULL) {
        Nodo *next = current->next;  // Salva o próximo antes de mexer

        if (current->data % 2 == 0) {  // PARES (ordem decrescente)
            if (evenList == NULL || current->data >= evenList->data) {
                // Insere no início (para ordem decrescente)
                current->next = evenList;
                evenList = current;
            } else {
                // Procura a posição correta
                Nodo *temp = evenList;
                while (temp->next != NULL && current->data < temp->next->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        } else {  // ÍMPARES (ordem crescente)
            if (oddList == NULL || current->data <= oddList->data) {
                // Insere no início (para ordem crescente)
                current->next = oddList;
                oddList = current;
            } else {
                // Procura a posição correta
                Nodo *temp = oddList;
                while (temp->next != NULL && current->data > temp->next->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }
        current = next;  // Avança para o próximo nó
    }

    // Liga a lista de pares com a de ímpares
    if (evenList == NULL) return oddList;  // Só ímpares
    if (oddList == NULL) return evenList;  // Só pares

    Nodo *lastEven = evenList;
    while (lastEven->next != NULL) {
        lastEven = lastEven->next;
    }
    lastEven->next = oddList;  // Conecta as listas

    return evenList;
}
