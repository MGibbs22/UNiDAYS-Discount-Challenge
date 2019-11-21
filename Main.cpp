#include "UnidaysDiscountChallenge.h"

int main()
{
	//Declared Items in the form {Name, Price, Discount}
	//Discounts in the form {Quantity, Total Price}
	std::vector<UnidaysDiscountChallenge::Item> PriceRules;
	PriceRules.push_back({ "A", 8.0, NULL});
	PriceRules.push_back({ "B", 12.0, {2,20.0}});
	//For example item C is £4.00 on a 2 for £20.00 deal
	PriceRules.push_back({ "C", 4.0, {3,10.0}});
	PriceRules.push_back({ "D", 7.0, {2,7.0}});
	PriceRules.push_back({ "E", 5.0, {3,10.0}});
	//PriceRules.push_back( ADD PARAMETERS HERE );

	//Construct the class passing vector of item price rules
	UnidaysDiscountChallenge example(PriceRules);

	//Add items to basket here
	example.AddToBasket("A");
	example.AddToBasket("B");
	example.AddToBasket("C");
	example.AddToBasket("D");
	example.AddToBasket("E");
	//More can go here

	//Calculates the total price including shipping
	double *result = example.CalculateTotalPrice();

	//These values are worked out as suggested
	double totalPrice = *result;
	double deliveryCharge = *(result + 1);
	double overallCost = totalPrice + deliveryCharge;

	//Outputs total prices with x9C being the Unicode value for £
	std::cout << "Total Price: \x9C" << totalPrice << "\nTotal Price with Delivery: \x9C" << deliveryCharge << std::endl;
	std::cout << "Overall Total: \x9C" << overallCost << std::endl;

}
