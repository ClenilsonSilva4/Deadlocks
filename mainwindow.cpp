#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,30);
    trem2 = new Trem(2,480,30);
    trem3 = new Trem(3,750,30);
    trem4 = new Trem(4,330,290);
    trem5 = new Trem(5,600,290);

    sinal1 = new Sinal(1, 2000, true);
    sinal2 = new Sinal(2, 2000, true);
    sinal3 = new Sinal(3, 2000, true);
    sinal4 = new Sinal(4, 2000, true);
    sinal5 = new Sinal(5, 2000, true);
    sinal6 = new Sinal(6, 2000, true);
    sinal7 = new Sinal(7, 2000, true);
    sinal8 = new Sinal(8, 2000, true);
    sinal9 = new Sinal(9, 2000, true);
    sinal10 = new Sinal(10, 2000, true);

    alocar = "ninguem";
    trilho1 = new TrilhoCompartilhado(1, "ninguem");
    trilho2 = new TrilhoCompartilhado(2, "ninguem");
    trilho3 = new TrilhoCompartilhado(3, "ninguem");
    trilho4 = new TrilhoCompartilhado(4, "ninguem");
    trilho5 = new TrilhoCompartilhado(5, "ninguem");
    trilho6 = new TrilhoCompartilhado(6, "ninguem");
    trilho7 = new TrilhoCompartilhado(7, "ninguem");

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

    connect(trilho1, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
    connect(trilho2, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
    connect(trilho3, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
    connect(trilho4, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
    connect(trilho5, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
    connect(trilho6, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
    connect(trilho7, SIGNAL(updateGUI(int,QString)), SLOT(updateInterface(int,QString)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){

        switch(id){
        case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
            ui->label_trem1->setGeometry(x,y,21,17);
            ui->trem1P->setText("("+QString::number(x)+","+QString::number(y)+")");
            break;
        case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
            ui->label_trem2->setGeometry(x,y,21,17);
            ui->trem2P->setText("("+QString::number(x)+","+QString::number(y)+")");
            break;
        case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
            ui->label_trem3->setGeometry(x,y,21,17);
            ui->trem3P->setText("("+QString::number(x)+","+QString::number(y)+")");
            break;
        case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
            ui->label_trem4->setGeometry(x,y,21,17);
            ui->trem4P->setText("("+QString::number(x)+","+QString::number(y)+")");
            break;
        case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
            ui->label_trem5->setGeometry(x,y,21,17);
            ui->trem5P->setText("("+QString::number(x)+","+QString::number(y)+")");
            break;
        default:
            break;
        }

        // Parar trem no sinal vermelho
        switch(id) {
        case 1:
            if(x == 270 && y == 30 && !sinal1->estaAberto()) {
                trem1->terminate();
            }
            break;
        case 2:
            if(x == 540 && y == 30 && !sinal6->estaAberto()) {
                trem2->terminate();
            }
            break;
        case 3:
            if(x == 800 && y == 150 && !sinal7->estaAberto()) {
                trem3->terminate();
            }
            break;
        case 4:
            if(x == 190 && y == 210 && !sinal3->estaAberto()) {
                trem4->terminate();
            }
            break;
        case 5:
            if(x == 530 && y == 290 && !sinal10->estaAberto()) {
                trem5->terminate();
            }
            break;
        default:
            break;
        }

        // Pedir para alocar trilho
        switch (id) {
        case 1:
            if(x == 270 && y == 30 && trilho1->getAlocadoPara() == "ninguem" && trilho3->getAlocadoPara() == "ninguem") {
                trilho1->setAlocadoPara("trem1");
                trilho3->setAlocadoPara("trem1");
                // abrir sinais 1, 2 e 4
                sinal1->abrir();
                //sinal2->abrir();
                //sinal4->abrir();
                // fechar sinais 3 e 5
                sinal3->fechar();
                sinal5->fechar();
            } else if(x == 270 && y == 30 && trilho1->getAlocadoPara() != "trem1" && trilho3->getAlocadoPara() != "trem1"){
                sinal1->fechar();
            }
            break;
        case 2:
            if(x == 540 && y == 30 && trilho1->getAlocadoPara() == "ninguem" && trilho2->getAlocadoPara() == "ninguem" && trilho4->getAlocadoPara() == "ninguem" && trilho5->getAlocadoPara() == "ninguem") {
                trilho1->setAlocadoPara("trem2");
                trilho2->setAlocadoPara("trem2");
                trilho4->setAlocadoPara("trem2");
                trilho5->setAlocadoPara("trem2");

                sinal6->abrir();
            } else if(x == 540 && y == 30  && trilho1->getAlocadoPara() != "trem2" && trilho2->getAlocadoPara() != "trem2" && trilho4->getAlocadoPara() != "trem2" && trilho5->getAlocadoPara() != "trem2") {
                sinal6->fechar();
            }
            break;
        case 3:
            if(x == 800 && y == 150 && trilho2->getAlocadoPara() == "ninguem" && trilho6->getAlocadoPara() == "ninguem") {
                trilho2->setAlocadoPara("trem3");
                trilho6->setAlocadoPara("trem3");
                // abrir sinal 7
                sinal7->abrir();
                // fechar sinal 6
                sinal6->fechar();
            } else if(x == 800 && y == 150 && trilho2->getAlocadoPara() != "trem3" && trilho6->getAlocadoPara() != "trem3") {
                sinal7->fechar();
            }
            break;
        case 4:
            if(x == 190 && y == 210 && trilho3->getAlocadoPara() == "ninguem" && trilho4->getAlocadoPara() == "ninguem" && trilho7->getAlocadoPara() == "ninguem") {
                trilho3->setAlocadoPara("trem4");
                trilho4->setAlocadoPara("trem4");
                trilho7->setAlocadoPara("trem4");
                // abrir sinais 3, 4 e 5
                //sinal3->abrir();
                sinal4->abrir();
                sinal5->abrir();
                // fechar sinal 1 e 10
                sinal1->fechar();
                sinal10->fechar();
            } else if(x == 190 && y == 210 && trilho3->getAlocadoPara() != "trem4" && trilho4->getAlocadoPara() != "trem4") {
                sinal3->fechar();
            }
            break;
         case 5:
            if(x == 530 && y == 290 && trilho7->getAlocadoPara() == "ninguem" && trilho5->getAlocadoPara() == "ninguem" && trilho6->getAlocadoPara() == "ninguem") {
                trilho5->setAlocadoPara("trem5");
                trilho6->setAlocadoPara("trem5");
                trilho7->setAlocadoPara("trem5");
                // fechar sinais 3, 6 e 7
                sinal3->fechar();
                sinal6->fechar();
                sinal7->fechar();
            } else if(x == 530 && y == 290 && trilho7->getAlocadoPara() != "trem5" && trilho5->getAlocadoPara() != "trem5" && trilho6->getAlocadoPara() != "trem5") {
                sinal10->fechar();
            }
        default:
            break;
        }
        // Pedir para desalocar trilho
        switch(id) {
        case 1:
            if(x == 160 && y == 150) {
                trilho1->setAlocadoPara("ninguem");
                trilho3->setAlocadoPara("ninguem");
                // abrir sinais fechados
                sinal3->abrir();
                sinal5->abrir();
                sinal1->fechar();
            }
            break;
        case 2:
            if(x == 360 && y == 30) {
                trilho1->setAlocadoPara("ninguem");
                trilho2->setAlocadoPara("ninguem");
                trilho4->setAlocadoPara("ninguem");
                trilho5->setAlocadoPara("ninguem");

                sinal6->fechar();
            }
            break;
        case 3:
            if(x == 630 && y == 30) {
                trilho2->setAlocadoPara("ninguem");
                trilho6->setAlocadoPara("ninguem");

                sinal7->fechar();
            }
            break;
        case 4: {
            if(x == 420 && y == 290) {
                trilho3->setAlocadoPara("ninguem");
                trilho4->setAlocadoPara("ninguem");
                trilho7->setAlocadoPara("ninguem");

                sinal1->abrir();
                sinal10->abrir();

                sinal3->fechar();

            }
            break;
        }
        case 5: {
            if(x == 730 && y == 200) {
                trilho5->setAlocadoPara("ninguem");
                trilho6->setAlocadoPara("ninguem");
                trilho7->setAlocadoPara("ninguem");

                //sinal3->abrir();
                //sinal6->abrir();
                //sinal7->abrir();

                sinal10->fechar();

            }
        }
        default:
            break;
        }

}
// mudar cor dos labels sinais e fazer trens andar caso estiverem parados
void MainWindow::updateInterface(int id, bool aberto) {
    switch (id) {
    case 1:
        if(aberto) {
               ui->sinal1->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
               if(trem1->getX() == 270 && trem1->getY() == 30) {
                   trem1->start();
               }
        }
        else {
            ui->sinal1->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 2:
        if(aberto) {
               ui->sinal2->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
               if(trem2->getX() == 540 && trem2->getY() == 30) {
                   trem2->start();
               }

        }
        else {
            ui->sinal2->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 3:
        if(aberto) {
               ui->sinal3->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
               if(trem4->getX() == 190 && trem4->getY() == 210) {
                   trem4->start();
               }

        }
        else {
            ui->sinal3->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 4:
        if(aberto) {
               ui->sinal4->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");

        }
        else {
            ui->sinal4->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 5:
        if(aberto) {
               ui->sinal5->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");

        }
        else {
            ui->sinal5->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 6:
        if(aberto) {
               ui->sinal6->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");

        }
        else {
            ui->sinal6->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 7:
        if(aberto) {
               ui->sinal7->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
               if(trem3->getX() == 800 && trem3->getY() == 150) {
                    trem3->start();
               }

        }
        else {
            ui->sinal7->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 8:
        if(aberto) {
               ui->sinal8->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");

        }
        else {
            ui->sinal8->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 9:
        if(aberto) {
               ui->sinal9->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");

        }
        else {
            ui->sinal9->setStyleSheet("QLabel { background: red}");
        }
        break;
    case 10:
        if(aberto) {
               ui->sinal10->setStyleSheet("QLabel { background: rgb(78, 154, 6)}");
               if(trem5->getX() == 530 && trem5->getY() == 290) {
                   trem5->start();
               }
        }
        else {
            ui->sinal10->setStyleSheet("QLabel { background: red}");
        }
        break;
    default:
        break;
    }
}

// Abrir e fechar sinais dependendo para qual trem alocar
// Não funciona
void MainWindow::updateInterface(int id, QString alocadoPara) {
    /*
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
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked()
{
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

    trilho1->start();
    trilho2->start();
    trilho3->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();

    sinal1->terminate();
}

void MainWindow::on_sliderTrem1_sliderMoved(int position)
{
    if(position == 100) {
        trem1->setVelocidade(1);
    } else if(position == 0) {
        trem1->terminate();
    } else {
        trem1->setVelocidade(100-position);
        trem1->start();
    }
}

void MainWindow::on_sliderTrem2_sliderMoved(int position)
{
    if(position == 100) {
        trem2->setVelocidade(1);
    } else if(position == 0) {
        trem2->terminate();
    } else {
        trem2->setVelocidade(100-position);
        trem2->start();
    }
}

void MainWindow::on_sliderTrem3_sliderMoved(int position)
{
    if(position == 100) {
        trem3->setVelocidade(1);
    } else if(position == 0) {
        trem3->terminate();
    } else {
        trem3->setVelocidade(100-position);
        trem3->start();
    }
}

void MainWindow::on_sliderTrem4_sliderMoved(int position)
{
    if(position == 100) {
        trem4->setVelocidade(1);
    } else if(position == 0) {
        trem4->terminate();
    } else {
        trem4->setVelocidade(100-position);
        trem4->start();
    }
}

void MainWindow::on_sliderTrem5_sliderMoved(int position)
{
    if(position == 100) {
        trem5->setVelocidade(1);
    } else if(position == 0) {
        trem5->terminate();
    } else {
        trem5->setVelocidade(100-position);
        trem5->start();
    }
}
