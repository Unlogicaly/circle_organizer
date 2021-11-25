//
// Created by Герман on 21.10.2021.
//
#include "circle.h"
#include <QStyle>


Circle::Circle(QWidget *parent): QWidget{parent}
{
    setMinimumSize(800, 800);
    QGridLayout *mainLayout = new QGridLayout();
    QtCharts::QChartView *chartView = new QtCharts::QChartView;

    chartView->setAutoFillBackground(true);
    chartView->setBackgroundBrush(QBrush(Qt::white));
    chartView->setRenderHint(QPainter::Antialiasing);
    QtCharts::QChart *chart = chartView->chart();
    chart->legend()->setVisible(false);
    chart->setAnimationOptions(QtCharts::QChart::AllAnimations);

    chart->setBackgroundBrush(QBrush(Qt::white));

    qreal minSize = 0.3;
    qreal maxSize = 0.8;
    int donutCount = 2;

    for (int i = 0; i < donutCount; i++) {
        QtCharts::QPieSeries *donut = new QtCharts::QPieSeries;
        int sliceCount =  3;
        for (int j = 0; j < sliceCount; j++) {
            qreal value = 100 + QRandomGenerator::global()->bounded(100);
            QtCharts::QPieSlice *slice = new QtCharts::QPieSlice(QString("%1").arg(value), value);
            slice->setLabelVisible(true);
            slice->setLabelColor(Qt::white);
            slice->setLabelPosition(QtCharts::QPieSlice::LabelInsideTangential);
            connect(slice, &QtCharts::QPieSlice::hovered, this, &Circle::explodeSlice);
            donut->append(slice);
            donut->setHoleSize(minSize + i * (maxSize - minSize) / donutCount);
            donut->setPieSize(minSize + (i + 1) * (maxSize - minSize) / donutCount);
        }
        m_donuts.append(donut);
        chartView->chart()->addSeries(donut);
    }

    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
}

void Circle::explodeSlice(bool exploded)
{
    QtCharts::QPieSlice *slice = qobject_cast<QtCharts::QPieSlice *>(sender());
    if (exploded) {
        qreal sliceStartAngle = slice->startAngle();
        qreal sliceEndAngle = slice->startAngle() + slice->angleSpan();

        QtCharts::QPieSeries *donut = slice->series();
        qreal seriesIndex = m_donuts.indexOf(donut);
        for (int i = seriesIndex + 1; i < m_donuts.count(); i++) {
            m_donuts.at(i)->setPieStartAngle(sliceEndAngle);
            m_donuts.at(i)->setPieEndAngle(360 + sliceStartAngle);
        }
    } else {
        for (int i = 0; i < m_donuts.count(); i++) {
            m_donuts.at(i)->setPieStartAngle(0);
            m_donuts.at(i)->setPieEndAngle(360);
        }
    }
    slice->setExploded(exploded);
}

void Circle::explodeSlice_click() {
    QtCharts::QPieSlice *slice = qobject_cast<QtCharts::QPieSlice *>(sender());
    qreal sliceStartAngle = slice->startAngle();
    qreal sliceEndAngle = slice->startAngle() + slice->angleSpan();

    QtCharts::QPieSeries *donut = slice->series();
    qreal seriesIndex = m_donuts.indexOf(donut);
    for (int i = seriesIndex + 1; i < m_donuts.count(); i++) {
        m_donuts.at(i)->setPieStartAngle(sliceEndAngle);
        m_donuts.at(i)->setPieEndAngle(360 + sliceStartAngle);
    }
}

