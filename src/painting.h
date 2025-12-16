#include <QPainter>
#include <QMouseEvent>
#include <QWidget>
#include <vector>

#pragma once

struct Stroke{
    QSize strokeSize{20,20};
    QColor strokeColor{0, 191, 255};
    bool erase=false;
};

struct Thisone{
    QString shapeB;
    QColor color;
    QSize size;
    QPoint thisonePosition;
};

class Painting: public QWidget{
    Q_OBJECT
public:
    Painting();
    ~Painting();

    QColor getColor(){
        return streak.strokeColor;
    }
    QSize getSize(){
        return streak.strokeSize;
    }
    bool getErase(){
        return streak.erase;
    }
    bool isHollow(){
        if(massive.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
    void putInMassive(){
        Thisone testing;
        massive.push_back(testing);
    }
protected:
    void paintEvent(QPaintEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
private:
    bool mousePressed;
    QString brushShape="rectB";
    Stroke streak;
    QPainter* painter;
    std::vector<Thisone> massive={};
public slots:
    void BrushChanged(QString);
    void ShapeChanged(QString);
    void ColorChanged(QString);
    void SizeChanged(QString);
    void Desintegrate(QString);
};
