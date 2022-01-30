#pragma once
#include<iostream>
#include<SKUItem.h>
using namespace std;
class CartItem
{
  public:
    bool PromotionApplied;
    double FinalPrice;
    SKUItem Item;
};
