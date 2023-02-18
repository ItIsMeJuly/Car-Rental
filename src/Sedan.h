#ifndef SEDAN_H
#define SEDAN_H

#include "Car.h"

#include <string>

class Sedan : public Car
{
private:
    int lastCleanedAtKm;
    const long double pricePerKm = 0.29;
    bool hasTowbar;

public:
    Sedan(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasTowbar);

    bool GetHasTowbar();
    bool GetNeedsCleaning() const;

    void Clean() override;
};

#endif