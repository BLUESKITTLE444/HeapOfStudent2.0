#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

public:
    Address();
    Address(std::string street,
            std::string city,
            std::string state,
            std::string zip);

    std::string toString();
};

#endif
