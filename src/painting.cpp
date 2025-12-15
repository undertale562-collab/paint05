#include "painting.h"
#include <QHBoxLayout>

Painting::Painting(){
    mousePressed=false;

}

Painting::~Painting(){

}

// вот здесь то, что писал я


void Painting::mouseMoveEvent(QMouseEvent* event){
    position=event->pos();
    update();
}

void Painting::mousePressEvent(QMouseEvent* event){
    mousePressed=true;
}


void Painting::mouseReleaseEvent(QMouseEvent*){
    mousePressed=false;
}

void Painting::paintEvent(QPaintEvent*){
    painter=new QPainter(this);
    if(mousePressed){
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
    }
    painter->end();
}

void Painting::ShapeChanged(QString modifier){
    if(modifier=="Rect"){
        figure="rect";
    }
    else if(modifier=="Circ"){
        figure="circ";
    }
    brushShape="";
}

void Painting::BrushChanged(QString modifier){
    if(modifier=="RectB"){
        brushShape="rect";
    }
    else if(modifier=="CircB"){
        brushShape="circ";
    }
    figure="";
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


// void Painting::mousePressEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton) {
//         position = event->pos();
//         mousePressed = true;
//     }
// }

// // When the mouse moves if the left button is clicked
// // we call the drawline function which draws a line
// // from the last position to the current
// void Painting::mouseMoveEvent(QMouseEvent *event)
// {
//     if ((event->buttons() & Qt::LeftButton) && mousePressed)
//         drawLineTo(event->pos());
// }

// // If the button is released we set variables to stop drawing
// void Painting::mouseReleaseEvent(QMouseEvent *event)
// {
//     if (event->button() == Qt::LeftButton && mousePressed) {
//         drawLineTo(event->pos());
//         mousePressed = false;
//     }
// }

// // QPainter provides functions to draw on the widget
// // The QPaintEvent is sent to widgets that need to
// // update themselves
// void Painting::paintEvent(QPaintEvent *event)
// {
//     QPainter painter(this);

//     // Returns the rectangle that needs to be updated
//     QRect dirtyRect = event->rect();

//     // Draws the rectangle where the image needs to
//     // be updated
//     painter.drawImage(dirtyRect, image, dirtyRect);
// }

// void Painting::drawLineTo(const QPoint &endPoint){
//     // Used to draw on the widget
//     QPainter painter(&image);

//     // Set the current settings for the pen
//     painter.setPen(QPen(streak.strokeColor, 30, Qt::SolidLine, Qt::RoundCap,
//                         Qt::RoundJoin));

//     // Draw a line from the last registered point to the current
//     painter.drawLine(position, endPoint);

//     int rad = (30 / 2) + 2;

//     // Call to update the rectangular space where we drew
//     update(QRect(position, endPoint).normalized()
//                .adjusted(-rad, -rad, +rad, +rad));

//     // Update the last position where we left off drawing
//     position = endPoint;
// }



