#ifndef TETRISWIDGET_H
#define TETRISWIDGET_H

#include <QWidget>
#include "board.h"
#include <QGridLayout>
class TetrisWidget : public QWidget
{
    Q_OBJECT

public:
    TetrisWidget(QWidget *parent = 0);
    ~TetrisWidget();
private:
    Board *PlayBoard;
    QGridLayout *MainLayout;
};

#endif // TETRISWIDGET_H
