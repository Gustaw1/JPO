#pragma once
#include "Plant.h"

namespace plant {

	class Guarana : public Plant
	{
	public:
		Guarana(int x, int y);
		~Guarana();
		void multiplication(int newX, int newY);
		void collision(organism::Organism* oponent);
	};

}