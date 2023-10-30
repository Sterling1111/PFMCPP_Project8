#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

SemiTruck::~SemiTruck() = default;

SemiTruck::SemiTruck(const SemiTruck&) = default;

SemiTruck& SemiTruck::operator=(const SemiTruck&) = default;

void SemiTruck::driveSlow()
{
    setSpeed(50);
    std::cout << name << ": driving slow" << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem?" << std::endl;
}
