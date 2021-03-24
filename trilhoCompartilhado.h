#ifndef TRILHOCOMPARTILHADO_H
#define TRILHOCOMPARTILHADO_H

#include <QThread>

class TrilhoCompartilhado: public QThread{
 Q_OBJECT
public:
    TrilhoCompartilhado(int,QString);  //construtor
    void run();         //função a ser executada pela thread
    QString getAlocadoPara();
    void setAlocadoPara(QString);


//Cria um sinal
signals:
    void updateGUI(int,QString);

private:
   int ID;
   QString alocadoPara;

};

#endif // TRILHOCOMPARTILHADO_H
