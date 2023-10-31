#pragma once

#include "Vehicle.h"

struct SemiTruck : Vehicle
{
    SemiTruck(const std::string& s);
    virtual ~SemiTruck() override;
    SemiTruck(const SemiTruck&);
    SemiTruck& operator=(const SemiTruck&);

    void pullOver();
    void driveSlow();
};
