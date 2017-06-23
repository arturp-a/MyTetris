#include "shape.h"

Shape::Shape()
    : ShapeMatrix(nullptr)
{

}

Square::Square() {
    ShapeMatrix = new int *[3];
    for (int i = 0; i< 3;i++) {
        ShapeMatrix[i] = new int[3];
    }
    CreateShape();
}
void Square::CreateShape() {
    ShapeMatrix[0][0] = 0;
    ShapeMatrix[0][1] = 1;
    ShapeMatrix[0][2] = 0;

    ShapeMatrix[1][0] = 1;
    ShapeMatrix[1][1] = 1;
    ShapeMatrix[1][2] = 1;

    ShapeMatrix[2][0] = 0;
    ShapeMatrix[2][1] = 0;
    ShapeMatrix[2][2] = 0;
}
BasicCube::BasicCube() {

}

void BasicCube::DrowShape(QWidget *WidgetToPaint, int left, int top, int width, int height){
//    QPainter painter(WidgetToPaint);
////    int left = 50;
////    int top = 50;
////    int width = 100;
////    int height = 125;
//    QRect r1;
//    //QRect r2(QPoint(left, top), QSize(width, height));
//    r1.setRect(left, top, width, height);
//    painter.setPen(Qt::blue);
//    painter.drawRect(r1);

}

void Square::DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height){
    QPainter painter(WidgetToPaint);
//    int left = 50;
//    int top = 50;
//    int width = 100;
//    int height = 125;
    QRect r1;
    //QRect r2(QPoint(left, top), QSize(width, height));
    r1.setRect(left, top, width, height);
    painter.setPen(Qt::blue);
    painter.drawRect(r1); // r1 as a bounding box

//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; i < 3; j++) {
//            if (ShapeMatrix[i][j] == 1) {
//                //painter
//            }
//        }
//    }


}
