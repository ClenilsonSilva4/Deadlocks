#include "sinal.h"
#include <QtCore>

//Construtor
Sinal::Sinal(int ID, int milisegundos, bool aberto){
    this->ID = ID;
    this->estado = aberto;
    this->tempoAcao = milisegundos;
}

//Função a ser executada após executar trem->START
void Sinal::run(){
    if(estado == true) {
        this->abrir();
    } else {
        this->fechar();
    }
    while(true) {
        msleep(200);
        if(estado) {
            msleep(tempoAcao);
            this->fechar();
        }
    }
}


bool Sinal::estaAberto() {
    return estado;
}

void Sinal::abrir() {
    //msleep(100);
    estado = true;
    emit updateGUI(ID, estado);

}

void Sinal::fechar() {
    estado = false;
    emit updateGUI(ID, estado);
}
