#include "widget.h"

#include <QApplication>

Widget *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new Widget();
    w->show();
    return a.exec();
}
