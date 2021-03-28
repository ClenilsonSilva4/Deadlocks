#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,30);
    trem2 = new Trem(2,440,30);
    trem3 = new Trem(3,710,30);
    trem4 = new Trem(4,350,290);
    trem5 = new Trem(5,610,290);

    sinal1 = new Sinal(1, 5000, false);
    sinal2 = new Sinal(2, 5000, false);
    sinal3 = new Sinal(3, 5000, false);
    sinal4 = new Sinal(4, 15000, false);
    sinal5 = new Sinal(5, 15000, false);
    sinal6 = new Sinal(6, 15000, false);
    sinal7 = new Sinal(7, 15000, false);
    sinal8 = new Sinal(8, 5000, false);
    sinal9 = new Sinal(9, 15000, false);
    sinal10 = new Sinal(10, 15000, false);
    sinal11 = new Sinal(11, 15000, false);
    sinal12 = new Sinal(12, 5000, false);
    sinal13 = new Sinal(13, 15000, false);

    gerente = new Gerente(1);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    connect(sinal1, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal2, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal3, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal4, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal5, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal6, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal7, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal8, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal9, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal10, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal11, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal12, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));
    connect(sinal13, SIGNAL(updateGUI(int,bool)), SLOT(updateInterface(int,bool)));

    connect(gerente, SIGNAL(updateGUI(int)), SLOT(updateInterface(int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
        switch(id){
            case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
                ui->label_trem1->setGeometry(x,y,21,17);
                ui->trem1P->setText("("+QString::number(x)+","+QString::number(y)+")");
                if(x == 290 && y == 30 && !sinal1->estaAberto()) {
                    trem1->terminate();
                    trem1->setParadoNoSinal(true);
                } else if(x == 330 && y == 110 && !sinal13->estaAberto()) {
                    trem1->terminate();
                    trem1->setParadoNoSinal(true);
                }
                break;
            case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
                ui->label_trem2->setGeometry(x,y,21,17);
                ui->trem2P->setText("("+QString::number(x)+","+QString::number(y)+")");
                if(x == 560 && y == 30 && !sinal2->estaAberto()) {
                    trem2->terminate();
                    trem2->setParadoNoSinal(true);
                } else if(x == 370 && y == 150 && !sinal6->estaAberto()) {
                    trem2->terminate();
                    trem2->setParadoNoSinal(true);
                } else if(x == 500 && y == 150 && !sinal9->estaAberto()) {
                    trem2->terminate();
                    trem2->setParadoNoSinal(true);
                } else if(x == 600 && y == 110 && !sinal10->estaAberto()) {
                    trem2->terminate();
                    trem2->setParadoNoSinal(true);
                }
                break;
            case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
                ui->label_trem3->setGeometry(x,y,21,17);
                ui->trem3P->setText("("+QString::number(x)+","+QString::number(y)+")");
                if(x == 770 && y == 150 && !sinal3->estaAberto()) {
                    trem3->terminate();
                    trem3->setParadoNoSinal(true);
                } else if(x == 640 && y == 150 && !sinal4->estaAberto()) {
                   trem3->terminate();
                   trem3->setParadoNoSinal(true);
                }
                break;
            case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
                ui->label_trem4->setGeometry(x,y,21,17);
                ui->trem4P->setText("("+QString::number(x)+","+QString::number(y)+")");
                if(x == 290 && y == 150 && !sinal7->estaAberto()) {
                    trem4->terminate();
                    trem4->setParadoNoSinal(true);
                } else if(x == 190 && y == 190 && !sinal12->estaAberto()) {
                    trem4->terminate();
                    trem4->setParadoNoSinal(true);
                }
                break;
            case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
                ui->label_trem5->setGeometry(x,y,21,17);
                ui->trem5P->setText("("+QString::number(x)+","+QString::number(y)+")");
                if(x == 560 && y == 150 && !sinal5->estaAberto()) {
                    trem5->terminate();
                    trem5->setParadoNoSinal(true);
                } else if(x == 500 && y == 290 && !sinal8->estaAberto()) {
                    trem5->terminate();
                    trem5->setParadoNoSinal(true);
                } else if(x == 460 && y == 190 && !sinal11->estaAberto()) {
                    trem5->terminate();
                    trem5->setParadoNoSinal(true);
                }
                break;
            default:
                break;
        }
}
// mudar cor dos labels sinais e fazer trens andar caso estiverem parados
void MainWindow::updateInterface(int id, bool aberto) {
    switch (id) {
        case 1:
            if(aberto) {
                ui->sinal01->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem1->getX() == 290 && trem1->getY() == 30) {
                   trem1->start();
                   trem1->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal01->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 2:
            if(aberto) {
                ui->sinal02->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem2->getX() == 560 && trem2->getY() == 30) {
                   trem2->start();
                   trem2->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal02->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 3:
            if(aberto) {
                ui->sinal03->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem3->getX() == 770 && trem3->getY() == 150) {
                   trem3->start();
                   trem3->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal03->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 4:
            if(aberto) {
                ui->sinal04->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem3->getX() == 640 && trem3->getY() == 150) {
                    trem3->start();
                    trem3->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal04->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 5:
            if(aberto) {
                ui->sinal05->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem5->getX() == 560 && trem5->getY() == 150) {
                    trem5->start();
                    trem5->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal05->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 6:
            if(aberto) {
                ui->sinal06->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem2->getX() == 370 && trem2->getY() == 150) {
                    trem2->start();
                    trem2->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal06->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 7:
            if(aberto) {
                ui->sinal07->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem4->getX() == 290 && trem4->getY() == 150) {
                    trem4->start();
                    trem4->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal07->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 8:
            if(aberto) {
                ui->sinal08->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem5->getX() == 500 && trem5->getY() == 290) {
                    trem5->start();
                    trem5->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal08->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 9:
            if(aberto) {
                ui->sinal09->setStyleSheet("QLabel {background: rgb(78, 154, 6)}");
                if(trem2->getX() == 500 && trem2->getY() == 150) {
                    trem2->start();
                    trem2->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal09->setStyleSheet("QLabel {background: red}");
            }
            break;
        case 10:
            if(aberto) {
                ui->sinal10->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
                if(trem2->getX() == 600 && trem2->getY() == 110) {
                   trem2->start();
                   trem2->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal10->setStyleSheet("QLabel { background: red}");
            }
            break;
        case 11:
            if(aberto) {
                ui->sinal11->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
                if(trem5->getX() == 460 && trem5->getY() == 190) {
                   trem5->start();
                   trem5->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal11->setStyleSheet("QLabel { background: red}");
            }
            break;
        case 12:
            if(aberto) {
                ui->sinal12->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
                if(trem4->getX() == 190 && trem4->getY() == 190) {
                   trem4->start();
                   trem4->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal12->setStyleSheet("QLabel { background: red}");
            }
            break;
        case 13:
            if(aberto) {
                ui->sinal13->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
                if(trem1->getX() == 330 && trem1->getY() == 110) {
                   trem1->start();
                   trem1->setParadoNoSinal(false);
                }
            }
            else {
                ui->sinal13->setStyleSheet("QLabel { background: red}");
            }
            break;
        default:
            break;
    }
}

void MainWindow::updateInterface(int caso) {
    switch (caso) {
    case 1:
        sinal1->abrir();
        sinal3->abrir();
        sinal4->abrir();
        sinal7->abrir();
        sinal10->abrir();
        sinal13->abrir();
        break;
    case 2:
        sinal2->abrir();
        sinal10->abrir();
        sinal5->abrir();
        sinal9->abrir();
        sinal6->abrir();
        sinal13->abrir();
        break;
    case 3:
        sinal12->abrir();
        sinal7->abrir();
        sinal6->abrir();
        sinal11->abrir();
        break;
    case 4:
        sinal8->abrir();
        sinal11->abrir();
        sinal9->abrir();
        sinal5->abrir();
        sinal4->abrir();
        break;
    default:
        break;
    }
}

// Abrir e fechar sinais dependendo para qual trem alocar
// Não funciona
/*void MainWindow::updateInterface(int id, QString alocadoPara) {
    switch (id) {
    case 1:
        if(alocadoPara == "trem1") {
            // abrir sinais 1
            sinal1->abrir();
        }
        break;
    case 2:
        if(alocadoPara == "trem1") {
            // abrir sinais 2 e 4
            sinal2->abrir();
            sinal4->abrir();
            // fechar sinais 3 e 5
            sinal3->fechar();
            sinal5->fechar();
        }
    default:
        break;
    }
}*/

MainWindow::~MainWindow(){
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked(){
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

    sinal1->start();
    sinal2->start();
    sinal3->start();
    sinal4->start();
    sinal5->start();
    sinal6->start();
    sinal7->start();
    sinal8->start();
    sinal9->start();
    sinal10->start();
    sinal11->start();
    sinal12->start();
    sinal13->start();

    gerente->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked(){
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();

    sinal1->terminate();
    sinal2->terminate();
    sinal3->terminate();
    sinal4->terminate();
    sinal5->terminate();
    sinal6->terminate();
    sinal7->terminate();
    sinal8->terminate();
    sinal9->terminate();
    sinal10->terminate();
    sinal11->terminate();
    sinal12->terminate();
    sinal13->terminate();

    gerente->terminate();
}

void MainWindow::on_sliderTrem1_sliderMoved(int position){
    if(position == 100) {
        trem1->setVelocidade(1);
    } else if(position == 0) {
        trem1->terminate();
    } else {
        trem1->setVelocidade(100-position);
        if(!trem1->getParadoNoSinal()) {
            trem1->start();
        }

    }
}

void MainWindow::on_sliderTrem2_sliderMoved(int position){
    if(position == 100) {
        trem2->setVelocidade(1);
    } else if(position == 0) {
        trem2->terminate();
    } else {
        trem2->setVelocidade(100-position);
        if(!trem2->getParadoNoSinal()) {
            trem2->start();
        }
    }
}

void MainWindow::on_sliderTrem3_sliderMoved(int position){
    if(position == 100) {
        trem3->setVelocidade(1);
    } else if(position == 0) {
        trem3->terminate();
    } else {
        trem3->setVelocidade(100-position);
        if(!trem3->getParadoNoSinal()) {
            trem3->start();
        }
    }
}

void MainWindow::on_sliderTrem4_sliderMoved(int position){
    if(position == 100) {
        trem4->setVelocidade(1);
    } else if(position == 0) {
        trem4->terminate();
    } else {
        trem4->setVelocidade(100-position);
        if(!trem4->getParadoNoSinal()) {
            trem4->start();
        }
    }
}

void MainWindow::on_sliderTrem5_sliderMoved(int position){
    if(position == 100) {
        trem5->setVelocidade(1);
    } else if(position == 0) {
        trem5->terminate();
    } else {
        trem5->setVelocidade(100-position);
        if(!trem5->getParadoNoSinal()) {
            trem5->start();
        }
    }
}
