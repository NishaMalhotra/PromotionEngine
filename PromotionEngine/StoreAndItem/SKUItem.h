#include<iostream>
#include<Store.h>
#include<list>
using namespace std;
class SKUItem 
{
    public:
        SKUitem(string id, double unitPrice);
        string getID();  
        double getUnitPrice();
        void UpdateUnitPrice(double price);
};
