#pragma once
#include <iostream>

class Wallet
{
public:
    double budget;
    double sell_rate;
    double sell_price;
    double popularity;

    Wallet();

    void reset_market();
    void reset_wallet();
    void set_sell_price(double price);
    void update_sell_rate();
};
