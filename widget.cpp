#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-18);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/fondo.png").scaled(1280,720)));
    //ui->iniciar->setVisible(false);
    ui->splitter->setVisible(false);

    canon = new Canon(0,300,2);
    canon->setDistancia(600);
    scene->addItem(canon);
    canon->addPortal();

    canon2 = new Canon(600,300,2);
    scene->addItem(canon2);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciar_clicked()
{
    ui->iniciar->setVisible(false);
    while (true) {
        double angle = rand() % 90;
        if(canon->disparar(600,300,angle)){
            canon->generarDisparo();
            break;
        }
    }
//    canon->generarDisparo();

}
