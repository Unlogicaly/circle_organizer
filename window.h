//
// Created by Герман on 21.10.2021.
//

#ifndef PROJECT1_WINDOW_H
#define PROJECT1_WINDOW_H
#include <QWidget>
#include <QDate>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include "circle.h"
#include "calendar.h"

class Window: public QWidget {
public:
    Window(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *resize_event) override;
    void draw_outside_circle();
    void draw_calendar();
    void set_date();

private:
    void initUI();
    QGridLayout *grid;
    QDate date;
    Circle *out_circle;
    Calendar *clndr;

    int screen_height;
    int screen_width;
};

#endif //PROJECT1_WINDOW_H