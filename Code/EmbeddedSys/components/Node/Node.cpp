/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 26/11/2022
 * File: Node.cpp
 */
#include "Node.hpp"

Node::Node(uint32_t data, Node* nxt)
{
    datapkt = data;
    next = nxt;
}

uint32_t Node::getData()
{
    return datapkt;
}

Node* Node::getNext()
{
    return next;
}

void Node::setData(uint32_t data)
{
    datapkt = data;
}

void Node::setNext(Node* nxt)
{
    next = nxt;
}
