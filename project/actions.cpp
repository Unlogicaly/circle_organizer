//
// Created by tarog on 30.09.2021.
//

#include "actions.h"

//-------------------Sports----------------------------

int Sports::get_id() const {  // Можно ли сделать код для конструкторов и get_id не повторяющимся?

    return Sports::id;
}

Sports::Sports(int h, int m, int duration, std::string &&name) :
        Action(h, m, duration, std::move(name)) {}

void Sports::get_params(Parameters &params) {

    get_default_params(params);
    params.sport_type = this->sport_type;
}

void Sports::set_params(Parameters &params) {

    set_default_params(params);
    sport_type = params.sport_type;
}

//---------------------Food------------------------------

int Food::get_id() const {

    return Food::id;
}

Food::Food(int h, int m, int duration, std::string &&name) :
        Action(h, m, duration, std::move(name)) {
}

//-----------------------Other-------------------------------

int Other::get_id() const {

    return Other::id;
}

Other::Other(int h, int m, int duration, std::string &&name) :
        Action(h, m, duration, std::move(name)) {
}

//-----------------------Note-------------------------------

int Note::get_id() const {

    return Note::id;
}

std::unique_ptr<Action> change_type(Action *action, int id) {

    if (id == 0)
        return std::make_unique<Other>(std::move(*action));

    if (id == 1)
        return std::make_unique<Note>(std::move(*action));

    if (id == 2)
        return std::make_unique<Sports>(std::move(*action));

    if (id == 3)
        return std::make_unique<Food>(std::move(*action));

//    if (id == 0)
//        return std::make_unique<Other>(std::move(*action)).release();
//
//    if (id == 0)
//        return std::make_unique<Other>(std::move(*action)).release();
//
//    if (id == 0)
//        return std::make_unique<Other>(std::move(*action)).release();
//    if (id == 0)
//        return std::make_unique<Other>(std::move(*action)).release();
    throw std::invalid_argument("invalid id");
}
