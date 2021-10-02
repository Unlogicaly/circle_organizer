//
// Created by tarog on 25.09.2021.
//

#ifndef ACTION_H
#define ACTION_H

#include <QTime>
#include "parameters.h"

class Action: public QTime {

  private:

    int duration;  // в минутах
    std::string name;

  protected:

    Action(int h, int m, int duration, std::string &&name);
    Action(Action &&action);

  public:

    const std::string &get_name() const;
    virtual int get_id() const = 0;
    QTime get_time() const;
    int get_duration() const;
    virtual void get_params(Parameters &params) {}

    void set_name(std::string &&name);
    void set_time(int h, int m);
    void set_duration(int duration);

    template<typename T>
    std::unique_ptr<T> change_type() {

        return std::make_unique<T>(std::move(*this));
    }
};

#endif // ACTION_H
