#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
    std::string manufacturer; 
    std::string model;        
    int buildYear;            
    std::string licensePlate; 
    long double pricePerKm;
    bool isAvailable;         
    int kilometers;           

public:
    Car(std::string manufacturer, std::string model, int buildYear, std::string licensePlate, long double pricePerKm);

    bool Rent();

    virtual void Clean() = 0;
    virtual bool GetNeedsCleaning() const = 0;
    virtual long double Return(int kilometers);

    long double GetPricePerKm() const;
    std::string GetManufacturer() const;
    std::string GetModel() const;
    std::string GetLicensePlate() const;
    int GetBuildYear() const;
    int GetKilometers() const;
    bool GetIsAvailable() const;

    void SetKilometers(int kilometers);
    void SetIsAvailable(bool isAvailable);

    std::string ToString();

};

#endif