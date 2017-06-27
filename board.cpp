#include "board.h"
#include <QDebug>
Board::Board()
{

}

Board::Board(QWidget *parent)
    : RowCount(0)
    , ColCount(0)
    , Height(0)
    , Width(0)
    , FirstRowToChange(0)
    , SecondRowToChange(0)
    , FirstColToChange(0)
    , SecondColToChange(0)
    , IsShapeOnBottom(false)
{
    Q_UNUSED(parent)

    setFocusPolicy(Qt::StrongFocus);
    BoardLayout = new QGridLayout();
    this->setBackgroundRole(QPalette::Base);
    this->setStyleSheet("background-color:gray;");
    Height = GetWidgetHeight();
    Width = GetWidgetWidth();
    RowCount = 25;
    ColCount = 12;
    WidgetMatrix = new int *[RowCount];
    for (int i(0); i<RowCount; i++) {
        WidgetMatrix[i] = new int [ColCount];
    }
    //Set the timer
    Timer = new QBasicTimer;
    Timer->start(timeoutTime(), this);
    // Create the emply board
    SetBoard(RowCount,ColCount);

    setRandomShape();



}
Board::~Board(){
    for( int i = 0 ; i < RowCount ; i++ )   {
        delete [] WidgetMatrix[i] ;
    }
    delete [] WidgetMatrix;
}

void Board::setRandomShape()
{
    //CreateRandomShape(TetrixShape(qrand() % 7 + 1));
    CreateRandomShape(TetrixShape(0));
}

Shape* Board::CreateRandomShape(TetrixShape ShapeFromEnum) {
    switch (ShapeFromEnum) {
    case TShape:
        MySquare = new Square;
        SetShape(MySquare);

        qDebug() << "asdasd";
        MySquare->PrintMatrix();
        return MySquare;
        break;
    default:
        break;
    }
}

bool Board::SetBoard(const unsigned int RowCountToCreate, const unsigned int ColCountToCreate) {
    for (unsigned int i = 0; i < RowCountToCreate; i++) {
        for(unsigned int j = 0; j < ColCountToCreate; j++) {
            WidgetMatrix[i][j] = 0;
        }
    }
    qDebug() << "start Matrix";
    PrintMatrix(RowCountToCreate,ColCountToCreate);
    return true;
}

void Board::PrintMatrix(int row, int col){
    QDebug dbg(QtDebugMsg);
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                dbg <<WidgetMatrix[i][j] << " ";
            }
        dbg << "\n";
   }
    dbg << "\n";
}


int Board::GetWidgetHeight() {
    return this->size().height();
}
int Board::GetWidgetWidth() {
    return this->size().width();
}
void Board::DrowMatrix(QWidget *WidgetToPaint, int i,int j) {
    QSize Sz = this->size();
    int width = Sz.width()/ColCount;
    int height = Sz.height()/RowCount;
    QPainter painter(WidgetToPaint);
    QRect r1;
    r1.setRect(j*width, i*height, width, height);
    QPen oPen = painter.pen();
    QBrush Brush(Qt::SolidPattern);
    if (WidgetMatrix[i][j] == 1) {
        oPen.setColor(Qt::black);
        Brush.setColor(Qt::blue);
        painter.setBrush(Brush);
        painter.setPen(oPen);
        painter.drawRect(r1);
    } else {
        oPen.setColor(Qt::black);
        Brush.setColor(Qt::red);
        painter.setBrush(Brush);
        painter.setPen(oPen);
        painter.drawRect(r1);
    }
}

void Board::paintEvent(QPaintEvent *event) {

    for (int i = 0; i < RowCount; i++) {
        for(int j = 0; j < ColCount; j++) {
            this->DrowMatrix(this,i,j);
        }
    }

}

void Board::timerEvent(QTimerEvent *event)
{
    OneStepDown();
}

void Board::keyPressEvent(QKeyEvent *event) {
    if(event->key() == Qt::Key_Right) {
        OneStepRight();
    } else if(event->key() == Qt::Key_Left) {
        OneStepLeft();
    } else if (event->key() == Qt::Key_Up) {
        RotateShapeInBoard();
    } else if (event->key() == Qt::Key_Down) {
        OneStepDown();
    }
}

void Board::SetShape(Shape *MyShape) {
    for(int i = 0; i < RowCount; ++i)
        for(int j = 0; j < ColCount; ++j)
            WidgetMatrix[i][j] = WidgetMatrix[i][j] + MyShape->ShapeMatrix[i][j];
    qDebug() << "MainMatrix";
    PrintMatrix(RowCount,ColCount);
}

void Board::OneStepDown() {
    if(FirstRowToChange+3 <=RowCount && SecondRowToChange+3 <=RowCount) {
        FirstRowToChange += 1;
        SecondRowToChange += 1;
        MySquare->MoveShapeDown(FirstRowToChange+1,SecondRowToChange);
        MySquare->MoveShapeDown(FirstRowToChange+1-1,SecondRowToChange-1);
        SetBoard(RowCount,ColCount);
        SetShape(MySquare);
        repaint();
    } else {
        IsShapeOnBottom = true;
        FirstColToChange=0;
        SecondColToChange=0;
        FirstRowToChange=0;
        SecondRowToChange=0;
        setRandomShape();
    }
}

void Board::OneStepLeft() {
    if(FirstColToChange >= -3 && SecondColToChange <= ColCount && IsShapeOnBottom == false) {
        FirstColToChange -= 1;
        SecondColToChange -= 1;
        MySquare->MoveShapeLeft(FirstColToChange+4,SecondColToChange+5);
        MySquare->MoveShapeLeft(FirstColToChange+5,SecondColToChange+6);
        MySquare->MoveShapeLeft(FirstColToChange+6,SecondColToChange+7);
        SetBoard(RowCount,ColCount);
        SetShape(MySquare);
        repaint();
    } else {

        //to do
    }
}
void Board::OneStepRight() {
    if(FirstColToChange >= -4 && SecondColToChange < 5 && IsShapeOnBottom == false) {
        FirstColToChange += 1;
        SecondColToChange += 1;
        MySquare->MoveShapeRight(FirstColToChange+6,SecondColToChange+5);
        MySquare->MoveShapeRight(FirstColToChange+5,SecondColToChange+4);
        MySquare->MoveShapeRight(FirstColToChange+4,SecondColToChange+3);
        SetBoard(RowCount,ColCount);
        SetShape(MySquare);
        repaint();
    } else {
        //to do
    }
}

void Board::RotateShapeInBoard() {
    //MySquare->RotateShape();
}



