#include "tetriswidget.h"

TetrisWidget::TetrisWidget(QWidget *parent)
    : QWidget(parent)
{    
    MainLayout = new QGridLayout;
    PlayBoard = new Board(this);
    MainLayout->addWidget(PlayBoard,0,0);
    setLayout(MainLayout);
}

TetrisWidget::~TetrisWidget()
{
    delete PlayBoard;
    delete MainLayout;
}
