#include <iostream>
#include "GameManager.h"
#include "Door.h"

/* Guess the Door Game
The game is initialized with X doors.
When you open each door, there is a possibility of either having some dollars or an enemy
If you find some dollars behind the door, you get to keep them.
If you find an enemy waiting for you behind the door, the enemy attacks you and your health gets reduced with the damage
value associated with that enemy
Game End Condition:
i) When all doors opened and your health remains greater than 0
OR
ii) your health goes down to 0 (and there are still other doors remaining)
*/

int main()
{
	int numOfDoors;
	int doorPicked;
	int numOfDoorsOpened = 0;
	bool isAssigningDoorCount = true;	// flag used to determine if user is in the generate door state. Set to FALSE, once user is passed that
	string playerName;
	string choice;

	cout << "****Welcome to the Guess the Door Game!*****" << endl;
	
	// Set the Player Name
	cout << "Enter your name.";
	cin >> playerName;

	// generate number of doors based on user input. Trap the user in a loop until they give a good numberofDoors value.	
	while (isAssigningDoorCount)
	{
		cout << "How many doors would you like to generate? ";
		cin >> numOfDoors;

		//also make sure that numOfDoors is actually an int lol...

		// Make sure that numOfDoors is greater than 0.
		if (numOfDoors <= 0)
		{
			// Give the user a "u is dum" errror. And start the loop again.
			cout << "Invalid number of doors. Please select a number greater than zero.";
			continue;
		}
		else
		{
			// Otherwise, the input is valid (i.e. the number of doors is greater than 0) so continue on with the game
			isAssigningDoorCount = false;	// Set to FALSE to continue to next step
		}
	}

	// Now that we have a good numOfDoors value, we can now create the Game Manager instance.
	GameManager* gMgr = new GameManager(playerName, numOfDoors);	

	// Gameplay loop until Game is Over...
	while ( !(gMgr->getIsGameOver()) )
	{
		cout << "Which door would you like to open (choose between 1 - " << numOfDoors << ")? ";

		// Prompt the user for a door number
		cin >> doorPicked;
		cout << "You chose to open door #" << doorPicked << " " << endl;

		//If-statement block! Check for certain conditions to make sure the game can continue appropriately.

		// Check if the doorPicked is within the range of the total number of doors
		if (doorPicked <= 0 || doorPicked > numOfDoors)
		{
			cout << "That's not an existing door... Try again.";
			continue;
		}

		// Check that the selected door has not already been opened
		else if (gMgr->checkIsDoorOpen(doorPicked))
		{
			cout << "That door is already opened... Try again ";			
			continue;
		}
		// Otherwise, the door selected has not already been opened, so
		else
		{			
			// Open it!
			gMgr->openSelectedDoor(doorPicked);
			
			// Also, print that door's info
			gMgr->PrintDoor(doorPicked);					

			// Also also, increment the number of doors that have now been opened. Used for below.
			numOfDoorsOpened++;
		}

		/* Apply Door Damage or Treasure values */
		// First check the door type
		
		if (gMgr->getDoorType(doorPicked) == 0)
		{
			//treasure type, so add the door value to the player score
			gMgr->increaseScore(gMgr->getDoorValue(doorPicked));
			
		}
		else
		{
			//enemy type so damage player HP by door value
			gMgr->reduceHP(gMgr->getDoorValue(doorPicked));

			//TODO: Display Player Stats Here
			gMgr->PrintPlayerStats();

			// Now check if player is still alive
			if (gMgr->getPlayerHP() <= 0)
			{
				//player is dead so shut it all down
				gMgr->shutDown();
			}
		}

		// Now, check if there are still any doors that need to be opened.
		if (numOfDoorsOpened < numOfDoors)
		{
			// If so, ask the user if they want to keep playing
			cout << "Would you like to keep playing (yes/no)? ";
			cin >> choice;

			if (choice.compare("yes"))
			{
				gMgr->shutDown();
			}
			else
			{
				continue;
			}
		}
		// Otherwise, end the game cuz u out of doors son
		else
		{
			cout << "There are no more doors to open. Congratulations!! You win?";
			gMgr->shutDown();
		}
	}
	
	// Once Game is Over... do what?
	cout << "Game Over";

	return 0;
}

