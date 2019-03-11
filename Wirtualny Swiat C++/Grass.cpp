#include "Grass.h"
#include "World.h"

namespace plant {

	Grass::Grass(int x, int y)
	{
		this->x = x;
		this->y = y;
		symbol = 'g';
	}


	Grass::~Grass()
	{
		world->log.push_back("Grass eaten");
	}

	void Grass::multiplication(int newX, int newY) {
		onMap[newX][newY] = new Grass(newX, newY);

		onMap[newX][newY]->setWorld(*world);
		world->organisms.push_back(onMap[newX][newY]);
		world->log.push_back("multiplication of grass");
		
	}

}