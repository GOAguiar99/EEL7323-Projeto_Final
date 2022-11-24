/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: Node.h
 */

#ifndef NODE_H
#define NODE_H

#include "../Datapkt/Datapkt.h"

class Node
{
protected:
    Datapkt datapkt;                      // Data packet information
    Node* next;                             // Pointer to next node

public:
    Node(Datapkt datapkt, Node* next);          
    
    Datapkt getData();
    Node* getNext();
    void setData(Datapkt data);
    void setNext(Node* nxt);
};

#endif  /* NODE_H */