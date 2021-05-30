/*
6. Inventory Class
Design an Inventory class that can hold information and calculate data for items in a
retail store's inventory. The class should have the following private member variables:
-------------------------------------------------------------------------------
Variable Name      Description
-------------------------------------------------------------------------------
itemNumber         An int that holds the item's item number
quantity           An int for holding the quantity of the items on hand
cost               A double for holding thw wholesale per-unit cost of the item
totalCost          A double for holding the total inventory cost of the item
                   (calculated as quntity times cost)
-------------------------------------------------------------------------------
The lass should have the following public member functions:
------------------------------------------------------------------------------------
Member Function           Description
------------------------------------------------------------------------------------
Default Constructor       Sets all the member vairables to 0
Constructor #2            Accepts an item's number, cost, and quantity as arguments
                          The function should copy these values to the appropriate
						  member variables and then call the setTotalCost function.
setItemNumber             Accepts an integer argument that is copied to the
                          itemNumber member variable
setQuantity               Accepts an integer argument that is copied to the
                          quantity member variable.
setCost                   Accepts a double argument that is copied to the cost
                          member variable.
setTotalCost              Calculates the total inventory cost for the item (quantity
                          times cost) and stores the result in totalCost.
getItemNumber             Returns the value in itemNumber.
getQuantity               Returns the value in quantity.
getCost                   Returns the value in cost.
getTotalCost              Returns the value in totalCost.
------------------------------------------------------------------------------------
Demonstrate the class in a driver program.
Input Validation: Do not accept negative values for item number, quantity, or cost.
*/

#include <iostream>
#include <iomanip>

#include "Inventory.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

void Show(const Inventory& inventory);

int main()
{
	cout << fixed << setprecision(2);

	Inventory inventory{ 1, 8, 9.99 };

	Show(inventory);

	return 0;
}

void Show(const Inventory& inventory)
{
	cout << "Item number: " << inventory.GetItemNumber() << endl;
	cout << "Quantity: " << inventory.GetQuantity() << endl;
	cout << "Item cost: $" << inventory.GetCost() << endl;
	cout << "Total cost: $" << inventory.GetTotalCost() << endl;
}