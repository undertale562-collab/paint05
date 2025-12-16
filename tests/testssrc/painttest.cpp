#include "painttest.h"
#include "C:\Users\under\desktop\projects\c++\paint05\src\painting.h"
#include <QTest>

void QPainttest::init(){

}

void QPainttest::initTestCase(){

}

void QPainttest::testBrush(){
    Painting canvas;
    QColor colorReference;
    QSize sizeReference;

    canvas.ColorChanged("Blue");
    colorReference={0,0,255};
    QCOMPARE(colorReference, canvas.getColor());
    canvas.ColorChanged("Red");
    colorReference={255,0,0};
    QCOMPARE(colorReference, canvas.getColor());
    canvas.ColorChanged("Green");
    colorReference={0,255,0};
    QCOMPARE(colorReference, canvas.getColor());

    sizeReference=canvas.getSize();
    canvas.SizeChanged("Thicker");
    QCOMPARE(sizeReference.width()+10, canvas.getSize().width());
    canvas.SizeChanged("Thinner");
    QCOMPARE(sizeReference.width(), canvas.getSize().width());
    canvas.SizeChanged("Higher");
    QCOMPARE(sizeReference.height()+10, canvas.getSize().height());
    canvas.SizeChanged("Lower");
    QCOMPARE(sizeReference.height(), canvas.getSize().height());
}

void QPainttest::testMassive(){
    Painting canvas;
    canvas.putInMassive();
    QCOMPARE(false, canvas.isHollow());
    canvas.Desintegrate("Clear");
    QCOMPARE(true, canvas.isHollow());
}

void QPainttest::cleanupFirstTest(){

}

void QPainttest::cleanup(){

}

// void QCarTest::testConsts(){
//     QCar car;
//     QCOMPARE(0.12, car.getConsumption());
//     QCOMPARE(50, car.getMaxFuel());
//     QCOMPARE(0, car.getCurrentFuel());
// }

// void QCarTest::testFuel(){
//     QCar car;
//     QCOMPARE(car.refuel(), 50);
//     QCOMPARE(car.getCurrentFuel(), car.getMaxFuel());
//     double maxdistance=car.getMaxFuel()/car.getConsumption();
//     QVERIFY(car.drive(maxdistance));
//     QCOMPARE(0, car.getCurrentFuel());
//     QCOMPARE(car.refuel(), 50);
//     QCOMPARE(car.getCurrentFuel(), car.getMaxFuel());
//     QVERIFY(!car.drive(maxdistance+1));
//     QCOMPARE(car.getCurrentFuel(), car.getMaxFuel());
// }
