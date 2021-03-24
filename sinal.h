#ifndef SINAL_H
#define SINAL_H

#include <QThread>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Sinal: public QThread{
 Q_OBJECT
public:
    Sinal(int, int, bool);  //construtor
    void run();         //função a ser executada pela thread


//Cria um sinal
signals:
    void updateGUI(int,bool);

private:
   int ID;          //ID do sinal
   int milisegundos; //Tempo para abrir ou fechar o sinal
   bool aberto;  //Se esta aberto ou fechado

public:
    bool estaAberto();
    void fechar();
    void abrir();
};




#endif // SINAL_H
