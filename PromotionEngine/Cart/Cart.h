#include<iostream>
#include<string>
#include<list>
using namespace std;
class cart 
{
    private:
        list<cartItem> ItemList();
    public:
        Cart();
        double TotalPrice();
        void AddItem(SKUitem item);
        void RemoveItem(string skuItemId);
        bool IsValidSKU(string sku);
};
