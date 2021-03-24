#include "sinal.h"
#include <QtCore>

//Construtor
Sinal::Sinal(int ID, int milisegundos, bool aberto){
    this->ID = ID;
    this->aberto = aberto;
    this->milisegundos = milisegundos;
}

//Função a ser executada após executar trem->START
void Sinal::run(){

    emit updateGUI(ID, aberto);
    /*
    while (true) {
        msleep(milisegundos);
        aberto = !aberto;
        emit updateGUI(ID,aberto);
    }
    */
    while(true) {
        msleep(200);
    }
}


bool Sinal::estaAberto() {
    return aberto;
}

void Sinal::abrir() {
    aberto = true;
    emit updateGUI(ID, aberto);
}

void Sinal::fechar() {
    aberto = false;
    emit updateGUI(ID, aberto);
}
