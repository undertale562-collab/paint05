#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <QPixmap>
#include <QLabel>

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
    QString brushShape="rect";
    QString figure="";
    QPoint position={0,0};
    QSize widgetSize={200,200};
    Stroke streak;
    QPainter* painter;
    // QPixmap canvas;
    // QLabel* desk;
public slots:
    void BrushChanged(QString);
    void ShapeChanged(QString);
    void ColorChanged(QString);
};

