#include "RentalAdministration.h"

#include <string>
#include <vector>
#include <stdexcept>

RentalAdministration::RentalAdministration()
{
}

bool RentalAdministration::Add(Car *car)
{
    if (car == nullptr)
    {
        throw std::invalid_argument("nullptr exception");
    }

    if (FindCar(car->GetLicensePlate()) != nullptr)
    {
        return false;
    }
    cars.push_back(car);
    return true;
}

bool RentalAdministration::RentCar(std::string licencePlate)
{
    if (licencePlate == "")
    {
        throw std::invalid_argument("nullpointer as argument");
    }

    Car *car = FindCarWithException(licencePlate);
    return car->Rent();
}

long double RentalAdministration::ReturnCar(std::string licencePlate, int kilometers)
{
    if (licencePlate == "")
    {
        throw std::invalid_argument("empty license plate");
    }

    Car *car = FindCarWithException(licencePlate);
    if (car == nullptr)
    {
        throw std::invalid_argument("car is mull");
    }
    if (car->GetIsAvailable())
    {
        throw std::invalid_argument("car is not rented");
    }

    return car->Return(kilometers);
}

void RentalAdministration::CleanCar(std::string licencePlate)
{
    if (licencePlate == "")
    {
        throw std::invalid_argument("no license plate");
    }

    Car *car = FindCarWithException(licencePlate);
    car->Clean();
}

Car *RentalAdministration::FindCar(std::string licencePlate)
{
    for (long long unsigned int i = 0; i < cars.size(); i++)
    {
        if (cars[i]->GetLicensePlate() == licencePlate)
        {
            return cars[i];
        }
    }
    return nullptr;
}

Car *RentalAdministration::FindCarWithException(std::string licencePlate)
{
    Car *car = FindCar(licencePlate);
    if (car == nullptr)
    {
        throw std::invalid_argument("no car with this licenceplate in administration");
    }
    return car;
}

std::vector<Car *> RentalAdministration::GetCars() const
{
    return cars;
}