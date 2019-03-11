#include "Guarana.h"
#include "World.h"

namespace plant {

	Guarana::Guarana(int x, int y)
	{
		this->x = x;
		this->y = y;
		symbol = 'u';
	}


	Guarana::~Guarana()
	{
		world->log.push_back("Guarana eaten");
	}

	void Guarana::multiplication(int newX, int newY) {
		onMap[newX][newY] = new Guarana(newX, newY);
		onMap[newX][newY]->setWorld(*world);
		world->organisms.push_back(onMap[newX][newY]);
		world->log.push_back("multiplication of Guarana");
	}

	void Guarana::collision(organism::Organism* oponent) {
		oponent->setStrength(3);

		world->log.push_back("Guarana increased oponents strength by 3");
	}
}
