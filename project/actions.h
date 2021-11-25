//
// Created by tarog on 30.09.2021.
//

#ifndef UNTITLED_ACTIONS_H
#define UNTITLED_ACTIONS_H

#include "action.h"
#include <stdexcept>

class Sports: public Action {

  private:

    SportType sport_type{SportType::Other};

    const static int id = 2;

  public:

    Sports(int h, int m, int duration, std::string &&name);

    explicit Sports(Action &&action): Action(std::move(action)) {}

    void get_params(Parameters &params) override;
    void set_params(Parameters &params) override;

    void parse(std::ifstream &is) override;

    int get_id() const override;
};


class Food: public Action {

  private:

    const static int id = 3;

  public:

    Food(int h, int m, int duration, std::string &&name);

    explicit Food(Action &&action): Action(std::move(action)) {}

    int get_id() const override;
};


class Other: public Action{

  private:

    const static int id = 0;

  public:

    Other(int h, int m, int duration, std::string &&name);

    explicit Other(Action &&action): Action(std::move(action)) {}

    int get_id() const override;
};


class Note: public Action{

  private:

    const static int id = 1;

  public:

    explicit Note(std::string &&name): Action(0, 0, 0, std::move(name)) {}

    explicit Note(Action &&action): Action(std::move(action)) {

        setHMS(0, 0, 0);
        set_duration(0);
    }

    int get_id() const override;
};


std::unique_ptr<Action> change_type(Action *action, int id);


#endif //UNTITLED_ACTIONS_H
