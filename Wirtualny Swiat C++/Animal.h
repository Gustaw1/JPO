#pragma once
#include "Organism.h"

namespace animal {

	class Animal : public organism::Organism
	{
	public:
		Animal();
		virtual ~Animal();
	protected:
		virtual void action();
		virtual void collision(organism::Organism *opponent) = 0;
		virtual void multiplication(Organism* partner);
		virtual void multiplication(int newX, int newY);
	};

}