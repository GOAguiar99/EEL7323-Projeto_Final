/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: Queue.h
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"



class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();

    void enqueue(Datapkt);
    void dequeue();
    
    void dateSearch(int, int);                          // Displays Log information between dates
    void dateGetBetween(int, int);                                     // Get data between two dates
};

#endif  /* QUEUE_H */