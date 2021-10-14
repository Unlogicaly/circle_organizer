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

    void get_current_params(Parameters &params);
    void set_current_params(Parameters &params);

    bool select_event(QTime time);
    void create_event(QTime time);

    void set_current_type(int id);

    void delete_event();
};


#endif //UNTITLED_DAY_H
