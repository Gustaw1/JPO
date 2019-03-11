#pragma once
#include "Animal.h"

namespace animal {

	class Wolf : public Animal
	{
	public:
		Wolf(int x, int y);
		~Wolf();
		void multiplication(Organism* partner);
		void collision(organism::Organism *opponent);
	};

}