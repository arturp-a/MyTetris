#ifndef SHAPE_H
#define SHAPE_H
#include <QPoint>
#include <QPainter>
#include <QWidget>
#include <QRect>
#include <QDebug>

//enum TetrixShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape, LShape, MirroredLShape };
enum TetrixShape {TShape};

class Shape
{
public:
    Shape();
    virtual void CreateShape()=0;
    virtual void MoveShapeDown(int row1, int row2)=0;
    virtual void MoveShapeLeft(int col1, int col2)=0;
    virtual void MoveShapeRight(int col1, int col2)=0;
    virtual void RotateShape()=0;
    virtual void PrintMatrix()=0;
    virtual void DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height)=0;
public:
    int **ShapeMatrix;
    QWidget *WidgetToPaint;
    int left;
    int top;
    int width;
    int height;
};

class Square : public Shape {
public:
    Square();
    void CreateShape();
    void MoveShapeDown(int row1, int row2);
    void MoveShapeLeft(int col1, int col2);
    void MoveShapeRight(int col1, int col2);
    void RotateShape();
    void DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height);
public:
    void PrintMatrix();
public:
    int RowCount;
    int ColCount;
};

class BasicCube: public Square {
public:
    BasicCube();
    BasicCube(QWidget *WidgetToPaint);
    void DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height);
};

#endif // SHAPE_H
