#pragma once
#include "InventorySystem.h"
#include <string>
#include <vector>

struct WeaponDetails {
	std::string weaponName;
	int weaponDamage;
	
};

class WeaponDetailsSystem {

	std::vector<WeaponDetails> weapons;
	public: 
		WeaponDetailsSystem();
		WeaponDetails* getWeaponDetails(int index);
		int getTotalWeapons();

};

class WeaponDropSystem {
	WeaponDetailsSystem& weaponDetails;
	InventorySystem& inventory;

public:
	WeaponDropSystem(WeaponDetailsSystem& details, InventorySystem& inv);
	void dropKnife();

	// this is future implementation of other weapons drop system.
	/*
	void dropAxe();
	void dropSpear();
	void dropDoubleDagger();
	void dropGiantChakra();
	void dropSwordOfDeath();
	*/
	
};