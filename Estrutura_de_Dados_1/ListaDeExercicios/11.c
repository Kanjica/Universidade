typedef struct Nodo{
    int data;
    struct Nodo *next, *previous;
}Nodo;

Nodo* listK(Nodo *list){
    if(list == NULL) return NULL;

    Nodo *newList = NULL;
    Nodo *tail = NULL;
    Nodo *current = list;

    while(current->next != NULL){
        current = current->next;
    }
    tail = current;

    current = list;
    newList = current;

    while(current != tail && current->next != tail){
        current->previous = tail;
        tail->previous = current->next;

        current = current->next;
        tail = tail->previous;
    }

    if(current == tail){
        current->previous = NULL;
    } 
    else if(current->next == tail){
        current->previous = tail;
        tail->previous = NULL;
    }
    return newList;
}
