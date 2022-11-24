/**
 * Author: Gabriel de Oliveira Aguiar
 * Institution: UFSC
 * Date: 23/11/2022
 * File: EmbSys.cpp
 */

#include <stdint.h>
#include <fstream>
#include <iostream>
#include "EmbSys.h"


void EmbSys::listData()                                                         // Placeholder listing function
{                                                                               // For now, lists packets by arriving order
    int i, j;
    std::cout << "From: ";
    std::cin >> i;
    
    std::cout << "To : ";
    std::cin >> j;
    std::cout << "Listing packets from " << i << " to " << j << std::endl;
    
    log.dateSearch(i, j);
}

void EmbSys::dateBetween()
{
    int i, j;
    std::cout << "From: ";
    std::cin >> i;
    
    std::cout << "To : ";
    std::cin >> j;
    std::cout << "Getting packets from " << i << " to " << j << std::endl;
    
    log.dateGetBetween(i, j);
}