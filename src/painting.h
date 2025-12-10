#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#pragma once

struct Stroke{
    QSize strokeSize{50,50};
    QColor strokeColor{0, 191, 255};
};

class Painting: public QWidget{
    Q_OBJECT
public:
    Painting();
    ~Painting();
protected:
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
private:
    bool mousePressed;
    QPoint position={0,0};
    QSize widgetSize;
    Stroke streak;
};
