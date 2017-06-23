#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "shape.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
class Board  : public QWidget
{
public:
    Board();
    Board(QWidget *parent = 0);
    ~Board();
    QLabel* label(int row, int column) const
    {
        return qobject_cast<QLabel*>(BoardLayout->itemAtPosition(row, column)->widget());
    }
protected:
    int GetWidgetWidth();
    int GetWidgetHeight();
    bool SetBoard(const unsigned int,const unsigned int);
    void DrowMatrix(QWidget *, int,int, int, int);
protected:
    void paintEvent(QPaintEvent *event);
private:
    enum { BoardWidth = 10, BoardHeight = 22 };
    //Shape shape[]
    int **WidgetMatrix;
    int RowCount;
    int ColCount;
    int Height;
    int Width;
    Square aa;
    QGridLayout *BoardLayout;

    
};

#endif // BOARD_H
