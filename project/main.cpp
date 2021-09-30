#include <QCoreApplication>
#include <QTime>
#include <memory>
#include <iostream>
#include "action.h"

enum SportType {
    Other = -1, Football, Basketball, Volleyball, Skiing, Jogging
};

class Sports: public Action {

  private:

    SportType sport_type{Other};

    const static int id = 0;

  public:

    Sports(int h, int m, int duration, std::string &&name):
            Action(h, m, duration, std::move(name)) {}

    Sports(Action &&action): Action(std::move(action)) {}

    void set_type(SportType sport_type) {
        this->sport_type = sport_type;
    }

    int get_id() const override {

        return Sports::id;
    }
};

class Food: public Action {

  private:

    const static int id = 1;

  public:

    Food(int h, int m, int duration, std::string &&name):
            Action(h, m, duration, std::move(name)) {
    }

    Food(Action &&action): Action(std::move(action)) {}

    int get_id() const override {

        return Food::id;
    }
};

int main(int argc, char *argv[]) {

    std::vector<std::unique_ptr<Action>> events;

    events.push_back(std::make_unique<Food>(10, 5, 10, "Eating at home"));
    events.push_back(std::make_unique<Sports>(10, 20, 50, "Jogging at park"));

    for (auto i = 0 ; i < 100000; ++i) {
        events[0] = events[0]->change_type<Sports>();
        std::cout << events[0]->get_id();
        events[0] = events[0]->change_type<Food>();
        std::cout << events[0]->get_id();
    }

    return 0;
}

