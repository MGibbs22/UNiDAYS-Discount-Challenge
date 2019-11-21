#include "UnidaysDiscountChallenge.h"

void UnidaysDiscountChallenge::AddToBasket(std::string item)
{
	//Checks the list of items and adds 1 to the quantity
	for (int i = 0; i < NumberOfItems; i++)
	{
		if (ListOfItems[i].ItemName == item)
		{
			ItemBasket.push_back(ListOfItems[i]);
			ListOfItems[i].Quantity += 1;
			
			break;
		}
	}
}

double *UnidaysDiscountChallenge::CalculateTotalPrice()
{
	//Initialise local variables
	double PriceOfItems = 0;
	double PriceOfDelivery = 0;
	
	for (int i = 0; i < NumberOfItems; ++i)
	{
		//A set of variables to make the following code easier to interpret
		int itemQuantity = ListOfItems[i].Quantity;
		int dealQuantity = ListOfItems[i].ItemDiscount.DealQuantity;
		double totalDealPrice = ListOfItems[i].ItemDiscount.TotalDealPrice;
		double normalItemPrice = ListOfItems[i].ItemPrice;

		if (itemQuantity != 0)
		{
			if (dealQuantity != NULL)
			{
				//Price = (deal price * whole number divisor) + (normal price * remainder)
				PriceOfItems += totalDealPrice * (int)(itemQuantity / dealQuantity) + (itemQuantity % dealQuantity) * normalItemPrice;
			}
			else
			{
				//Price = normal price * quantity of item
				PriceOfItems += normalItemPrice * itemQuantity;
			}
		}

	}

	//Check if delivery charge applies
	if (PriceOfItems < 50.0 && PriceOfItems != 0)
	{
		PriceOfDelivery = DeliveryCharge;
	}
	else
	{
		PriceOfDelivery = 0;
	}

	//Formatting the results into an array to pass back
	double Total[2] = { PriceOfItems, PriceOfDelivery };

	return Total;
}