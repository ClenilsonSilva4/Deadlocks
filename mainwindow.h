#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include "sinal.h"
#include "trilhoCompartilhado.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);
    void updateInterface(int,bool);
    void updateInterface(int, QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_sliderTrem1_sliderMoved(int position);

    void on_sliderTrem1_valueChanged(int value);

    void on_sliderTrem2_sliderMoved(int position);

    void on_sliderTrem3_sliderMoved(int position);

    void on_sliderTrem4_sliderMoved(int position);

    void on_sliderTrem5_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

    Sinal *sinal1;
    Sinal *sinal2;
    Sinal *sinal3;
    Sinal *sinal4;
    Sinal *sinal5;
    Sinal *sinal6;
    Sinal *sinal7;
    Sinal *sinal8;
    Sinal *sinal9;
    Sinal *sinal10;

    QString alocar;

    TrilhoCompartilhado *trilho1;
    TrilhoCompartilhado *trilho2;
    TrilhoCompartilhado *trilho3;
    TrilhoCompartilhado *trilho4;
    TrilhoCompartilhado *trilho5;
    TrilhoCompartilhado *trilho6;
    TrilhoCompartilhado *trilho7;
};

#endif // MAINWINDOW_H
