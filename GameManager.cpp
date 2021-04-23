#include "GameManager.h"
#include "Random.h"
#include "Player.h"

GameManager::GameManager(string pName, int totalDoorsToGenerate)
{
	isGameOver = false;
	totalDoors = totalDoorsToGenerate;
	openedDoors = 0;

	// Create the doors array
	doors = new Door[totalDoors];
	
	// Create the player instance
	player = new Player(pName);

	for (int i = 1; i < totalDoorsToGenerate + 1; i++)
	{
		//set the doortype to be within the range of 0 to 1 (inclusive). See Door class for more info
		DOOR_TYPE dt = (DOOR_TYPE) GEP::RandomRange(0, 1);
		
		// Generate treasure value or... generate enemy damage value
		int randVal = 0;
		if (dt == 0) // treasure type generate between 100-500
			randVal = GEP::RandomRange(100, 500);
		else // enemy type generate dmg btwn 10-30
			randVal = GEP::RandomRange(10, 30);

		//finally, create the door object with the passed parameters, and add it to the doors array.
		doors[i].InitializeDoor(i, dt, randVal);
	}
}
/***************************************Game Manager Operations**********************************/
GameManager::~GameManager()
{
	delete[] doors;
	doors = nullptr;
}

bool GameManager::getIsGameOver()
{
	return isGameOver;
}

//Simply sets the isGameOver flag to TRUE
void GameManager::shutDown()
{
	isGameOver = true;
}

/***************************************Player Operations**********************************/
// Player Accessors
string GameManager::getPlayerName()
{
	return player->getPlayerName();
}

int GameManager::getPlayerHP()
{
	return player->getHealth();
}

int GameManager::getScore()
{
	return player->getScore();
}

// Player Setters
void GameManager::reduceHP(int damage)
{
	player->ReduceHealth(damage);
}

void GameManager::increaseScore(int score)
{
	player->AddToScore(score);
}

void GameManager::resetPlayer()
{
	player->Reset();
}

void GameManager::PrintPlayerStats()
{
	cout << "*************PLAYER STATS***************" << endl;
	cout << "Player Name: " << getPlayerName() << endl;
	cout << " Health: " << getPlayerHP() << endl;
	cout << " Money: " << getScore() << endl;
	cout << "****************************************" << endl;

}

/***************************************Door Operations**********************************/
// checks if the passed door number has already been opened or nah
bool GameManager::checkIsDoorOpen(int selectedDoor)
{
	bool check = doors[selectedDoor].getIsDoorOpened();
	return check; 
}

DOOR_TYPE GameManager::getDoorType(int selectedDoor)
{
	return doors[selectedDoor].getType();
}

int GameManager::getDoorValue(int selectedDoor)
{
	return doors[selectedDoor].getValue();
}

//call the Door toggleOpen Method to simulate opening the selected door number
void GameManager::openSelectedDoor(int selectedDoor)
{
	doors[selectedDoor].toggleDoorOpening();
}

// Prints the Door info of the selected door
void GameManager::PrintDoor(int selectedDoor)
{
	doors[selectedDoor].Print();
}

//print every single door in the array!
void GameManager::PrintAllDoors()
{
	for (int i = 0; i < totalDoors; i++)
		doors[i].Print();
}
