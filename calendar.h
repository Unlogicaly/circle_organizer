//
// Created by Герман on 29.10.2021.
//

#ifndef PROJECT1_CALENDAR_H
#define PROJECT1_CALENDAR_H
#include <QWidget>
#include <QCalendarWidget>

class Calendar: public QCalendarWidget {
public:
    Calendar(QWidget *parent = nullptr);
protected:
    void paintCell(QPainter * painter, const QRect & rect, const QDate & date) const override;
};


#endif //PROJECT1_CALENDAR_H
