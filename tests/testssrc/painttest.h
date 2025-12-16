#include <QObject>

class QPainttest: public QObject{
    Q_OBJECT
private slots:
    void initTestCase();
    void init();

    void testBrush();
    void testMassive();

    void cleanupFirstTest();
    void cleanup();
};
