/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Queue.hpp
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.hpp"



class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();

    void enqueue(uint32_t);
    void dequeue();
    
};

#endif  /* QUEUE_H */
