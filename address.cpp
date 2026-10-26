#include "address.h"

Address::Address()
{
    street = "";
    city = "";
    state = "";
    zip = "";
}

Address::Address(std::string street,
                 std::string city,
                 std::string state,
                 std::string zip)
{
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

std::string Address::toString()
{
    return street + "\n" +
           city + " " +
           state + ", " +
           zip;
}
