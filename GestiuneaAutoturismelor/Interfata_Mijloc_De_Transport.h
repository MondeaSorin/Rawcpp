#pragma once
#include <iostream>
class Interfata_Mijloc_De_Transport
{
    friend std::ostream& operator<<(std::ostream& os, const Interfata_Mijloc_De_Transport& obj);
public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~Interfata_Mijloc_De_Transport() = default;
};

std::ostream& operator<<(std::ostream& os, const Interfata_Mijloc_De_Transport& obj) {
    obj.print(os);
    return os;
}

