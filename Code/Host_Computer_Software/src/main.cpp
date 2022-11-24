/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 02/03/2022
 * File: main.cpp
 */
#include <iostream>
#include <thread>
#include <unistd.h>
#include "../src/EmbSysLinux/EmbSysLinux.h"

using namespace std;

void serialMonitoring();
void pressEnterToContinue();

EmbSysLinux* Raspberry;                             // Embedded System interface

int main(){
    Raspberry = new EmbSysLinux();

    thread monitor (serialMonitoring);
    usleep(500000); // Wait for readser thread to print serial connection report
    char op = '0';


    while (true)
    {
        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << endl;
        cout << "MENU" << endl;
        cout << endl;
        cout << "   1 - Listas todos os eventos ocorridos em um determinado intervalo de datas" << endl;
        cout << "   2 - Obter os dados adquiridos, enviados ou não, em um determinado intervalo de datas." << endl;
        cout << endl;
        cout << "Escolha a operacao: ";
        cin >> op;
        cout << endl;
        cout << "-------------------------------------------------------------" << endl << endl;

        switch (op)
        {
        case '1':
            Raspberry->listData();
            pressEnterToContinue();
            break;

        case '2':
            Raspberry->dateBetween();
            pressEnterToContinue();
            break;


        default:
            cout << endl << "Operação invalida, tente novamente" << endl;
            pressEnterToContinue();
            break;
        }

    }
    delete Raspberry;
    return 0;
}


void serialMonitoring()
{
    const char* port = "/dev/ttyUSB0";  // Port to use
    
    Raspberry->openSerial(port);
    Raspberry->serialMonitor();
    delete Raspberry;
}

void pressEnterToContinue(){
    cout << endl << "Pressione 'Enter' para continuar";
    cin.ignore();
    cin.get();
}