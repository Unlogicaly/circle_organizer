#include <QCoreApplication>
#include <QTime>
#include <memory>
#include <iostream>
#include <set>
#include "actions.h"
#include "day.h"


int main(int argc, char *argv[]) {

    Day day(2021, 10, 14);

    day.create_event({19, 38, 0});
    day.create_event({20, 40, 2});

    for (auto i = 0; i < 10000000; ++i) {

        day.set_current_type(i % 4);
        if (!(i % 1001))
            std::cout << i << '\n';
    }

    return 0;
}

