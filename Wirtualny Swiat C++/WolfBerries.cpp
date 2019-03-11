#include "WolfBerries.h"
#include "World.h"

namespace plant {

	WolfBerries::WolfBerries(int x, int y)
	{
		this->x = x;
		this->y = y;
		symbol = 'w';
	}


	WolfBerries::~WolfBerries()
	{
		world->log.push_back("WolfBerries eaten");
	}

	void WolfBerries::multiplication(int newX, int newY) {
		onMap[newX][newY] = new WolfBerries(newX, newY);
		//pojawianie sie w swiecie i komunikaty
		onMap[newX][newY]->setWorld(*world);
		world->organisms.push_back(onMap[newX][newY]);
		world->log.push_back("multiplication of WolfBerries");

	}
	void WolfBerries::collision(organism::Organism* oponent) {
		oponent->setAlive(false);
		//komunikaty
		std::string comment;
		comment = "WolfBerries killed: ";
		world->log.push_back(comment += oponent->getSymbol());

	}

}