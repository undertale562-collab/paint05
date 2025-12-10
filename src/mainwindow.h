#include <QWidget>
#include "painting.h"
#include "toolbar.h"
#pragma once

class MainWindow: public QWidget{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
private:
    Painting* canvas;
    ToolBar* tools;
};
