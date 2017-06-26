#include "shape.h"

Shape::Shape()
    : ShapeMatrix(nullptr)
    , left(0)
    , top(0)
    , width(10)
    , height(10)
{

}

Square::Square()
    : RowCount(25)
    , ColCount(12)
{
    ShapeMatrix = new int *[RowCount];
    for (int i = 0; i< RowCount;i++) {
        ShapeMatrix[i] = new int[ColCount];
    }
    CreateShape();
}
void Square::CreateShape() {
    ShapeMatrix[0][0] = 0;
    ShapeMatrix[0][1] = 0;
    ShapeMatrix[0][2] = 0;
    ShapeMatrix[0][3] = 0;
    ShapeMatrix[0][4] = 0;
    ShapeMatrix[0][5] = 1;
    ShapeMatrix[0][6] = 0;

    ShapeMatrix[1][0] = 0;
    ShapeMatrix[1][1] = 0;
    ShapeMatrix[1][2] = 0;
    ShapeMatrix[1][3] = 0;
    ShapeMatrix[1][4] = 1;
    ShapeMatrix[1][5] = 1;
    ShapeMatrix[1][6] = 1;

    for (int i = 2; i < RowCount; i++) {
        for (int j=0; j < ColCount; j++) {
           ShapeMatrix[i][j] = 0;
        }
    }
}

void Square::MoveShapeDown(int row1, int row2) {
    for (int ia = 0; ia< ColCount; ia++) {
        if (row1 <=RowCount && row2 <= RowCount-1) {
            int temp;
            temp = ShapeMatrix[row1][ia];
            ShapeMatrix[row1][ia] = ShapeMatrix[row2][ia];
            ShapeMatrix[row2][ia] = temp;
        } else {
            return;
        }
    }
}
void Square::MoveShapeLeft(int col1, int col2) {
    for (int ia = 0; ia< RowCount; ia++) {
        if (col1 >= 0 && col2 <= ColCount) {
            int temp;
            temp = ShapeMatrix[ia][col1];
            ShapeMatrix[ia][col1] = ShapeMatrix[ia][col2];
            ShapeMatrix[ia][col2] = temp;
        } else {
            return;
        }
    }
}
void Square::MoveShapeRight(int col1, int col2) {
    for (int ia = 0; ia< RowCount; ia++) {
        if (col1 >= 0 && col2 <= ColCount) {
            int temp;
            temp = ShapeMatrix[ia][col1];
            ShapeMatrix[ia][col1] = ShapeMatrix[ia][col2];
            ShapeMatrix[ia][col2] = temp;
        } else {
            return;
        }
    }
}
void Square::RotateShape() {
    int rows =RowCount;
    int col = ColCount;
    int temp;


    for (int i = 0; i < rows; i++)
        {
            for (int j = i + 1; j < col; j++)
            {
                temp = ShapeMatrix[i][j];
                ShapeMatrix[i][j] = ShapeMatrix[j][i];
                ShapeMatrix[j][i] = temp;
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col / 2; j++)
            {
                temp = ShapeMatrix[i][j];
                ShapeMatrix[i][j] = ShapeMatrix[i][col - 1 - j];
                ShapeMatrix[i][col - 1 - j] = temp;
            }
        }
    PrintMatrix();
}

void Square::PrintMatrix() {
    QDebug dbg(QtDebugMsg);
    dbg << "\n";
    for(int i=0;i<RowCount;i++)
        {
            for(int j=0;j<ColCount;j++)
            {
                dbg <<ShapeMatrix[i][j] << " ";
            }
        dbg << "\n";
   }
}

void Square::DrowShape(QWidget *WidgetToPaint, int left,int top, int width, int height){
    QPainter painter(WidgetToPaint);
    QRect r1;
    QBrush Brush(Qt::blue,Qt::SolidPattern);
    r1.setRect(left, top, width, height);
    painter.setPen(Qt::blue);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            qDebug() << ShapeMatrix[i][j];
            if (ShapeMatrix[i][j] == 1){

                //painter.fillRect(r1,Brush);
                painter.drawRect(r1);
            } else {
                painter.save();
                painter.restore();
                painter.drawRect(r1);
            }
        }
        qDebug() << "\n";
    }

}


BasicCube::BasicCube(){

}

BasicCube::BasicCube(QWidget *WidgetToPaint) {
    QPainter painter(WidgetToPaint);
//    left = 50;
//    top = 50;
//    width = 100;
//    height = 125;
    QRect r1;
    //QRect r2(QPoint(left, top), QSize(width, height));
    r1.setRect(left, top, width, height);
    painter.setPen(Qt::red);
    painter.drawRect(r1);
}

void BasicCube::DrowShape(QWidget *WidgetToPaint, int left, int top, int width, int height){
    QPainter painter(WidgetToPaint);
//    int left = 50;
//    int top = 50;
//    int width = 100;
//    int height = 125;
    QRect r1;
    //QRect r2(QPoint(left, top), QSize(width, height));
    r1.setRect(left, top, width, height);
    painter.setPen(Qt::blue);
    painter.drawRect(r1);

}

