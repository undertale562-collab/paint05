#include <QWidget>
#pragma once

class ToolBar : public QWidget
{
    Q_OBJECT
public:
    ToolBar();
    ~ToolBar();
signals:
    void ShapeClicked();
    void BrushClicked();
};

