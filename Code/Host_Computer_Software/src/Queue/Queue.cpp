/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: Queue.cpp
 */
#include <iostream>
#include "Queue.h"


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

void Queue::enqueue(Datapkt data)
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
    std::cout << "Dequeueing..." << std::endl;
}

void Queue::dateSearch(int min, int max)
{
    int aux = 0;
    Node* scan = head;
    
    if (scan == nullptr)
    {
        std::cout << "Sem nodos na fila" << std::endl;
    }
    else
    {
        while (scan != nullptr)
        {
            aux = scan->getData().pktn;                              // Placeholder search algorithm
            if ((aux >= min) && (aux <= max))
            {
                std::cout << std::endl;
                std::cout << "ID number: "<< scan->getData().id << std::endl;
                std::cout << "Data Number: "<< scan->getData().pktn << std::endl;
                std::cout << "Measure Temperature: " << scan->getData().val1 << std::endl;
                std::cout << "Measure Humidity: " << scan->getData().val2 << std::endl;
                std::cout << "Msg: " << scan->getData().msg << std::endl;
            }
            scan = scan->getNext();
        }
    }
    return;
}

void Queue::dateGetBetween(int min, int max)
{
// to do.. //
}