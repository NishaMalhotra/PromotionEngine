#pragma once
#include<iostream>
#include<Store.h>
#include<list>
using namespace std;
class SKUItem
{
    public:
        SKUItem(string id, double unitPrice);
        string getID();
        double getUnitPrice();
        void UpdateUnitPrice(double price);
};

