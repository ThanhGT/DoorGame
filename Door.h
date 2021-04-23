#pragma once

#include <iostream>
#include <string>

using namespace std;

enum DOOR_TYPE {TREASURE, ENEMY};

class Door
{
private:
	DOOR_TYPE doorType;
	int value;	//this contains either the treasure value ($$$), or damage, depending on the door type
	int doorId; //identifier for door 
	bool isDoorOpened;	//used to denote that `this` door has already been opened by the player
	int doorPicked;

public:
	Door() {}
	~Door() {}

	// Accessors
	int getDoorId() { return doorId; }
	int getValue() { return value; }
	DOOR_TYPE getType() { return doorType; }
	bool getIsDoorOpened() { return isDoorOpened; }

	// Setters
	void toggleDoorOpening();
	void InitializeDoor(int id, DOOR_TYPE dt, int val);
	void Print();
};