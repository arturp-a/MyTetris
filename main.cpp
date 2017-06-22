#include "tetriswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TetrisWidget w;
    w.show();

    return a.exec();
}
