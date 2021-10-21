#include <QCoreApplication>
#include <QTime>
#include <memory>
#include <iostream>
#include <set>
#include "actions.h"
#include "day.h"
#include <sys/stat.h>

inline bool exists(const std::string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}

class OrgGlob {

  private:

    Parameters params;

    std::unique_ptr<Day> *current_day{nullptr};

    class Org {

      private:

        std::vector<std::unique_ptr<Day>> days; // Initially current day +- 30 days

        void expand(QDate date);

        void load(QDate date, int position);

        void read_file(std::ifstream &is);

      public:

        std::unique_ptr<Day>* get_day(QDate date);

        explicit Org(QDate date);
    };

    Org org;

  public:


};

std::unique_ptr<Day> *OrgGlob::Org::get_day(QDate date) {

    int num = days[0]->daysTo(date);

    if (num < 0) {

        throw std::invalid_argument("Day is lower than accepted");
    }

    if (num > 365) {

        throw std::invalid_argument("Day is higher than accepted");
    }

    if (num > days.size()) {

        expand(date);
    }

    if (!days[num].get()) {

        load(date, num);
    }

    return &days[num];
}

OrgGlob::Org::Org(QDate date) : days(61) {

    days.reserve(365);

    load(date.addDays(-30), 0);
    load(date, 30);
    load(date.addDays(30), 60);
}

void OrgGlob::Org::expand(QDate date) {

    days.resize(days[0]->daysTo(date) + 1);
}

void OrgGlob::Org::load(QDate date, int position) {

    std::string path{R"(C:\circle_organizer\days\)" + date.toString("dd.MM.yyyy").toStdString() + ".txt"};

    if (exists(path)) {

        // to be implemented
    }
}

void OrgGlob::Org::read_file(std::ifstream &is) {  // Stopped working here

    char checker;

    // to be implemented
}

int main(int argc, char *argv[]) {

    QDate date{2021, 10, 21};

    std::string path{R"(C:\circle_organizer\days\)" + date.toString("dd.MM.yyyy").toStdString() + ".txt"};

    std::cout << path << " " << exists(path);

    return 0;
}
