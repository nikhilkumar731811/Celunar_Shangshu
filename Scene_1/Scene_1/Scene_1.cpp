#include "Muiro_details_declaration.h"
#include "Scene1SaveSystem.h"
#include "InventorySystem.h"
#include "WeaponDetailsSystem.h"
#include <iostream>

using namespace std;

int main()
{ 

    




	// THSI is the code of main story of the game.

	MuiroStartAttack a;
	a.allSetFunction(); // this is call because details are fixed and solved duplication problem that is why it is call here.
	a.show();
	a.setAttackName();
	a.scene1StoryShow(a);
	a.checkSceneCompletion();
	





	return 0;
}