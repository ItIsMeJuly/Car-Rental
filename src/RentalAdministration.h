#ifndef RENTAL_ADMINISTRATION_H
#define RENTAL_ADMINISTRATION_H

#include "Car.h"

#include <vector>
#include <string>

class RentalAdministration
{
private:
    std::vector<Car*> cars;

public:
    RentalAdministration();

    Car* FindCar(std::string licencePlate);
    Car* FindCarWithException(std::string licencePlate);
    bool Add(Car* car);
    bool RentCar(std::string licencePlate);
    long double ReturnCar(std::string licencePlate, int kilometers);
    void CleanCar(std::string licencePlate);

    std::vector<Car*> GetCars() const;
};

#endif