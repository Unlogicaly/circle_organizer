//
// Created by tarog on 25.09.2021.
//

#include "action.h"


const std::string &Action::get_name() const{
    return name;
}

QTime Action::get_time() const {

    return QTime(hour(), minute());
}

int Action::get_duration() const {
    return duration;
}

void Action::set_name(std::string &&name) {
    this->name = name;
}

void Action::set_time(int h, int m) {
    this->setHMS(h, m, 0);
}

void Action::set_duration(int duration) {
    this->duration = duration;
}

Action::Action(int h, int m, int duration, std::string &&name) :
        QTime(h, m), duration{duration}, name{name} {

}

Action::Action(Action &&action):
        QTime(action.hour(), action.minute()),
        duration{action.duration},
        name{action.name} {}
