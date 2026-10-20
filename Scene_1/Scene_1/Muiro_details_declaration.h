#pragma once
#include <string>
#include <chrono>

class MuiroDetails
{

public:
	std::string name;
	std::string rankName;
	int health;
	int scene1LastHealth;
	void setName(std::string name);
	void setRankName(std::string rankname);
	void setHealth(int health);
	void getName();
	void getRankName();
	void getHealth();
	void increseHealth();
	//void setScene1LastHealth(int scene1LastHealth);
	//void getScene1LastHealth();
	void allSetFunction();
	void display();
};

class FirstDemon
{

public:
	int vHealth;
	int vDamage;
	std::chrono::steady_clock::time_point lastAttack;
	void setDemonHealth(int vHealth);
	// void getDemonHealth();
	void setvDamage(int vDamage);
	void show();
	void demonAttack(MuiroDetails& muiro);
};

class Scene1Story
{
	std::string story1;
	std::string story2;
	std::string story3;
	std::string keyboardButton;

public:
	void scene1Story1();
	void scene1Story2();
	void completeScene1(MuiroDetails& muiro);
	void getKeyboardButton();
	void scene1Story3(MuiroDetails& muiro);
	void scene1StoryShow(MuiroDetails& muiro);
};

class MuiroStartAttack : public MuiroDetails, public FirstDemon, public Scene1Story
{
	std::string attackName[3];
	char ch;
	int damage;
	int finalHealth;
	bool isPaused = false;



public:
	bool keyInput();
	void setAttackName();
	bool getAttackName();
	void isGamePaused();
	void checkSceneCompletion();
};
