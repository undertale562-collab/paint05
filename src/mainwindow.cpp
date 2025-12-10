#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow():
    canvas(new Painting()),
    tools(new ToolBar){
    QHBoxLayout* mainHlay=new QHBoxLayout(this);
    QVBoxLayout* rightVlay=new QVBoxLayout(this);

    canvas->setFixedSize(800,tools->height());

    this->setLayout(mainHlay);
    rightVlay->addWidget(tools);
    rightVlay->addWidget(canvas);
    mainHlay->addLayout(rightVlay);
}

MainWindow::~MainWindow(){

}

// this->setLayout(mainHlay);

// currentexpression->setReadOnly(true);

// rightVlay->addWidget(currentexpression);
// rightVlay->addWidget(calcWidget);

// mainHlay->addWidget(historywidget);
// mainHlay->addLayout(rightVlay);

// const QSize calcSize=calcWidget->size();
// const QSize expressionsize(calcWidget->width(), 40);
// const QSize historysize(calcWidget->width(), calcWidget->height()+40);
// const QSize mainsize(2*calcWidget->width()+60, historysize.height()+20);

// setFixedSize(mainsize);
// calcWidget->setFixedSize(calcSize);
// currentexpression->setFixedSize(expressionsize);
// historywidget->setFixedSize(historysize);
