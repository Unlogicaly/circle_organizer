//
// Created by tarog on 30.09.2021.
//

#include "day.h"

bool Day::select_event(QTime time) {

    current_event = find_event(time);

    return current_event != events.end();
}

decltype(Day::current_event) Day::find_event(QTime time) {

    auto iter = events.begin();

    Parameters params{};  // В будущем будет частью глобального класса. Не забыть убрать

    for (; iter != events.end(); ++iter) {

        (*iter)->get_params(params);

        QTime time_cur(params.h, params.m, 0);

        if (time_cur <= time and
            time < time_cur.addSecs(params.duration * 60)) {

            current_event = iter;
            return iter;
        }
    }

    return iter;
}

void Day::delete_event() {

    events.erase(current_event);
}

void Day::create_event(QTime time) {

    current_event = events.insert(std::make_unique<Other>(time.hour(), time.minute(), 1, "")).first;
}

Day::Day(int year, int month, int day) : QDate(year, month, day) {
}

void Day::get_current_params(Parameters &params) {

    (*current_event)->get_params(params);
}

void Day::set_current_params(Parameters &params) {

    (*current_event)->set_params(params);
}

void Day::set_current_type(int id) {

    auto new_event = events.insert(current_event, change_type((*current_event).get(), id));
    events.erase(current_event);
    current_event = new_event;
}
