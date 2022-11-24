/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: Datapkt.h
 */

// Data packet definition

class Datapkt
{
    public:
    int val1, val2; // sensors measures
    int id; // control id
    int pktn; // date in milliseconds
    char msg[20]; //Log message
};
