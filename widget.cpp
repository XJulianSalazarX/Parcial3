#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //ui->iniciar->setGeometry(555,275,170,170);
    ui->setupUi(this);
    this->setMinimumSize(width(),height());
    this->setMaximumSize(width(),height());
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(width(),height()-10);
    ui->graphicsView->setSceneRect(0,0,width(),height()-20);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->iniciar->setVisible(false);
    ui->splitter->setVisible(false);

    canon = new Canon(100,100,10);
    scene->addItem(canon);
    canon->addPortal();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_iniciar_clicked()
{
    canon->generarDisparo();
    ui->iniciar->setVisible(false);
}
