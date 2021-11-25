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

  public:

    Parameters params;

    std::unique_ptr<Day> *current_day{nullptr};

    class Org {

      private:

        Parameters *params;

        std::vector<std::unique_ptr<Day>> days; // Initially current day +- 30 days

        void expand(QDate date);

        void load(QDate date, int position);

      public:

        std::unique_ptr<Day>* get_day(QDate date);

        explicit Org(QDate date, Parameters *params);
    };

    Org org;

  public:

    explicit OrgGlob(QDate date): params(), org(date, &params) {

        current_day = org.get_day(date);
    }
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

OrgGlob::Org::Org(QDate date, Parameters *params) : days(61), params{params} {

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

    days[position] = std::make_unique<Day>(date);

    if (exists(path)) {

        std::ifstream is(path);

        int h, m, duration, id;
        std::string name;

        while(true) {

            is >> h >> m >> id;

            if (not is.good())
                break;

            days[position]->create_event({h, m, 0});
            days[position]->set_current_type(id);

            days[position]->parse_current(is);
        }
    }
}

int main(int argc, char *argv[]) {

    OrgGlob org_glob{{2021, 10, 21}};

    org_glob.current_day->get()->get_current_params(org_glob.params);

    std::cout << org_glob.params.name;

    return 0;
}
