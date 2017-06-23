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
{
    Q_UNUSED(parent)
    BoardLayout = new QGridLayout();
    this->setBackgroundRole(QPalette::Base);
    this->setStyleSheet("background-color:gray;");
    Height = GetWidgetHeight();
    Width = GetWidgetWidth();
    RowCount = 25;
    ColCount = 9;
    WidgetMatrix = new int *[RowCount];
    for (int i(0); i<RowCount; i++) {
        WidgetMatrix[i] = new int [ColCount];
    }
    SetBoard(RowCount,ColCount);
}
Board::~Board(){
    for( int i = 0 ; i < RowCount ; i++ )   {
        delete [] WidgetMatrix[i] ;
    }
    delete [] WidgetMatrix;
}


bool Board::SetBoard(const unsigned int RowCountToCreate, const unsigned int ColCountToCreate) {
    for (unsigned int i = 0; i < RowCountToCreate; i++) {
        for(unsigned int j = 0; j < ColCountToCreate; j++) {
            WidgetMatrix[i][j] = 0;
        }
    }
    return true;
}


int Board::GetWidgetHeight() {
    return this->size().height();
}
int Board::GetWidgetWidth() {
    return this->size().width();
}
void Board::DrowMatrix(QWidget *WidgetToPaint, int left,int top, int width, int height) {
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

void Board::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    for (int i = 0; i < RowCount; i++) {
        for(int j = 0; j < ColCount; j++) {
            //BasicCube *label = new BasicCube;
            QLabel *label = new QLabel(QString("label %1").arg(i * ColCount + j + 1));
            BoardLayout->addWidget(label, i, j);
            this->setLayout(BoardLayout);
            //cub->DrowShape(this,i,j,10,10);
        }
    }
}
