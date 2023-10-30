#include "HighwayPatrol.h"
#include "Highway.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"
#include <iostream>
#include <cassert>


HighwayPatrol::HighwayPatrol() : Vehicle("HighwayPatrol")
{

}

HighwayPatrol::~HighwayPatrol() = default;

HighwayPatrol::HighwayPatrol(const HighwayPatrol&) = default;

HighwayPatrol& HighwayPatrol::operator=(const HighwayPatrol&) = default;

void HighwayPatrol::scanHighway(Highway* h)
{
    std::cout << name << ": scanning highway for speeders" << std::endl;

    for( size_t i = h->vehicles.size(); i-- > 0; )
    {
        auto* v = h->vehicles[i];
        if( v->speed > h->speedLimit + 5 )
        {
            pullOver(v, v->speed > (h->speedLimit + 15), h );
            h->changeSpeed(50); //slow down for the highway patrol
        }
    }
}

std::string HighwayPatrol::getVehicleType(Vehicle *v)
{
    if(dynamic_cast<Car*>(v) != nullptr)
    {
        return "Car";
    }
    else if(dynamic_cast<Motorcycle*>(v) != nullptr)
    {
        return "Motorcycle";
    }
    else if(dynamic_cast<SemiTruck*>(v) != nullptr)
    {
        return "SemiTruck";
    }
    return "";
}

void HighwayPatrol::pullOver( Vehicle* v, bool willArrest, Highway* h )
{
    std::cout << "\n\n";
    std::cout << name << ": vehicle is traveling " << v->speed - h->speedLimit << " miles per hour over the speed limit" << std::endl;
    if( willArrest )
    {
        std::string vehicleType = getVehicleType(v);
        
        std::cout << name << ": YOU IN THE [ " << vehicleType << " ] PULL OVER AND SHOW YOUR HANDS" << std::endl;
        std::cout << "EVERYONE ELSE, SLOW DOWN!! \n\n\n";
        h->removeVehicle(v);
    }
}
