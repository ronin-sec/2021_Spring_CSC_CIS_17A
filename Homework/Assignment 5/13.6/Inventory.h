#pragma once

class Inventory
{
private:
	int itemNumber;
	int quantity;
	double cost;
	double totalCost;

public:
	Inventory()
		: itemNumber(0), quantity(0), cost(0.0), totalCost(0.0)
	{ }

	Inventory(int itemNumber, int quantity, double cost);

	void SetItemNumber(int itemNumber);
	void SetQuantity(int quantity);
	void SetCost(double cost);
	void SetTotalCost() { totalCost = quantity * cost; }

	int GetItemNumber() const { return itemNumber; }
	int GetQuantity() const { return quantity; }
	double GetCost() const { return cost; }
	double GetTotalCost() const { return totalCost; }
};
