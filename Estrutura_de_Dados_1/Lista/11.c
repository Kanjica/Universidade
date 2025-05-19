typedef struct Nodo{
  int data;
  struct Nodo *next, *previous;
}Nodo;

Nodo * listK(Nodo *list){
  if(list==NULL) return NULL;

  Nodo *newList = NULL;
  Nodo *tail = NULL;
  Nodo *current = list;

  while(current->next != NULL){
    current = current->next;
  }
  tail = current;
  current = list;
  newList = current;
  
  while(current != tail){
    current->previous = tail;
    tail->previous = current->next;
    
    tail = tail->previous;
    current = current->next;
  }
  return newList;
}
