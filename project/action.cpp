//
// Created by tarog on 25.09.2021.
//

#include "action.h"

Action::Action(int h, int m, int duration, std::string &&name) :
        QTime(h, m), duration{duration}, name{name} {

}

Action::Action(Action &&action) noexcept:
        QTime(action.hour(), action.minute()){

    std::swap(duration, action.duration);
    std::swap(name, action.name);
}

void Action::get_default_params(Parameters &params) {

    params.duration = this->duration;
    params.h = this->hour();
    params.m = this->minute();
    params.id = this->get_id();
    params.name = this->name;
}

void Action::set_default_params(Parameters &params) {

    this->setHMS(params.h, params.m, 0);
    this->duration = params.duration;
    this->name = params.name;
}

void Action::get_params(Parameters &params) {

    get_default_params(params);
}

void Action::set_params(Parameters &params) {

    set_default_params(params);
}

void Action::set_duration(int dur) {

    this->duration = dur;
}

void Action::parse(std::ifstream &is) {

    is >> duration;
    std::getline(is, name);
    std::getline(is, name);
}
