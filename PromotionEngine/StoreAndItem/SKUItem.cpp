#include <SKUItem.h>
using namespace std;
SKUitem::SKUitem(string id, double unitPrice)
{
    if(id == NULL)
        throw std::invalid_argument("Invalid SKUId!!");
    if(unitPrice <=0)
        throw std::invalid_argument("Invalid unitPrice!!");
    
    this->id = id;
    this->unitPrice = unitPrice;
}
string SKUitem::getID()
{
    return id;
}
double SKUitem::getUnitPrice()
{
    return unitPrice;
}
void SKUitem::UpdateUnitPrice(double price)
{
    unitPrice = price;
}
