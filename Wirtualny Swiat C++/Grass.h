#pragma once
#include "Plant.h"

namespace plant {

	class Grass:public Plant {
	public:
		Grass(int x, int y);
		~Grass();
		void multiplication(int newX, int newY);
	};

}