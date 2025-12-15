#include "painting.h"
#include <QHBoxLayout>

Painting::Painting(){
    mousePressed=false;

}

Painting::~Painting(){

}

void Painting::mouseMoveEvent(QMouseEvent* event){
    if(streak.erase){
        for(int i=0; i<massive.size(); i++){
            if(event->pos().x()+massive[i].size.width()/2 > massive[i].thisonePosition.x() &&
                event->pos().x()+massive[i].size.width()/2 < massive[i].thisonePosition.x()+massive[i].size.width() &&
                event->pos().y()+massive[i].size.height()/2 > massive[i].thisonePosition.y() &&
                event->pos().y()+massive[i].size.height()/2 < massive[i].thisonePosition.y()+massive[i].size.height()){
                massive.erase(massive.begin()+i);
                update();
            }
        }
    }
    else{
        Thisone piece;
        piece.thisonePosition=event->pos();
        piece.color=streak.strokeColor;
        piece.size=streak.strokeSize;
        piece.shapeB=brushShape;
        massive.push_back(piece);
        update();
    }
}

void Painting::mousePressEvent(QMouseEvent* event){
    if(streak.erase){
        for(int i=0; i<massive.size(); i++){
            if(event->pos().x()+massive[i].size.width()/2 > massive[i].thisonePosition.x() &&
                event->pos().x()+massive[i].size.width()/2 < massive[i].thisonePosition.x()+massive[i].size.width() &&
                event->pos().y()+massive[i].size.height()/2 > massive[i].thisonePosition.y() &&
                event->pos().y()+massive[i].size.height()/2 < massive[i].thisonePosition.y()+massive[i].size.height()){
                massive.erase(massive.begin()+i);
                update();
            }
        }
    }
    else{
        Thisone piece;
        piece.thisonePosition=event->pos();
        piece.color=streak.strokeColor;
        piece.size=streak.strokeSize;
        piece.shapeB=brushShape;
        massive.push_back(piece);
        update();
    }
}


void Painting::mouseReleaseEvent(QMouseEvent*){
    mousePressed=false;
}

void Painting::paintEvent(QPaintEvent*){
    painter=new QPainter(this);
    painter->setPen(Qt::NoPen);
    QBrush brush;
    QPen pen;
    pen.setStyle(Qt::NoPen);
    brush.setStyle(Qt::SolidPattern);
    for (int i=0; i<massive.size(); i++){
        pen.setColor(massive[i].color);
        brush.setColor(massive[i].color);
        painter->setBrush(brush);
        if(massive[i].shapeB=="rect"){
            pen.setStyle(Qt::SolidLine);
            painter->setPen(pen);
            painter->setBrush(Qt::NoBrush);
            painter->drawRect(massive[i].thisonePosition.x()-massive[i].size.width()/2,
                              massive[i].thisonePosition.y()-massive[i].size.height()/2, massive[i].size.width(), massive[i].size.height());
        }
        if(massive[i].shapeB=="circ"){
            pen.setStyle(Qt::SolidLine);
            painter->setPen(pen);
            painter->setBrush(Qt::NoBrush);
            painter->drawEllipse(massive[i].thisonePosition.x()-massive[i].size.width()/2,
                              massive[i].thisonePosition.y()-massive[i].size.height()/2, massive[i].size.width(), massive[i].size.height());
        }
        else if(massive[i].shapeB=="rectB"){
            painter->drawRect(massive[i].thisonePosition.x()-massive[i].size.width()/2,
                              massive[i].thisonePosition.y()-massive[i].size.height()/2, massive[i].size.width(), massive[i].size.height());
        }
        else if(massive[i].shapeB=="circB"){
            painter->drawEllipse(massive[i].thisonePosition.x()-massive[i].size.width()/2,
                                 massive[i].thisonePosition.y()-massive[i].size.height()/2, massive[i].size.width(), massive[i].size.height());
        }
    }
    painter->end();
}

void Painting::ShapeChanged(QString modifier){
    streak.erase=false;
    if(modifier=="Rect"){
        brushShape="rect";
    }
    else if(modifier=="Circ"){
        brushShape="circ";
    }
}

void Painting::BrushChanged(QString modifier){
    streak.erase=false;
    if(modifier=="RectB"){
        brushShape="rectB";
    }
    else if(modifier=="CircB"){
        brushShape="circB";
    };
}


void Painting::ColorChanged(QString modifier){
    if(modifier=="Red"){
        streak.strokeColor={255,0,0};
    }
    else if(modifier=="Blue"){
        streak.strokeColor={0,0,255};
    }
    else if(modifier=="Green"){
        streak.strokeColor={0,255,0};
    }
    else if(modifier=="Yellow"){
        streak.strokeColor={255,255,0};
    }
    else if(modifier=="Black"){
        streak.strokeColor={0,0,0};
    }
    else if(modifier=="White"){
        streak.strokeColor={255,255,255};
    }
}

void Painting::SizeChanged(QString modifier){
    if(modifier=="Thicker"){
        if(streak.strokeSize.width()==1){
            streak.strokeSize={10, streak.strokeSize.height()};
        }
        else{
            streak.strokeSize={streak.strokeSize.width()+10, streak.strokeSize.height()};
        }
    }
    else if(modifier=="Thinner"){
        if(streak.strokeSize.width()<=0){
            streak.strokeSize={1, streak.strokeSize.height()};
        }
        else{
            streak.strokeSize={streak.strokeSize.width()-10, streak.strokeSize.height()};
        }
    }
    if(modifier=="Higher"){
        if(streak.strokeSize.width()==1){
            streak.strokeSize={streak.strokeSize.width(), 1};
        }
        else{
            streak.strokeSize={streak.strokeSize.width(), streak.strokeSize.height()+10};
        }
    }
    else if(modifier=="Lower"){
        streak.strokeSize={streak.strokeSize.width(), streak.strokeSize.height()-10};
        if(streak.strokeSize.height()<=0){
            streak.strokeSize={streak.strokeSize.height(), 1};
        }
    }
}

void Painting::Desintegrate(QString modifier){
    if(modifier=="Clear"){
        massive={};
        update();
    }
    else if(modifier=="Eraser"){
        streak.erase=true;
    }
}

