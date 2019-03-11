#include "Wolf.h"
#include "World.h"

namespace animal {

	Wolf::Wolf(int x, int y)
	{
		this->x = x;
		this->y = y;
		initiative = 5;
		strength = 9;
		symbol = 'W';
	}
	
	Wolf::~Wolf()
	{
		world->log.push_back("The Wolf died");
	}

	void Wolf::multiplication(organism::Organism *partner) {

		bool place_on_map = false;
		int px = partner->getX();
		int py = partner->getY();
		
		//						1		2		3		 4			5			  6       // punkty sasiadujace ze zwierzetami
		int neighbour_x[] = { x		,	x	 ,  x - 1,	px		,	px		,	px + 1	};
		int neighbour_y[] = { y + 1  , y - 1  ,	y	 ,	py + 1	,	py - 1	,     py	};

		//Sprawdzenie czy jest miejsce na mapie

		int i = 0;
		for (i ; i < 6; i++) {
			if (neighbour_x[i] >= 0 && neighbour_x[i] < 20 && 
				neighbour_y[i] >= 0 && neighbour_y[i] < 20 && 
				onMap[neighbour_x[i]][neighbour_y[i]] == nullptr)
			{
				place_on_map = true;
				break;
			}
		}

		if (place_on_map) {
			onMap[neighbour_x[i]][neighbour_y[i]] = new Wolf(neighbour_x[i],neighbour_y[i]);
			onMap[neighbour_x[i]][neighbour_y[i]]->setWorld(*world);
			world->organisms.push_back(onMap[neighbour_x[i]][neighbour_y[i]]);
			world->log.push_back("The birth of a Wolf");
		}


	}

	void Wolf::collision(organism::Organism *opponent) {
		
	}
}