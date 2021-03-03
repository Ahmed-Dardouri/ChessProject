#include "List.h"

void List::add_node(Piece n){
    Node *tmp = new Node;
    tmp->p = n;
    tmp->next = nullptr;

    if(head == nullptr){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
}
List::List(){
    head = nullptr;
    tail = nullptr;
}