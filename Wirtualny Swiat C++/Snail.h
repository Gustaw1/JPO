#pragma once
#include "Animal.h"

namespace animal {
	class Snail : public Animal
	{
	public:
		Snail(int x, int y);
		~Snail();
		void multiplication(Organism* partner);
		void collision(organism::Organism *opponent);
		void action();
		
	};

}