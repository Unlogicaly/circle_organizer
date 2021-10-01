//
// Created by tarog on 30.09.2021.
//

#include "actions.h"

void Sports::set_type(SportType sport_type) {

    this->sport_type = sport_type;
}

int Sports::get_id() const {  // Можно ли сделать код для конструкторов и get_id не повторяющимся?

    return Sports::id;
}

int Food::get_id() const {

    return Food::id;
}

int Other::get_id() const {

    return Other::id;
}