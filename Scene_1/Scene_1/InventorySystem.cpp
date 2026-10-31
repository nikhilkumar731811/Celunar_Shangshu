#include "InventorySystem.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


void InventorySystem::addItem(const InventoryItem& item) {

	for (int i = 0; i < items.size();i++) {
		if (items[i].itemName == item.itemName && items[i].gameplayValue == item.gameplayValue && items[i].itemType == item.itemType) {
			items[i].quantity += item.quantity;
			return;
		}

	}
	

	if (items.size() >= maxCapacity) {
		cout << "Inventory is full" << endl;
		return;
	}
	items.push_back(item);
	
}

// this is constructor to check immediatly capicty of inventory
InventorySystem::InventorySystem(int capacity) {
	maxCapacity = capacity;

}
void InventorySystem::displayInventory() {
	cout << "\n====MUIRO'S INVENTORY====\n";
	for (int i = 0; i < items.size(); i++) {
		if (items[i].quantity > 0) {
			cout << "Item Name: " << items[i].itemName << endl;
			cout << "Item Type: " << items[i].itemType << endl;
			cout << "Item Value: " << items[i].gameplayValue << endl;
			cout << "Item Quantity: " << items[i].quantity << endl;
			cout << endl;
		}
	}
}

void InventorySystem::removeItem(const string& itemName, const std::string& itemType,int gameplayValue, int amount) {
	for (int i = 0; i < items.size(); i++) {
		if (items[i].itemName == itemName && items[i].itemType == itemType && items[i].gameplayValue == gameplayValue) {
			if (items[i].quantity >= amount) {
				items[i].quantity -= amount;
				cout << "Item Quantity updated" << endl;
			}
			else {
				cout << "Not enough quantity" << endl;
			}
			return;
		}
	}
	cout << "Item Not Found" << endl;
}