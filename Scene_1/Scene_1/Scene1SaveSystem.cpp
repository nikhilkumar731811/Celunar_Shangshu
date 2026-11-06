#include "Muiro_details_declaration.h"
#include "Scene1SaveSystem.h"
#include "InventorySystem.h"
#include <iostream>
#include <fstream>
using namespace std;

void Scene1SaveSystem::saveHealth(const MuiroDetails& muiro) {

	ofstream savefile("scene1_save.txt");

	if (!savefile.is_open()) {
		cout << "unable to save muiro health" << endl;
		return;

	}
	savefile << muiro.health;
	if (savefile) {
		cout << "muiro health saved successfully" << endl;
	}
	else {
		cout << "Failed to write Muiro's health!" << endl;
	}
}

bool Scene1SaveSystem::loadHealth(MuiroDetails& muiro) {
	ifstream savefile("scene1_save.txt");
	if (!savefile.is_open()) {
		cout << "no save file found" << endl;
		return false;
	}
	int savedHealth;
	if (!(savefile >> savedHealth)) {
		cout << "Unable to read saved health." << endl;
		return false;
	}
	if (savedHealth < 0) {
		cout << "saved health is invalid" << endl;
		return false;

	}
	muiro.setHealth(savedHealth);

	cout << "Muiro's health loaded: "
		<< savedHealth << " HP" << endl;

	return true;
}

void Scene1SaveSystem::saveInventory(const InventorySystem& inventory) {
	ofstream savefile("scene1_save.txt", ios::app); // ios::app is used to append the inventory data to the existing save file.
	if (!savefile.is_open()) {
		cout << "Unable to save inventory." << endl;
		return;
	}
	const vector<InventoryItem>& items = inventory.getItems();
	savefile << "\nInventory:" << endl;
	for (const InventoryItem& item : items) {
		savefile << "Item Name: " << item.itemName << " "
			<< "Item Type: " << item.itemType << " "
			<< "Item Value: " << item.gameplayValue << " "	
			<< "Item Quantity: " << item.quantity << endl;
	}
	cout << "Inventory saved successfully." << endl;
}

void Scene1SaveSystem::saveScene1(
	const MuiroDetails& muiro,
	const InventorySystem& inventory)
{
	ofstream savefile("scene1_save.txt");

	if (!savefile.is_open()) {
		cout << "Unable to save Scene 1 data." << endl;
		return;
	}

	// Save Muiro's health
	savefile << muiro.health << endl;

	// Get inventory items
	const std::vector<InventoryItem>& items = inventory.getItems();

	savefile << "Inventory:" << endl;

	// Save each inventory item
	for (const InventoryItem& item : items) {

		savefile << "Item Name: " << item.itemName << " "
			<< "Item Type: " << item.itemType << " "
			<< "Item Value: " << item.gameplayValue << " "
			<< "Item Quantity: " << item.quantity << endl;
	}

	if (savefile) {
		cout << "Scene 1 data saved successfully." << endl;
	}
	else {
		cout << "Failed to save Scene 1 data." << endl;
	}
}