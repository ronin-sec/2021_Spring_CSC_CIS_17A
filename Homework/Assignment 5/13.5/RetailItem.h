#include <string>

using std::string;

class RetailItem
{
private:
	string description;
	int unitsOnHand;
	double price;

public:
	RetailItem(const string& description, int unitsOnHand, double price)
		: description(description), unitsOnHand(unitsOnHand), price(price)
	{ }

	void SetDescription(const string& description) { this->description = description; }
	void SetUnitsOnHand(int unitsOnHand) { this->unitsOnHand = unitsOnHand; }
	void SetPrice(double price) { this->price = price; }

	string GetDescription() const { return description; }
	int GetUnitsOnHand() const { return unitsOnHand; }
	double GetPrice() const { return price; }
};