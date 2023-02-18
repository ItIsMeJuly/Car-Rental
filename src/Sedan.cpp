#include "Sedan.h"

#include <string>

Sedan::Sedan(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasTowbar)
    : Car(manufacturer, model, buildYear, licencePlate, this->GetPricePerKm())
{
    this->hasTowbar = hasTowbar;
    lastCleanedAtKm = 0;
}

bool Sedan::GetHasTowbar()
{
    return hasTowbar;
}

bool Sedan::GetNeedsCleaning() const
{
    return (GetKilometers() - lastCleanedAtKm) >= 1000;
}

void Sedan::Clean()
{
    lastCleanedAtKm = GetKilometers();
}