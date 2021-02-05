#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "canon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_iniciar_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Canon *canon;
    Canon *canon2;
};
#endif // WIDGET_H
