#pragma once

#include "business.h"

#include <iostream>
#include <list>
#include <map>
#include <string>

class Factory
{
public:
    Wallet wallet;

    std::map<std::string, std::pair<double, int>> inventory;
    // Initializing components price and stock

    int car_inventory; // number of cars available for sale

    // Constructor
    Factory();

    void reset_factory();
    void buy(const std::string &component);
    void build_car();
};
