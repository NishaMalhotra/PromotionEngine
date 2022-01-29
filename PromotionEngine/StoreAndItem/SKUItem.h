#pragma once
#include<iostream>
#include<Store.h>
#include<list>
#include<string.h>
using namespace std;
class SKUItem
{
    String Id;
    double UnitPrice;
    public:
        SKUItem(string id, double unitPrice);
        string getID();
        double getUnitPrice();
        void UpdateUnitPrice(double price);
};

