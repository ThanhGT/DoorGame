#include "Door.h"

//toggles whether the door has been opened (TRUE) or closed (FALSE)
void Door::toggleDoorOpening()
{
	if (isDoorOpened) 
	{ 
		isDoorOpened = false; 
	}
	else 
	{ 
		isDoorOpened = true; 
	}
}

void Door::InitializeDoor(int id, DOOR_TYPE dt, int val)
{
	doorType = dt;
	value = val;
	doorId = id;
	isDoorOpened = false;
}

void Door::Print()
{
	cout << "Door No. " << getDoorId() << " Door Type " << getType() << " | value " << getValue() << endl;
}

