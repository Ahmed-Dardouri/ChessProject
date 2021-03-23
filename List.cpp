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
/*bool List::search(Piece x){  
    Node* current = this;
    while (current != NULL)  
    {  
        if (current->p == x)  
            return true;  
        current = current->next;  
    }  
    return false;  
}  

Piece List::GetNth(Piece index)
{
 
    Node* current = this;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->p);
        count++;
        current = current->next;
    }
    assert(0);
}

void List::deleteNode(Node *n)  
{  
    if(head == n)  
    {  
        if(head->next == NULL)  
        {  
            cout << "There is only one node." << 
                    " The list can't be made empty ";  
            return;  
        }  
  
        head->data = head->next->data;  
  
        // store address of next node  
        n = head->next;  
  
        // Remove the link of next node  
        head->next = head->next->next;  
  
        // free memory  
        free(n);  
  
        return;  
    }  
  
  
    // When not first node, follow  
    // the normal deletion process  
  
    // find the previous node  
    Node *prev = head;  
    while(prev->next != NULL && prev->next != n)  
        prev = prev->next;  
  
    // Check if node really exists in Linked List  
    if(prev->next == NULL)  
    {  
        cout << "\nGiven node is not present in Linked List";  
        return;  
    }  
  
    // Remove node from Linked List  
    prev->next = prev->next->next;  
  
    // Free memory  
    free(n);  
  
    return;  
}  */