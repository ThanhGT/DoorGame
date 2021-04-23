#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double* players = nullptr; // to dynamically allocate an array
	double sum = 0.0;
	double avg;
	
	int numDays;

	cout << "How many days of player data do you wish to process?";
	cin >> numDays;
	
	//Dynamically allocate an array large enough to hold that many days of data 
	players = new double[numDays]; //allocates memory

	cout << "Enter the player figures below (How many players played your game each day): ";

	// Get user input through a for loop
	for (int i = 0; i < numDays; i++)
	{
		cout << "Day " << (i + 1) << ": ";
		cin >> players[i];
		sum += players[i];
		
	}
	
	avg = sum / numDays;

	//Display results:
	cout << setprecision(1) << fixed;

	cout << "Total Player: " << sum << endl;
	cout << "Avg Players/day " << avg << endl;

	cout << "Total Player: " << sum << endl;
	cout << "Avg players/day" << avg << endl;

	// Free the dynamically allocated memory
	delete[] players;
	players = nullptr;

	// return 0;
}