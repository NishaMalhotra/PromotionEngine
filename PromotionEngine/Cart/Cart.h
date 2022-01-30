#pragma once
#include<iostream>
#include<string>
#include<list>
#include<CartItem.h>
using namespace std;
class Cart
{
    private:
        list<CartItem> ItemList;
        double TotalPrice;
    public:
        Cart();
        
        void AddItem(SKUItem item);
        void RemoveItem(string skuItemId);
        bool IsValidSKU(string sku);
};
