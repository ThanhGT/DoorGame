#pragma once

#include<string>

using namespace std;

class Player
{

private:
		string playerName;
		int health;
		int score;
		float money;

public:
	Player(string pName) { playerName = pName; health = 100; score = 0; }
	~Player() { }

	/***Getters/Acessors ***/
	string getPlayerName() { return playerName; }
	int getHealth() { return health; }
	int getScore() { return score; }

	// Member functions
	void AddToScore(int points) { score += points; }
	void ReduceHealth(int h) { health -= h; }
	void Reset() { health = 100; score = 0; }
};