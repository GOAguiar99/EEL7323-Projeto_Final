/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Queue.cpp
 */
#include <iostream>
#include "Queue.hpp"


Queue::Queue ()
{
    head = 0;
    tail = 0;
}

Queue::~Queue()
{
    Node* aux;
    while (head)
    {
        aux = head;
        head = head->getNext();
        delete aux;
    }
}

void Queue::enqueue(uint32_t data)
{
    if (!tail)                                                  // Check if tail is not set (first node)
    {
        tail = new Node(data, nullptr);
    }
    else                                                        // Create new node and insert after current tail
    {
        Node* aux = new Node(data, nullptr);
        tail->setNext(aux);
        tail = aux;
    }

    if (!head)                                                  // Set the head if it's not set (first node)
    {
        head = tail;
    }
}

void Queue::dequeue()
{
    Node* aux = head;
    head = head->getNext();                                     // Point the head to the next node and delete current node
    delete aux;
}
