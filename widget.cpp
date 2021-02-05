#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    punto = 0;

    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-18);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.png").scaled(1280,720)));
    ui->iniciar->setVisible(false);
    ui->next->setVisible(false);

    ofensivo = new CanonOfensivo(0,300,2);
    scene->addItem(ofensivo);
    ofensivo->addPortal();
    defensivo = new CanonDefensivo(1000,100,2);
    scene->addItem(defensivo);
    defensivo->addPortal();
    ofensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));
    defensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciar_clicked()
{
    ui->iniciar->setVisible(false);
    switch (punto) {
    case 1:{
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                break;
            }
        }
    }
        break;
    case 2:{

    }
        break;
    case 3:{

    }
        break;
    case 4:{

    }
        break;
    case 5:{

    }
        break;
    default:{
        qDebug() << "Opcion no valida";
    }
    }
}

void Widget::on_punto1_clicked()
{
    punto = 1;
//    ofensivo = new CanonOfensivo(0,300,2);
//    scene->addItem(ofensivo);
//    ofensivo->addPortal();
//    defensivo = new CanonDefensivo(1000,300,2);
//    scene->addItem(defensivo);
//    defensivo->addPortal();
//    ofensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));
//    defensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
}

void Widget::on_next_clicked()
{

}
