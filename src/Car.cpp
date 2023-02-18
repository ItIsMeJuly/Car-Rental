#include <stdexcept>
using namespace std;

#include "Car.h"

// TODO: implement your class methods here

Car::Car(std::string manufacturer, std::string model, int buildYear, std::string licensePlate, long double pricePerKm)
{
    if ((manufacturer == "") || (model == "") || (licensePlate == ""))
    {
        throw invalid_argument("arguments are null");
    }
    if (buildYear < 1890)
    {
        throw invalid_argument("cars cannot be built before 1890!");
    }
    if (pricePerKm < 0)
    {
        throw invalid_argument("cannot be smaller than 0");
    }
    this->manufacturer = manufacturer;
    this->model = model;
    this->buildYear = buildYear;
    this->licensePlate = licensePlate;
    this->kilometers = 0;
    this->isAvailable = true;
    this->pricePerKm = pricePerKm;
}

bool Car::GetIsAvailable() const
{
    return isAvailable;
}

bool Car::Rent()
{
    if (!isAvailable)
    {
        return false;
    }

    isAvailable = false;
    return true;
}

long double Car::Return(int kilometers)
{
    if (isAvailable)
    {
        throw invalid_argument("car was not rented");
    }
    if (kilometers < this->kilometers)
    {
        throw invalid_argument("car is returned with less kilometers than it had");
    }

    long double cost = pricePerKm * (kilometers - kilometers);
    kilometers = kilometers;
    isAvailable = true;
    return cost;
}

void Car::SetKilometers(int kilometers)
{
    kilometers = kilometers;
}

void Car::SetIsAvailable(bool isAvailable)
{
    isAvailable = isAvailable;
}

string Car::ToString()
{
    return manufacturer +
           " - " + model +
           ", " + licensePlate;
}

long double Car::GetPricePerKm() const
{
    return pricePerKm;
}

std::string Car::GetManufacturer() const
{
    return manufacturer;
}

std::string Car::GetModel() const
{
    return model;
}

std::string Car::GetLicensePlate() const
{
    return licensePlate;
}

int Car::GetBuildYear() const
{
    return buildYear;
}

int Car::GetKilometers() const
{
    return kilometers;
}