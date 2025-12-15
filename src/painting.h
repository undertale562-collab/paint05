#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <QImage>

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
    // void drawLineTo(const QPoint& endPoint);
private:
    bool mousePressed;
    QString brushShape="rect";
    QString figure="";
    QPoint position={0,0};
    Stroke streak;
    QPainter* painter;
    // QImage image;
public slots:
    void BrushChanged(QString);
    void ShapeChanged(QString);
    void ColorChanged(QString);
};


