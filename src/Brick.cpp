#include <iostream>
#include "Brick.h"

class Brick
{
	private :

	int value;
	vector<int> position(2);

	public :

	void Brick::setValue(int value)
	{
		this.vale = value;
	}

	int Brick::getValue()
	{
		return this.value;
	}
}
