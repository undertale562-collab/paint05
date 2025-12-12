#include "painting.h"
#include <QHBoxLayout>

Painting::Painting(){
    mousePressed=false;
    // QHBoxLayout* base=new QHBoxLayout;
    // desk=new QLabel;
    // canvas.scaled(widgetSize);
    // desk->setPixmap(canvas);
    // base->addWidget(desk);
    // this->setLayout(base);
}

Painting::~Painting(){

}

void Painting::mouseMoveEvent(QMouseEvent* event){
    position=event->pos();
    update();
}

void Painting::mousePressEvent(QMouseEvent*){
    mousePressed=true;
}


void Painting::mouseReleaseEvent(QMouseEvent*){
    mousePressed=false;
}

void Painting::paintEvent(QPaintEvent*){
    if(mousePressed){
        painter=new QPainter(this);
        QBrush brush;
        brush.setColor(streak.strokeColor);

        if(figure==""){
            brush.setStyle(Qt::SolidPattern);
        }
        else{
            brush.setStyle(Qt::NoBrush);
            painter->setPen(Qt::SolidLine);

            if(figure=="rect"){
            }
            else{

            }
            painter->end();
        }

        painter->setPen(Qt::NoPen);
        painter->setBrush(brush);
        if(brushShape=="rect"){
            painter->drawRect(position.x()-streak.strokeSize.width()/2, position.y()-streak.strokeSize.height()/2,
                              streak.strokeSize.width(), streak.strokeSize.height());
        }
        else if(brushShape=="circ"){
            painter->drawEllipse(position.x()-streak.strokeSize.width()/2, position.y()-streak.strokeSize.height()/2,
                                 streak.strokeSize.width(), streak.strokeSize.height());
        }
        painter->end();
    }
}

void Painting::BrushChanged(QString modifier){
    if(modifier=="RectB"){
        brushShape="rect";
    }
    else if(modifier=="CircB"){
        brushShape="circ";
    }
}

void Painting::ShapeChanged(QString modifier){
    if(modifier=="Rect"){
        figure="rect";
    }
    else if(modifier=="Circ"){
        figure="circ";
    }
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



