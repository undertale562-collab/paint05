#include "toolbar.h"
#include "painting.h"
#include <QGridLayout>
#include <QPushButton>

ToolBar::ToolBar(){
    const  QSize buttonsize={80, 40};
    QVector <QString> texts={"Rect", "Circ", "RectB", "CircB", "Red", "Blue", "Green", "Yellow", "Black", "White"};
    const QSize widgetsize(200,300);

    QGridLayout* mainLay=new QGridLayout();

    setLayout(mainLay);
    setFixedSize(widgetsize);
    for (int i=0; i<5; i++){
        for (int k=0; k<2; k++){
            QPushButton* button = new QPushButton(texts.takeFirst(), this);
            button->setFixedSize(buttonsize);
            mainLay->addWidget(button, i, k);
        }
    }
}

ToolBar::~ToolBar(){

}

// void ToolBar::ShapeClicked(){

// }

// void ToolBar::BrushClicked(){

// }
