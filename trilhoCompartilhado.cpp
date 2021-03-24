#include "trilhoCompartilhado.h"
#include <QtCore>

//Construtor
TrilhoCompartilhado::TrilhoCompartilhado(int ID, QString alocadoPara){
    this->ID = ID;
    this->alocadoPara = alocadoPara;
}

//Função a ser executada após executar trem->START
void TrilhoCompartilhado::run(){
    while (true) {
       if(alocadoPara == "trem1") {
           // mudar cor do trilho para cor do trem
       } else if(alocadoPara == "trem2") {

       } else if(alocadoPara == "trem3") {

       } else if(alocadoPara == "trem4") {

       } else if(alocadoPara == "trem5") {

       }
       else {
           // mudar cor do trilho para amarelo
       }
    }
}


QString TrilhoCompartilhado::getAlocadoPara() {
    return alocadoPara;
}

void TrilhoCompartilhado::setAlocadoPara(QString alocar) {
    alocadoPara = alocar;
    emit updateGUI(ID, alocadoPara);
}
