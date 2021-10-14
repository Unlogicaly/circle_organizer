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
    Action(Action &&action) noexcept ;

    void get_default_params(Parameters &params);
    void set_default_params(Parameters &params);

  public:

    virtual int get_id() const = 0;
    void set_duration(int duration);

    virtual void get_params(Parameters &params);

    virtual void set_params(Parameters &params);
};

#endif // ACTION_H
