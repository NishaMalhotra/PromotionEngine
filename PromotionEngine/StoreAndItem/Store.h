#pragma once
#include<iostream>
#include<list>
#include<SKUItem.h>
#include<Cart.h>
#include<PromotionRules.h>

using namespace std;
class Store//:public AbstractStoreClass
{
   Cart cart;
        list<PromotionRules*> Promotions;
        list<SKUItem> Items;
  public:
    Store();
//    list<PromotionRules> Promotions();
    Store AddSKUitem(SKUItem item);
    Store AddPromotions(list<PromotionRules*> promotions);
    Store AddPromotion(PromotionRules *promotion);
    Store AddPromotion(string promotion);
    void DeletePromotion(string promotion);
    Store AddItemToCart(string itemSKU);
    Store EmptyCart();
    Store Checkout();
    list<SKUItem> GetSKUitems();
    void UpdateSKUitemUnitPrice(string sku, float price);
    void DeleteSKUitem(string sku);
    list<PromotionRules*> GetPromotions();
    list<SKUItem> GetAllItems();
    SKUItem GetItem(string sku);
    void DeleteItemFromCart(string sku);
    double GetCartTotal();
    Cart GetCart();
    bool IsValidSKU(string sku);
};

