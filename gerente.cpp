#include "gerente.h"
#include <QtCore>

Gerente::Gerente(int id) {
    this->ID = id;
    this->caso = 1;
}

void Gerente::run() {

    while(true) {
        msleep(1000);
        emit updateGUI(caso);
        msleep(15000);
        this->caso = this->caso + 1;
        if(this->caso == 5) {
            this->caso = 1;
        }
    }


}

int Gerente::getCaso() {
    return this->caso;
}

void Gerente::mandarCaso() {
    emit updateGUI(this->caso);
}
