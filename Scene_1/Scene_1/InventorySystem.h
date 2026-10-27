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
	void add(const InventoryItem& item);

};	
