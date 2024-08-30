#ifndef INTERPRETOR_HPP
#define INTERPRETOR_HPP

#include <string>

class FlyController; // Déclaration anticipée de FlyController

class Interpretor
{
    FlyController *flyController;
public:
    Interpretor();
    Interpretor(FlyController *flyController);
    virtual ~Interpretor(){};
    void serialCommand(String &stringCommandValue, FlyController *flyController);
};

#endif