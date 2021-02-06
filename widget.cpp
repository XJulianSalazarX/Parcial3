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
    switch (punto) {
    case 1:{
        ui->label->setText(ui->label->text()+datos+"Coordenadas del objetivo: (");
        ui->label->setText(ui->label->text()+QString::number(defensivo->getPosx())+", "+QString::number(defensivo->getPosy())+")\n");
    }
        break;
    case 2:{
        ui->label->setText(ui->label->text()+datos+"Coordenadas del objetivo: (");
        ui->label->setText(ui->label->text()+QString::number(ofensivo->getPosx())+", "+QString::number(ofensivo->getPosy())+")\n");
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
        break;
    }
}

void Widget::quitarPortal()
{
    ofensivo->portalInvisible();
    defensivo->portalInvisible();
}

void Widget::on_iniciar_clicked()
{
    ui->iniciar->setVisible(false);
    switch (punto) {
    case 1:{
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ui->label->setText("Simulacion "+QString::number(balas+1)+"\n");
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
                ui->label->setText("Simulacion "+QString::number(balas+1)+"\n");
                defensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
        break;
    case 3:{
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                balas ++;
                break;
            }
        }
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 4:{
        while (true) {
            double angle = rand() % 90;
            if(ofensivo->disparar(defensivo->getPosx(),defensivo->getPosy(),angle)){
                ofensivo->generarDisparo();
                balas ++;
                break;
            }
        }
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 5:{

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
                ui->label->setText(ui->label->text()+"Simulacion "+QString::number(balas+1)+"\n");
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
                ui->label->setText(ui->label->text()+"Simulacion "+QString::number(balas+1)+"\n");
                defensivo->generarDisparo();
                balas ++;
                break;
            }
        }
    }
        break;
    case 3:{
        ofensivo->generarDisparo();
        balas ++;
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
    }
        break;
    case 4:{
        ofensivo->generarDisparo();
        balas ++;
        connect(timer,SIGNAL(timeout()),this,SLOT(espiaDefensa()));
        timer->start(2000);
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

void Widget::on_punto2_clicked()
{
    punto = 2;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
}

void Widget::on_punto3_clicked()
{
    punto = 3;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
}

short Widget::getPunto() const
{
    return punto;
}

void Widget::stopOfensivo()
{
    ofensivo->stop();
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
}

void Widget::on_punto4_clicked()
{
    punto = 4;
    ui->splitter->setVisible(false);
    ui->iniciar->setVisible(true);
}
