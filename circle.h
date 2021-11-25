//
// Created by Герман on 21.10.2021.
//

#ifndef PROJECT1_CIRCLE_H
#define PROJECT1_CIRCLE_H
#include "QWidget"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCore/QRandomGenerator>
#include <QGridLayout>
#include <QtCore/QTimer>

class Circle: public QWidget {
public:
    Circle(QWidget *parent = nullptr);

public slots:
    void explodeSlice(bool exploded);
    void explodeSlice_click();

private:
    QList<QtCharts::QPieSeries *> m_donuts;
};


#endif //PROJECT1_CIRCLE_H
