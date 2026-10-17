#include "Muiro_details_declaration.h"
#include "Scene1SaveSystem.h"
#include <iostream>

using namespace std;

int main()
{ // this code is temporary to check save system 
    MuiroStartAttack a;
    a.allSetFunction(); // this is call because details are fixed and solved duplication problem that is why it is call here.
    a.show();
    a.setAttackName();
    a.scene1StoryShow(a);
    
    a.checkSceneCompletion();
    //bool demonDefeated = a.getAttackName();
    //if (demonDefeated)
    //{
    //    a.completeScene1(a); 
    //}
    

    // this is original code
	//MuiroStartAttack a;
    //a.allSetFunction();
    //a.show();
	//a.setAttackName();
	//a.scene1StoryShow(a);
	//a.getAttackName();



	return 0;
}