//
// Created by tarog on 02.10.2021.
//

#ifndef UNTITLED_PARAMETERS_H
#define UNTITLED_PARAMETERS_H

enum class SportType {
    Other = -1, Football, Basketball, Volleyball, Skiing, Jogging
};

struct Parameters{

    std::string name;
    int h, m, duration;
    int id;

    std::vector<std::string> products_list{};
    SportType sport_type{};
};

#endif //UNTITLED_PARAMETERS_H
