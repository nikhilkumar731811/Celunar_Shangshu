#include "Muiro_details_declaration.h" // this is the header file.
#include "Scene1SaveSystem.h"
#include <iostream>
#include <string>
#include <conio.h> // this library is used for keyboard input functions.
#include <iomanip> // this library is used for manipulator.
#include <thread>


#include <chrono> // this library is used for time and date functions.
using namespace std;
using namespace std::chrono;

// here is the implementation of the MuiroDetails class.

void MuiroDetails::setName(string name)
{
	this->name = name;
}
void MuiroDetails::setRankName(string rankname)
{
	this->rankName = rankname;
}
void MuiroDetails::setHealth(int health)
{
	this->health = health;
}
void MuiroDetails::getName()
{
	cout << "The name of the main character is: " << name << endl;
}
void MuiroDetails::getRankName()
{
	cout << "The rankname of the main character is: " << rankName << endl;
}
void MuiroDetails::getHealth()
{
	cout << "The health of the main character is: " << health << endl;
}
void MuiroDetails::increseHealth()
{
	health += 200; // this is the health increment of the main character.
	cout << "Health recovered +200 'HP'" << endl;
	cout << "Muiro's current health is: " << health << endl;
}
//void MuiroDetails::setScene1LastHealth(int scene1LastHealth)
//{
//	this->scene1LastHealth = 500; // this is the last health of the main character in scene 1.
//}
//void MuiroDetails::getScene1LastHealth()
//{
//	cout << "Health is incremented 300 to: " << scene1LastHealth << endl;
//}
void MuiroDetails::allSetFunction() {
	setName("MUIRO");
	setRankName("D"); // D is the lowest rank in this game.
	setHealth(300); // this is the starting health of the main character.
}

void MuiroDetails::display()
{
	getName();
	getRankName();
	getHealth();
	cout << endl << endl;
}

// here is the implementation of the MuiroStartAttack class.

void MuiroStartAttack::setAttackName()
{
	attackName[0] = "Straight punch";
	attackName[1] = "Side kick";
	attackName[2] = "Finish move";
}

