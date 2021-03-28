#ifndef GERENTE_H
#define GERENTE_H

#include <QThread>

class Gerente: public QThread{
 Q_OBJECT
public:
    Gerente(int);  //construtor
    void run();         //função a ser executada pela thread
    int getCaso();


//Cria um sinal
signals:
    void updateGUI(int);

private:
   int ID;
   int caso;

   void mandarCaso();
};

#endif // GERENTE_H
