#pragma once
#include "Animal.h"

namespace animal {
	class Elephant : public Animal
	{
	public:
		Elephant(int x, int y);
		~Elephant();
		void multiplication(Organism* partner);
		void collision(organism::Organism *opponent);
	};

}