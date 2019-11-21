#include <iostream>
#include <vector>

class UnidaysDiscountChallenge
{

public:
	//Private Structures
	struct Discount
	{
		//Quantity to make deal, deal price
		int DealQuantity;
		double TotalDealPrice;
	};

	struct Item
	{
		//Name, price, discount, quantity
		std::string ItemName;
		double ItemPrice;
		UnidaysDiscountChallenge::Discount ItemDiscount;
		int Quantity;
	};

private:
	
	//Variable initialisation for the class methods
	int NumberOfItems;
	std::vector<Item> ListOfItems;

	//Vector for the basket size
	std::vector<Item> ItemBasket;

	//Constant delivery charge
	const double DeliveryCharge = 7.0;

public:
	//Constructor
	UnidaysDiscountChallenge(std::vector<Item> PriceRules)
	{
		NumberOfItems = PriceRules.size();
		for (int i = 0; i < NumberOfItems; i++)
		{
			ListOfItems.push_back(PriceRules[i]);
		}
		
	};
	//2 public functions as specified
	void AddToBasket(std::string item);
	double *CalculateTotalPrice();

	};

