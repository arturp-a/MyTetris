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
#include <QBasicTimer>
#include <QKeyEvent>
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

    int timeoutTime() {
        return 1000 / (1 + 0);// to be added level
    }
public:
    void OneStepDown();
    void OneStepLeft();
    void OneStepRight();
    void RotateShapeInBoard();
protected:
    int GetWidgetWidth();
    int GetWidgetHeight();
    bool SetBoard(const unsigned int,const unsigned int);
    void DrowMatrix(QWidget *, int i,int j);
    void PrintMatrix();
    void SetShape();
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
private:
    QBasicTimer *Timer;
    int **WidgetMatrix;
    int RowCount;
    int ColCount;
    int Height;
    int Width;
    int Level;
    Square *MySquare;
    QGridLayout *BoardLayout;
    QPen pen;
    QBrush brush;
    int FirstRowToChange;
    int SecondRowToChange;
    int FirstColToChange;
    int SecondColToChange;
    bool IsShapeOnBottom;
    
};

#endif // BOARD_H
