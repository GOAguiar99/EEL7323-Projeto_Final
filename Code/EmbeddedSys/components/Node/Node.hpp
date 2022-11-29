/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Node.hpp
 */
#ifndef NODE_H
#define NODE_H

#include <stdint.h>

class Node
{
protected:
    uint32_t datapkt;                      // Data packet information
    Node* next;                             // Pointer to next node

public:
    Node(uint32_t datapkt, Node* next);          
    
    uint32_t getData();
    Node* getNext();
    void setData(uint32_t data);
    void setNext(Node* nxt);
};

#endif  /* NODE_H */
