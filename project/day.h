//
// Created by tarog on 30.09.2021.
//

#ifndef UNTITLED_DAY_H
#define UNTITLED_DAY_H

#include "actions.h"
#include <set>
#include <memory>

class Day: public QDate {

  private:

    std::set<std::unique_ptr<Action>> events;

    decltype(events.begin()) current_event;

    decltype(current_event) find_event(QTime time);

  public:

    Day(int year, int month, int day);

    template<typename T>
    void change_event_type();

    void change_event(int h, int m, int duration, std::string &&name);

    bool select_event(QTime time);

    void create_event(QTime time);

    const Action &get_current_action();

    void delete_event();
};


#endif //UNTITLED_DAY_H
