#pragma once
#include<iostream>
#include<SKUItem.h>
using namespace std;
class CartItem
{
  private:
    bool PromotionApplied;
    double FinalPrice;
    SKUItem Item;
  public:
    CartItem(){}
    CartItem(SKUItem item,double price,bool promo){
      Item = item;
      FinalPrice = price;
      PromotionApplied = promo;
    }
};
