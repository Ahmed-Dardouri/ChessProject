#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List{

    private:
        Node *head,*tail;
    public:
        List();
        void add_node(Piece n);
        bool search(Node* head, int x);
        Piece GetNth(Piece index);
};


#endif