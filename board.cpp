#include "board.h"

Board::Board()
{

}

Board::Board(QWidget *parent)
{
    this->setBackgroundRole(QPalette::Base);
    this->setStyleSheet("background-color:gray;");
}
