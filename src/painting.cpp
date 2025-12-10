#include "painting.h"

Painting::Painting(){

}

Painting::~Painting(){

}

void Painting::mouseMoveEvent(QMouseEvent* event){
    if(mousePressed){
        position=event->pos();
    }
}

void Painting::mousePressEvent(QMouseEvent*){
    mousePressed=true;
}


void Painting::mouseReleaseEvent(QMouseEvent*){
    mousePressed=false;
}

void Painting::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QBrush brush(Qt::SolidPattern);
    brush.setColor(streak.strokeColor);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRect(300, 200, streak.strokeSize.width(), streak.strokeSize.height());
}

