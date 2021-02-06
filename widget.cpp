#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    punto = 0;
    balas = 0;
    probados = 0;

    timer = new QTimer();

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
    ui->label->setVisible(false);
    invisible();

//    ofensivo = new CanonOfensivo(0,300,2);
//    scene->addItem(ofensivo);
//    ofensivo->addPortal();
//    ofensivo->addPortal2();

//    defensivo = new CanonDefensivo(1275,300,2);
//    scene->addItem(defensivo);
//    defensivo->addPortal();
//    ofensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));
//    defensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::visible()
{
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->xo->setVisible(true);
    ui->yo->setVisible(true);
    ui->xd->setVisible(true);
    ui->yd->setVisible(true);
}

void Widget::invisible()
{
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->xo->setVisible(false);
    ui->yo->setVisible(false);
    ui->xd->setVisible(false);
    ui->yd->setVisible(false);
}

void Widget::nextVisible()
{
    ui->next->setVisible(true);
}

void Widget::mostrarDatos()
{
    ui->label->setVisible(true);
}

void Widget::agregarTexto(QString datos)
{
    ui->label->setText(ui->label->text()+datos);
}

void Widget::quitarPortal()
{
    ofensivo->portalInvisible();
    defensivo->portalInvisible();
}

void Widget::on_iniciar_clicked()
{
    ui->label->setText("");
    if(ui->xd->value()-ui->xo->value()<640){
        QMessageBox::critical(this,"Error","La distancia horizontal minima entre los cañones debe ser de 640.");
        return;
    }
    ui->iniciar->setVisible(false);
    invisible();

    ofensivo = new CanonOfensivo(ui->xo->value(),ui->yo->value(),2);
    scene->addItem(ofensivo);
    ofensivo->addPortal();
    ofensivo->addPortal2();

    defensivo = new CanonDefensivo(ui->xd->value(),ui->yd->value(),2);
    scene->addItem(defensivo);
    defensivo->addPortal();
    ofensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));
    defensivo->setDistancia(abs(ofensivo->getPosx()-defensivo->getPosx()));

    switch (punto) {
    case 1:{
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
        break;
    case 2:{
        while (true){
            double angle = 91 + rand() % (181-91);
            if(defensivo->disparar(ofensivo->getPosx(),ofensivo->getPosy(),angle)){
                defensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
        break;
    case 3:{
        balas = 0;
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                break;
            }
        }
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 4:{
        balas = 0;
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                break;
            }
        }
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 5:{
        balas = 0;
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                break;
            }
        }
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);

    }
        break;
    default:{
        qDebug() << "Opcion no valida";
    }
        break;
    }
}

void Widget::on_punto1_clicked()
{
    punto = 1;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
    visible();
}

void Widget::on_next_clicked()
{
    ui->next->setVisible(false);
    if(balas == 3){
        mostrarDatos();
        return;
    }
    switch (punto) {
    case 1:{
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
        break;
    case 2:{
        while (true) {
            double angle = 91 + rand() % (181-91);
            if(defensivo->disparar(ofensivo->getPosx(),ofensivo->getPosy(),angle)){
                defensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
        break;
    case 3:{
        ofensivo->generarDisparo();
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 4:{
        ofensivo->generarDisparo();
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 5:{
        ofensivo->generarDisparo();
        connect(timer,SIGNAL(timeout()),this,SLOT(repetirDispDefensivo()));
        timer->start(2000);

    }
        break;
    default:{
        qDebug() << "Opcion no valida";
    }
    }
}

void Widget::on_punto2_clicked()
{
    punto = 2;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
    visible();
}

void Widget::on_punto3_clicked()
{
    punto = 3;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
    visible();
}

short Widget::getPunto() const
{
    return punto;
}

void Widget::stopOfensivo()
{
    ofensivo->stop();
}

void Widget::stopDefensivo()
{
    defensivo->stop();
}

void Widget::espiaDefensa()
{
    while (true) {
        double angle = 91 + rand() % (181-91);
        if(punto == 3){
            if(defensivo->SimularDispDefensivo(angle,ofensivo->getPosx(),ofensivo->getPosy(),ofensivo->getV_inicial(),ofensivo->getAngulo())){
                defensivo->generarDisparo();
                balas ++;
                break;
            }
        }
        else{
            if(defensivo->SimularDispDefensivo2(angle,ofensivo->getPosx(),ofensivo->getPosy(),ofensivo->getV_inicial(),ofensivo->getAngulo())){
                defensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
    timer->stop();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
    if(punto == 5){
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaAtaque()));
        timer->start(1000);
    }
}

void Widget::repetirDispDefensivo()
{
    defensivo->generarDisparo();
    balas++;
    timer->stop();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(repetirDispDefensivo()));
    if(punto == 5){
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaAtaque()));
        timer->start(1000);
    }
}

void Widget::espiaAtaque()
{
    for(int angle=probados;angle<90;angle++){
        if(ofensivo->simularDispApoyo(angle,defensivo->getPosx(),defensivo->getPosy(),defensivo->getV_inicial(),defensivo->getAngulo())){
            ofensivo->disparoApoyo();
            probados = ofensivo->anguloBalaApoyo()+1;
            break;
        }
    }
    timer->stop();
    disconnect(timer,SIGNAL(timeout()),this,SLOT(espiaAtaque()));
}

void Widget::on_punto4_clicked()
{
    punto = 4;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
    visible();
}

void Widget::on_punto5_clicked()
{
    punto = 5;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
    visible();
}

short Widget::getBalas() const
{
    return balas;
}
