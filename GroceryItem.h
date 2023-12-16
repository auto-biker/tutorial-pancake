#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <cstring>
#include <iostream>
#include <string>

class GroceryItem
{
public:
	void SetItemCount(int count);
	void SetItemName(std::string name);
	std::string GetItemName();
	int GetItemCount();
	void PrintItemDetails();
private:
	int itemQuantity;
	std::string itemName;
};

#endif