bool MuiroStartAttack::keyInput()
{
	if (_kbhit())
	{
		ch = _getch();
		if (ch == 'S' || ch == 's')
		{
			damage = 50;
			vHealth -= damage;
			if (vHealth <= 0)
			{
				cout << endl
					<< endl;
				cout << setw(78) << "<-------------------------------------------->" << endl;
				cout << setw(68) << "          You defeated the demon!" << endl;
				cout << setw(78) << "<-------------------------------------------->" << endl;
				increseHealth(); // this is used to increase the health of the main character after defeating the demon.
				return true;
			}

			cout << "You attacked with: " << attackName[0] << " ----> Cause damage: " << damage << endl;
			cout << setw(48) << "Demon's remaining health: " << vHealth << endl;
		}
		else if (ch == 'D' || ch == 'd')
		{
			damage = 70;
			vHealth -= damage;
			if (vHealth <= 0)
			{
				cout << endl
					<< endl;
				cout << setw(78) << "<-------------------------------------------->" << endl;
				cout << setw(68) << "          You defeated the demon!" << endl;
				cout << setw(78) << "<-------------------------------------------->" << endl;
				increseHealth(); // this is used to increase the health of the main character after defeating the demon.
				return true;
			}

			cout << "You attacked with: " << attackName[1] << " ----> Cause damage: " << damage << endl;
			cout << setw(48) << "Demon's remaining health: " << vHealth << endl;
		}
		else if (ch == 'F' || ch == 'f')
		{
			if (vHealth <= 200)
			{
				damage = 200;
				vHealth -= damage;
				if (vHealth <= 0)
				{
					cout << endl
						<< endl;
					cout << setw(78) << "<-------------------------------------------->" << endl;
					cout << setw(68) << "          You defeated the demon!" << endl;
					cout << setw(78) << "<-------------------------------------------->" << endl;
					increseHealth(); // this is used to increase the health of the main character after defeating the demon.
					return true;
				}

				cout << "You attacked with: " << attackName[2] << " ----> Cause damage: " << damage << endl;
				cout << "Demon's remaining health: " << vHealth << endl;
			}
		}
		else if (ch == 'X' || ch == 'x')
		{
			cout << "You have quit the game." << endl;
			return false; // this will break the loop and exit the game.
		}
		else if (ch == 'M' || ch == 'm')
		{
			// this is show the detials of the main character.
			display();
		}
		else if (ch == 'N' || ch == 'n')
		{
			Scene1Story scene1;   // this is show the combat controls of the game.
			scene1.getKeyboardButton();
		}
		else if (ch == 32) // this is checking is spacebar pressed or not 32 is interger value of spacebar. spacebar is not a char key so we needed to campare its interger value.
		{
			isPaused = true;
			cout << setw(103) << "\033[31mThe game is paused, for continue press: (Spacebar)\033[0m" << endl;

		}

		else
		{
			cout << "Invalid input keys. Please press 'S/s' or 'D/d'." << endl;
		}
	}

	return true; // this is used here because the function is returning a boolean value, and it will return true if the player has not quit the game.
}
void MuiroStartAttack::isGamePaused() {
	while (isPaused) {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 32) // this is also checking spacebar key 
			{
				isPaused = false;
				lastAttack = steady_clock::now();
				cout << setw(90) << "\033[35m<----Game Resumed---->\033[0m" << endl;
			}
			else {
				cout << "invalid keys please press (Spacebar) to resumed game." << endl;
			}
		}
		//this_thread::sleep_for(milliseconds(30)); // we can write it as ---> this_thread::sleep_for(chrono::milliseconds(value)). but when we used using namespace std::chrono, then no need to write it as long.

	}

}
void MuiroStartAttack::checkSceneCompletion() {

	bool demonDefeated = getAttackName();

	if (demonDefeated)
	{
		Scene1Story scene1;
		scene1.completeScene1(*this);
	}
}


bool MuiroStartAttack::getAttackName()
{
	lastAttack = steady_clock::now();
	bool isDemonDefeated = false; // this is a flag to use to print one time message F/f to finish move.


	while (health > 0 && vHealth > 0)
	{

		if (vHealth <= 200 && !isDemonDefeated)

		{

			// \033[31m Set the text color to red
			cout << right << setw(103) << "\033[31mPress 'F/f' <---- Finish move ---->\033[0m" << endl;
			// \033[0m Reset the color to defaul

			isDemonDefeated = true; // Set the flag to true to indicate that the demon can be

		}

		isGamePaused(); // this is checking when you paused game this check you pressed or not the key to resume.

		if (!keyInput()) // Call the keyInput function to get the player's input
		{
			break;
		}

		demonAttack(*this); // Call the demonAttack function to attack the player

	}
	return vHealth <= 0;


}

// here is the implementation of the Scene1Story class.

