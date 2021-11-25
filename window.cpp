//
// Created by Герман on 21.10.2021.
//
#include "window.h"
#include <iostream>
#include <QDesktopWidget>


Window::Window(QWidget *parent) : QWidget(parent) {

    auto desk = QDesktopWidget();

    QRect rec = desk.screenGeometry();
    screen_height = rec.height();
    screen_width = rec.width();

    initUI();
}

void Window::draw_outside_circle(){
    out_circle = new Circle();

    grid->setColumnMinimumWidth(0, screen_width / 10);
    grid->setColumnMinimumWidth(2, screen_width / 10);

    grid->addWidget(out_circle, 0, 1, 4, 1, Qt::AlignHCenter);
}

void Window::draw_calendar() {
    clndr = new Calendar;
    grid->addWidget(clndr, 0, 2, 1, 1, Qt::AlignVCenter);
}

void Window::set_date(){
    date = QDate::currentDate();
    QString str_main = date.toString("ddd, d MMMM yyyy");
    auto *label = new QLabel(str_main);
    label->setFont(QFont("Purisa", 16));
    label->setStyleSheet("QLabel { color : black; }");
    grid->addWidget(label, 0, 1, Qt::AlignHCenter | Qt::AlignTop);
}

void Window::resizeEvent(QResizeEvent *resize_event) {

    QWidget::resizeEvent(resize_event);

    grid->setColumnMinimumWidth(0,resize_event->size().width() * 2 / 9);
    grid->setColumnMinimumWidth(2,resize_event->size().width() * 2 / 9);

    out_circle->setFixedSize(resize_event->size().width() / 2, resize_event->size().height() * 11 / 12);
}

void Window::initUI() {
    setWindowTitle("Planner");
    setGeometry(60, 60, screen_width / 2, screen_height / 2);
    setStyleSheet("background-color: white");

    grid = new QGridLayout();
    draw_outside_circle();
    draw_calendar();
    set_date();

    setLayout(grid);
}
