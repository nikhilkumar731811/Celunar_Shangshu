#pragma once
class MuiroDetails;
class InventorySystem;
class Scene1SaveSystem {
public:
	void saveHealth(const MuiroDetails& muiro);
	bool loadHealth(MuiroDetails& muiro);
	void saveInventory(const InventorySystem& inventory);
	void saveScene1(const MuiroDetails& muiro, const InventorySystem& inventory);
		
};