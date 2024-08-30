#ifndef INTERPRETOR_HPP
#define INTERPRETOR_HPP

#include <string>

class FlyController;

class Interpretor
{
public:
    Interpretor();
    virtual ~Interpretor(){};
    void serialCommand(String &stringCommandValue, FlyController *flyController);
};

#endif