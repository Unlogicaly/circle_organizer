//
// Created by tarog on 30.09.2021.
//

#ifndef UNTITLED_ACTIONS_H
#define UNTITLED_ACTIONS_H

#include "action.h"

class Sports: public Action {

  private:

    SportType sport_type{SportType::Other};

    const static int id = 2;

  public:

    Sports(int h, int m, int duration, std::string &&name):
            Action(h, m, duration, std::move(name)) {}

    Sports(Action &&action): Action(std::move(action)) {}

    void set_type(SportType sport_type);

    void get_params(Parameters &params) override {
        params.sport_type = &this->sport_type;
    }

    int get_id() const override;
};

class Food: public Action {

  private:

    const static int id = 3;

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

class Note: public Action{

  private:

    const static int id = 1;

  private:

    Note(std::string &&name): Action(0, 0, 0, std::move(name)) {}

    Note(Action &&action) : Action(std::move(action)) {}

    int get_id() const override;
};


#endif //UNTITLED_ACTIONS_H
