#pragma once
#include "Animal.h"

namespace animal {

	class Mosquito : public Animal
	{
	public:
		Mosquito(int x, int y);
		~Mosquito();
		void multiplication(Organism* partner);
		void collision(organism::Organism *opponent);
		void action();
		void isMosquitoAneighbour();
		bool MosquitoEscaped();
	};

}