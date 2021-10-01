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

    for (; iter != events.end(); ++iter) {

        if ((*iter)->get_time() <= time and
            time < (*iter)->get_time().addSecs((*iter)->get_duration() * 60)) {

            current_event = iter;
        }
    }

    return iter;
}

void Day::delete_event() {

    events.erase(current_event);
}

template <typename T>
void Day::change_event_type() {

    *current_event = (*current_event)->change_type<T>();
}

void Day::create_event(QTime time) {

    events.insert(std::make_unique<Other>(time.hour(), time.minute(), 1, ""));
}
