#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow():
    canvas(new Painting()),
    tools(new ToolBar){
    QHBoxLayout* Hlay=new QHBoxLayout(this);
    QVBoxLayout* Vlay=new QVBoxLayout(this);

    canvas->setFixedSize(width(), height());
    tools->setFixedSize(tools->size());
    this->setLayout(Vlay);

    Hlay->addWidget(tools);
    Hlay->addWidget(canvas);
    Vlay->addLayout(Hlay);

    connect(tools, &ToolBar::ShapeClicked, canvas, &Painting::ShapeChanged);
    connect(tools, &ToolBar::BrushClicked, canvas, &Painting::BrushChanged);
    connect(tools, &ToolBar::ColorClicked, canvas, &Painting::ColorChanged);
    connect(tools, &ToolBar::SizeClicked, canvas, &Painting::SizeChanged);
    connect(tools, &ToolBar::ClearClicked, canvas, &Painting::Desintegrate);
}

MainWindow::~MainWindow(){

}
