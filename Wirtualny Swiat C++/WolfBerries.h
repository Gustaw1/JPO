#pragma once
#include "Plant.h"

namespace plant {

	class WolfBerries:public Plant
	{
	public:
		WolfBerries(int x, int y);
		~WolfBerries();
		void multiplication(int newX, int newY);
		void collision(organism::Organism* oponent);
	};

}