#include "Muiro_details_declaration.h"
#include "Scene1SaveSystem.h"
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

bool Scene1SaveSystem::loadHealth( MuiroDetails& muiro) {
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