/*
3. Escreva uma função, em C, que receba duas listas simplesmente encadeadas
Ae B, contendo informações (Código e Nome) dos pacientes do médico X e do
médico Y (respectivamente), de uma determinada clínica. A clínica deseja
possuir uma lista única com as informações dos pacientes desses dois médicos
a partir da junção dessas duas listas. Considere que as listas A e B estão
ordenadas por código de pacientes e que não existem dois (ou mais) pacientes
com o mesmo código. A lista resultante deve conter todos os pacientes dos
médicos X e Y ordenados por código e sem elementos repetidos.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int code;
    char name[20];
    struct Nodo *next;
} Nodo;

Nodo* removeRepeats(Nodo *list){
    if(list == NULL) return NULL;
    Nodo* current = list;
    while(current->next != NULL){
        if(current->code == current->next->code){
            Nodo* temp = current->next;
            current->next = temp->next;
            free(temp);
        } 
        else{
            current = current->next;
        }
    }
    return list;
}

Nodo* unifyLists(Nodo *doctorX, Nodo *doctorY){
    if(doctorX == NULL) return doctorY;
    if(doctorY == NULL) return doctorX;

    Nodo* unifiedList = NULL;
    Nodo* auxX = doctorX;
    Nodo* auxY = doctorY;
    Nodo* auxUnifiedList = unifiedList;  

    while(auxX != NULL && auxY != NULL){
        if(auxX->code <= auxY->code){
            if(auxUnifiedList == NULL){
                unifiedList = auxX;
                auxUnifiedList = unifiedList;
            } 
            else{
                auxUnifiedList->next = auxX;
                auxUnifiedList = auxUnifiedList->next;
            }
            auxX = auxX->next;
        } 
        else{
            if (auxUnifiedList == NULL){
                unifiedList = auxY;
                auxUnifiedList = unifiedList;
            } 
            else{
                auxUnifiedList->next = auxY;
                auxUnifiedList = auxUnifiedList->next;
            }
            auxY = auxY->next;
        }
    }

    if(auxX != NULL){auxUnifiedList->next = auxX;} 
    else if(auxY != NULL){auxUnifiedList->next = auxY;}

    return removeRepeats(unifiedList);
}
