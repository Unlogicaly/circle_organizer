//
// Created by Герман on 29.10.2021.
//
#include "calendar.h"
#include <QPainter>

Calendar::Calendar(QWidget *parent): QCalendarWidget{parent} {
    parent = new QCalendarWidget;
    setMinimumDate(QDate(2020, 1, 1));
    setMaximumDate(QDate(2023, 1, 1));
    setGridVisible(parent);
    setStyleSheet("background-color : lightblue;"); // misty_rose
}

void Calendar::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const {
    QCalendarWidget::paintCell(painter, rect, date);
    if (date == date.currentDate()) {
        painter->setPen(QPen(QColor(0, 0, 0), 2, Qt::SolidLine, Qt::RoundCap));
        painter->drawLine(rect.topRight(), rect.topLeft());
        painter->drawLine(rect.topRight(), rect.bottomRight());
        painter->drawLine(rect.bottomLeft(), rect.bottomRight());
        painter->drawLine(rect.topLeft(), rect.bottomLeft());
        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
    }
}
