/*
5. RetailItem Class
Write a class named RetailItem that holds data about an item in a retail store. The
class should have the following member variables:
- description - a string that holds a brief description of the item
- unitsOnHand - an int that holds the number of units currently in inventory
- price - a double that holds the item's retail price
Write a constructor that accepts arguments for each member variable, appropriate mutator
functions that store values in these member variables, and accessor functions that
return the values in these member variables. Once you have written the class, write a separate
program that creates three RetailItem objects and stores the following data in them:
------------------------------------------------------
         Description        Units On Hand        Price
------------------------------------------------------
Item #1  Jacket             12                   59.95
Item #2  Designer Jeans     40                   34.95
Item #3  Shirt              20                   24.95
------------------------------------------------------
*/

#include <iostream>
#include <iomanip>

#include "RetailItem.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
	RetailItem item1{ "Jacket", 12, 59.95 };
	RetailItem item2{ "Designer Jeans", 40, 34.95 };
	RetailItem item3{ "Shirt", 20, 24.95 };

	cout << "Item #1: \n";
	cout << "\t Description: " << item1.GetDescription() << endl;
	cout << "\t Units on hand: " << item1.GetUnitsOnHand() << endl;
	cout << "\t Price: $" << item1.GetPrice() << "\n\n";

	cout << "Item #2: \n";
	cout << "\t Description: " << item2.GetDescription() << endl;
	cout << "\t Units on hand: " << item2.GetUnitsOnHand() << endl;
	cout << "\t Price: $" << item2.GetPrice() << "\n\n";

	cout << "Item #3: \n";
	cout << "\t Description: " << item3.GetDescription() << endl;
	cout << "\t Units on hand: " << item3.GetUnitsOnHand() << endl;
	cout << "\t Price: $" << item3.GetPrice() << endl;

	return 0;
}