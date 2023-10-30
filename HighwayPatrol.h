#pragma once 

#include "Vehicle.h"

struct Highway;

struct HighwayPatrol : Vehicle 
{
    HighwayPatrol();
    virtual ~HighwayPatrol() override;
    HighwayPatrol(const HighwayPatrol&);
    HighwayPatrol& operator=(const HighwayPatrol&);

    void scanHighway(Highway* h);
    std::string getVehicleType(Vehicle* v);

    void pullOver( Vehicle* v, bool willArrest, Highway* h );
};
