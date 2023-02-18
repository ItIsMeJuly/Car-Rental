#ifndef LIMOUSINE_H
#define LIMOUSINE_H

#include "Car.h"

#include <string>

class Limousine : public Car
{
private:
    const long double pricePerKm = 2.5;
    bool needsCleaning;
    bool hasMiniBar;

public:
    Limousine(std::string manufacturer, std::string model, int buildYear, std::string licencePlate, bool hasMinibar);

    bool GetHasMiniBar();
    bool GetNeedsCleaning() const;
    long double Return(int kilometers) override;
    void Clean() override;
};

#endif