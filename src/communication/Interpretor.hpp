#ifndef INTERPRETOR_HPP
#define INTERPRETOR_HPP

#include <string>

class Interpretor
{
public:
    Interpretor();
    virtual ~Interpretor(){};
    void serialCommand(std::string stringCommandValue);
};

#endif