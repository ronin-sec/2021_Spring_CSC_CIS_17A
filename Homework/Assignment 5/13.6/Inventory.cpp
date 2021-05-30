#include "Inventory.h"

Inventory::Inventory(int itemNumber, int quantity, double cost)
	: itemNumber(0), quantity(0), cost(0.0), totalCost(0.0)
{
	SetItemNumber(itemNumber);
	SetQuantity(quantity);
	SetCost(cost);
	SetTotalCost();
}

void Inventory::SetItemNumber(int itemNumber)
{
	if (itemNumber >= 0)
		this->itemNumber = itemNumber;
}

void Inventory::SetQuantity(int quantity)
{
	if (quantity >= 0)
	{
		this->quantity = quantity;
		SetTotalCost();
	}
}

void Inventory::SetCost(double cost)
{
	if (cost >= 0)
	{
		this->cost = cost;
		SetTotalCost();
	}
}