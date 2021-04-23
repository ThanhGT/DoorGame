#pragma once
#include "Door.h"
#include "Player.h"
#include <iostream>

using namespace std;

class GameManager
{
private:
	bool isGameOver;

	//dynamically allocated array of doors
	Door* doors;
	
	//Assign the Player instance
	Player* player;

	//how many doors in the game?
	int totalDoors;
	//how many doors opened?
	int openedDoors;	

public:
	GameManager(string pname, int totalDoorToGenerate);
	~GameManager();
	bool getIsGameOver();
	void shutDown();

	/*************Player Operations**********/
	//Setters
	void reduceHP(int damage);
	void increaseScore(int score);
	void resetPlayer();
	void PrintPlayerStats();

	//Accessors
	string getPlayerName();
	int getPlayerHP();
	int getScore();

	/*************Door Operations**********/
	//Setters
	void openSelectedDoor(int selectedDoor);
	void PrintDoor(int selectedDoor);
	void PrintAllDoors();

	//Accessors
	bool checkIsDoorOpen(int selectedDoor);
	DOOR_TYPE getDoorType(int selectedDoor);
	int getDoorValue(int selectedDoor);
	int getOpenedDoorsCount() {return openedDoors;}
	int getTotalDoorsCount() { return totalDoors; }
	int getRemainingDoorsCount() { return totalDoors - openedDoors; }

};
