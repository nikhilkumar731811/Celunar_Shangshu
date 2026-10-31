#pragma once

#include <string>
#include <vector>

struct InventoryItem {
	std::string itemName;
	std::string itemType;
	int gameplayValue;
	int quantity;

};

class InventorySystem {
	std::vector<InventoryItem> items;
	int maxCapacity;
public:
	void addItem(const InventoryItem& item);
	InventorySystem(int Capacity); // this is constructor
	void displayInventory();
	void removeItem(const std::string& itemName, const std::string& itemType,int gameplayValue, int amount);


};	
