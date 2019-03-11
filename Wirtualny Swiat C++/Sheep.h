#pragma once
#include "Animal.h"

namespace animal {

	class Sheep : public Animal
	{
	public:
		Sheep(int x, int y);
		~Sheep();
		void multiplication(Organism* partner);
		void collision(organism::Organism *opponent);
	};

}