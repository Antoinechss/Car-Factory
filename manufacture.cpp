#include "manufacture.h"
#include <iostream>

Factory::Factory()
{
    inventory["wheel"] = {1000.0, 0};
    inventory["engine"] = {2000.0, 0};
    inventory["glass"] = {500.0, 0};
    inventory["electronics"] = {10.0, 0};
    inventory["frame"] = {500.0, 0};
    car_inventory = 0;
    wallet.budget = 10000;
};

void Factory::reset_factory()
{
    /*
    Initializing a new empty factory
    */
    inventory["wheel"].second = 0;
    inventory["engine"].second = 0;
    inventory["glass"].second = 0;
    inventory["electronics"].second = 0;
    inventory["frame"].second = 0;
    car_inventory = 0;

    std::cout << "Resetting factory" << std::endl;
}

void Factory::buy(const std::string &component)
{
    /*
    Buying component stock and updating quantity and budget 
    */
    // checking for sufficient budget
    if (wallet.budget < inventory[component].first) {
        std::cout << "Insufficient funds" << std::endl;
    } else {
        // Updating inventory and budget after purchase
        inventory[component].second += 1;
        wallet.budget -= inventory[component].first;
    }
}

void Factory::build_car()
{
    /*
    Building a car    
    */
    // checking for available components
    if (inventory["wheel"].second < 4 || inventory["electronics"].second < 1
        || inventory["glass"].second < 6 || inventory["frame"].second < 1
        || inventory["engine"].second < 1) {
        std::cout << "Insufficient inventory" << std::endl;
    } else {
        inventory["wheel"].second -= 4;
        inventory["electronics"].second -= 1;
        inventory["glass"].second -= 6;
        inventory["frame"].second -= 1;
        inventory["engine"].second -= 1;
        car_inventory += 1;
        std::cout << "Car built!" << std::endl;
    }
}
