#include"WeaponDetailsSystem.h"
#include "InventorySystem.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

WeaponDetailsSystem::WeaponDetailsSystem() {
	// Initialize the weapons vector with some weapon details
	weapons.push_back({ "Knife", 50 });
	weapons.push_back({ "Axe", 100 });
	weapons.push_back({ "Spear", 150 });
	weapons.push_back({ "Double Daggers", 250 });
	weapons.push_back({ "Giant Chakra", 300 });
	weapons.push_back({ "Sword of Death", 500 });
}

// here is the implementation of the WeaponDetailsSystem class.

// WeaponDetails* --> this is the return type of this function. It returns a pointer to a WeaponDetails object.
WeaponDetails* WeaponDetailsSystem::getWeaponDetails(int index) {
	if (index >= 0 && index < weapons.size()) {
		return &weapons[index];
	}
	
	return nullptr; // Return nullptr if the index is out of bounds
	
}
int WeaponDetailsSystem::getTotalWeapons() {
	return weapons.size();
}


// here is the implementation of the WeaponDropSystem class.
WeaponDropSystem::WeaponDropSystem(WeaponDetailsSystem& details, InventorySystem& inv) // this is new initialization of constuctor values.
	: weaponDetails(details), inventory(inv) {
}
void WeaponDropSystem::dropKnife() {
	WeaponDetails* knifeDetails = weaponDetails.getWeaponDetails(0); // Get the details of the knife (index 0)

	if (knifeDetails == nullptr) {
		return;

	}
	cout << "Dropping Knife..." << endl;
	cout << "Weapon Name: " << knifeDetails->weaponName << endl;
	cout << "Weapon Damage: " << knifeDetails->weaponDamage << endl;
	
	char choice;

	while (true) {
		cout << "Press 'P/p' to pick up the knife, You must: ";
		
		choice = _getch();

		if (choice == 'P' || choice == 'p') {
			// this is initialization of new method.

			//InventoryItem this is sturcture  and knifeitem is a object of inventory.
			InventoryItem knifeItem = { knifeDetails->weaponName, "Weapon", knifeDetails->weaponDamage, 1 };
			inventory.addItem(knifeItem);
			cout << endl;
			cout << "Knife added to inventory." << endl;
			break;
		}
		
		else {
			cout << " invalid input. Please press 'P/p' or 'I/i'." << endl;
		}
	}
	
}