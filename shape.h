#ifndef SHAPE_H
#define SHAPE_H
#include <QPoint>
#include <QPainter>
#include <QWidget>
#include <QRect>
class Shape
{
public:
    Shape();
    virtual void CreateShape()=0;
    virtual void DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height)=0;
public:
    int **ShapeMatrix;
};

class Square :public Shape {
public:
    Square();
    void CreateShape();
    void DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height);
private:
    QPoint X;
    QPoint Y;
};

class BasicCube {
public:
    BasicCube();
    void DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height);
};

#endif // SHAPE_H
