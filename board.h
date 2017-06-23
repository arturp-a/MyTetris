#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "shape.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include <QBrush>
#include <QPen>
#include <QPixmap>
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
    int **WidgetMatrix;
    int RowCount;
    int ColCount;
    int Height;
    int Width;
    Square aa;
    QGridLayout *BoardLayout;
    QPen pen;
    QBrush brush;

    
};

#endif // BOARD_H
