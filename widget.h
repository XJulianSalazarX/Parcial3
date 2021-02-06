#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "canon.h"
#include "canonofensivo.h"
#include "canondefensivo.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void visible();
    void invisible();
    void nextVisible();
    void mostrarDatos();
    void agregarTexto(QString datos);
    void quitarPortal();

    short getPunto() const;
    void stopOfensivo();
    void stopDefensivo();

private slots:
    void on_iniciar_clicked();

    void on_punto1_clicked();

    void on_next_clicked();

    void on_punto2_clicked();

    void on_punto3_clicked();

    void on_punto4_clicked();

    void on_punto5_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    CanonOfensivo *ofensivo;
    CanonDefensivo *defensivo;
    short punto,balas;
    QTimer *timer;
    int probados;

public slots:
    void espiaDefensa();
    void repetirDispDefensivo();
    void espiaAtaque();
};
#endif // WIDGET_H
