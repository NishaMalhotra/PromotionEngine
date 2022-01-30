#pragma once
#include<iostream>
#include<string>
#include<list>
#include<CartItem.h>
using namespace std;
class Cart
{
    private:
        list<CartItem> Items;
    public:
        Cart();
        double TotalPrice();
        void AddItem(SKUItem item);
        void AddItems(SKUItem item,int noOfItems);
        void RemoveItem(string skuItemId);
        bool IsValidSKU(string sku);
};
