#include "GroceryItem.h"
#include <iostream>
#include <string>

using namespace std;

void GroceryItem::SetItemCount(int count) {
	this->itemQuantity = count;
}

void GroceryItem::PrintItemDetails() {
	std::cout << this->itemName << ": Quantity of " << this->itemQuantity << endl;
}
void GroceryItem::SetItemName(string name) {
	this->itemName = name;
}
string GroceryItem::GetItemName() {
	return this->itemName;
}
int GroceryItem::GetItemCount() {
	return this->itemQuantity;
}