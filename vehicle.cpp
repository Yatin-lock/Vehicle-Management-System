#include "vehicle.h"
// #include "string_helper.h"

const char DELIMITER = ';';

Vehicle::Vehicle(
            string registrationNumber, 
            VehicleType type,
            int seats,
            string companyName,
            double pricePerKm,
            Date PUCExpirationDate,
            long recordId=0
        ){
    this->registrationNumber = registrationNumber;
    this->type = type;
    this->seats = seats;
    this->companyName = companyName;
    this->pricePerKm = pricePerKm;
    this->PUCExpirationDate = PUCExpirationDate;
    }
    string Vehicle::getRegistrationNumber() const;