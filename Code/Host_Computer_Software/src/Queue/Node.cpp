/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: Node.cpp
 */

#include "Node.h"

Node::Node(Datapkt data, Node* nxt)
{
    datapkt = data;
    next = nxt;
}

Datapkt Node::getData()
{
    return datapkt;
}

Node* Node::getNext()
{
    return next;
}

void Node::setData(Datapkt data)
{
    datapkt = data;
}

void Node::setNext(Node* nxt)
{
    next = nxt;
}