#pragma once

#include <string>
#include <iostream>

struct Vehicle
{
    Vehicle(const std::string& n);

    //Special member Functions.
    virtual ~Vehicle();
    Vehicle(const Vehicle&);
    Vehicle& operator=(const Vehicle&);

    virtual void setSpeed(int s);
    virtual void tryToEvade();

protected:
    int speed = 0;
    std::string name;
    friend struct HighwayPatrol;
};
