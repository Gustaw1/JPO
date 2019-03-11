#pragma once
#include "Organism.h" 

namespace plant {

	class Plant : public organism::Organism
	{
	public:
		Plant();
		virtual ~Plant();

		virtual void action();
		virtual void collision(organism::Organism *opponent);
		virtual void multiplication(Organism* partner);
		virtual void multiplication(int newX, int newY) = 0;
	};

}