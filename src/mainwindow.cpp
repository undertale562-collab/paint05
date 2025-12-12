#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow():
    canvas(new Painting()),
    tools(new ToolBar){
    QHBoxLayout* Hlay=new QHBoxLayout(this);
    QVBoxLayout* Vlay=new QVBoxLayout(this);

    canvas->setFixedSize(height(),tools->height());
    tools->setFixedSize(tools->size());
    this->setLayout(Vlay);
    Hlay->addWidget(tools);
    Hlay->addWidget(canvas);
    Vlay->addLayout(Hlay);

    connect(tools, &ToolBar::ShapeClicked, canvas, &Painting::ShapeChanged);
    connect(tools, &ToolBar::BrushClicked, canvas, &Painting::BrushChanged);
    connect(tools, &ToolBar::ColorClicked, canvas, &Painting::ColorChanged);
}

MainWindow::~MainWindow(){

}