void Scene1Story::scene1Story1()
{

	story1 = "A dark forest lies beneath a heavy veil of fog.\n"
		"The trees stand silently, their twisted branches disappearing into the darkness.\n"
		"The air is cold... and strangely quiet.\n\n"
		"In the middle of the forest, a young man lies motionless on the ground.\n"
		"His body is covered in dirt, and he remains completely unconscious.\n";

	cout << story1 << endl
		<< endl;
	this_thread::sleep_for(chrono::seconds(1)); // this is used to pause the program for 9 seconds.
}
void Scene1Story::scene1Story2()
{
	story2 = "After some time, the man slowly opens his eyes.\n"
		"His vision is blurred.\n"
		"He slowly raises his head and looks around, trying to understand where he is.\n\n"

		"\"Where... am I?\"\n\n"

		"He looks around the unfamiliar forest, but there is nothing he recognizes.\n"
		"Then suddenly...\n\n"

		"Something catches his attention.\n"
		"His eyes widen.\n"
		"A horrifying sight stands before him.\n\n"

		"A demon is crouched on the ground, feeding on a human corpse.\n"
		"Blood drips from the demon's mouth and stains the ground beneath it.\n";
	cout << story2 << endl
		<< endl;
	this_thread::sleep_for(chrono::seconds(1));
}
void Scene1Story::scene1Story3(MuiroDetails& muiro)
{
	story3 = "Before he can react...\n\n"
		"The demon suddenly turns toward him.\n"
		"In an instant, it rushes forward and grabs him by the throat.\n\n"
		"Muiro struggles desperately, trying to break free.\n"
		"The demon tightens its grip around his neck.\n"
		"For a moment, everything goes silent.\n\n"
		"He realizes...\n"
		"this creature is trying to kill him.\n";
	cout << story3 << endl << endl;
	cout << "The demon's grip finally weakens. Muiro breaks free, but the struggle costs him 100 HP." << endl << endl;
	this_thread::sleep_for(chrono::seconds(1));

	muiro.display();
	this_thread::sleep_for(chrono::seconds(1)); // we can also write it as ----> this_thread::sleep_for(second(value)); <---- but we need using namespace std::chrono;
	getKeyboardButton();
	this_thread::sleep_for(chrono::seconds(1));
	system("cls");

	cout << setw(98) << "The struggle for survival begins..." << endl;
}
void Scene1Story::getKeyboardButton()
{
	keyboardButton = "Combat Controls";

	cout << keyboardButton << endl;
	cout << setw(103) << "-------------------------------------------------------------" << endl;

	cout << setw(98) << "Press 'S/s'  ----> Straight Punch  ----> Damage: 50" << endl;
	cout << setw(98) << "Press 'D/d'  ---->  Side Kick      ----> Damage: 70" << endl;
	cout << setw(80) << "Press 'X/x'  ---->  Quit the game" << endl;
	cout << setw(80) << "Press 'M/m'  ---->  Muiro details" << endl;
	cout << setw(83) << "Press 'N/n'  ---->  Keyboard Details" << endl;
	cout << setw(82) << "Press 'Spacebar' ---->  Game Paused" << endl;

	cout << setw(103) << "-------------------------------------------------------------" << endl;
	cout << endl << endl;
}

void Scene1Story::scene1StoryShow(MuiroDetails& muiro)
{
	scene1Story1();
	scene1Story2();
	scene1Story3(muiro);
}

void Scene1Story::completeScene1(MuiroDetails& muiro) {
	Scene1SaveSystem saveSystem;
	cout << "Scene1 complete" << endl;
	saveSystem.saveHealth(muiro);

}

// here is the implementation of the FirstDemon class.

void FirstDemon::setDemonHealth(int vHealth)
{
	this->vHealth = 700; // this is the max health of the demon.
}
// void FirstDemon::getDemonHealth()
// {
//     cout << "Demon Health: " << vHealth << endl;
// }
void FirstDemon::setvDamage(int vDamage)
{
	this->vDamage = 65; // this is the max damage of the demon. 
}
void FirstDemon::show()
{
	setDemonHealth(vHealth);
	setvDamage(vDamage);
}
void FirstDemon::demonAttack(MuiroDetails& muiro)
{
	auto currentAttack = steady_clock::now();
	auto elapsed = duration_cast<seconds>(currentAttack - lastAttack).count();

	if (elapsed >= 3)
	{
		muiro.health -= vDamage;
		if (muiro.health <= 0)
		{
			cout << endl
				<< endl;

			cout << setw(78) << "<--------------------------------------------------->" << endl;
			cout << setw(70) << "   You have been defeated by the demon!" << endl;
			cout << setw(78) << "<--------------------------------------------------->" << endl;
			//cout <<  muiro.health << endl; // this is only printed to check function is working or not
			//cout << vHealth << endl;
			return;
		}
		cout << "Demon attacked! with the damage: " << vDamage << " ----> Your remaining health: " << muiro.health << endl;
		lastAttack = currentAttack;
	}
}