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

    template<typename T>
    void change_event_type();

    bool select_event(QTime time);

    void create_event(QTime time);

    void delete_event();
};


#endif //UNTITLED_DAY_H
