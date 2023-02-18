#include "Limousine.h"

// TODO: implement your class methods here

Limousine::Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar)
    : Car(manufacturer, model, buildYear, licencePlate, this->GetPricePerKm())
{
    this->hasMiniBar = hasMinibar;
    needsCleaning = false;
}

bool Limousine::GetHasMiniBar()
{
    return hasMiniBar;
}

bool Limousine::GetNeedsCleaning() const
{
    return needsCleaning;
}

long double Limousine::Return(int kilometers)
{
    return kilometers;
}

void Limousine::Clean()
{
    needsCleaning = false;
}