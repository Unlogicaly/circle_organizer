//
// Created by tarog on 30.09.2021.
//

#ifndef UNTITLED_ACTIONS_H
#define UNTITLED_ACTIONS_H

#include "action.h"

enum class SportType {
    Other = -1, Football, Basketball, Volleyball, Skiing, Jogging
};

class Sports: public Action {

  private:

    SportType sport_type{SportType::Other};

    const static int id = 1;

  public:

    Sports(int h, int m, int duration, std::string &&name):
            Action(h, m, duration, std::move(name)) {}

    Sports(Action &&action): Action(std::move(action)) {}

    void set_type(SportType sport_type);

    int get_id() const override;
};

class Food: public Action {

  private:

    const static int id = 2;

  public:

    Food(int h, int m, int duration, std::string &&name):
            Action(h, m, duration, std::move(name)) {
    }

    Food(Action &&action): Action(std::move(action)) {}

    int get_id() const override;
};

class Other: public Action{

  private:

    const static int id = 0;

  public:

    Other(int h, int m, int duration, std::string &&name):
            Action(h, m, duration, std::move(name)) {
    }

    Other(Action &&action): Action(std::move(action)) {}

    int get_id() const override;
};

#endif //UNTITLED_ACTIONS_H
