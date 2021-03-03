#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List{

    private:
        Node *head,*tail;
    public:
        List();
        void add_node(Piece n);
};


#endif