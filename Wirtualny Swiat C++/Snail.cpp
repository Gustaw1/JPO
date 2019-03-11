#include "Snail.h"
//slimak
#include "World.h"

namespace animal {

	Snail::Snail(int x, int y)
	{
		this->x = x;
		this->y = y;
		initiative = 1;
		strength = 1;
		symbol = 'N';
	}

	Snail::~Snail()
	{
		world->log.push_back("The Snail died");
	}

	void Snail::multiplication(organism::Organism *partner) {

		bool place_on_map = false;
		int px = partner->getX();
		int py = partner->getY();

		//						1		2		3		 4			5			  6       // punkty sasiadujace ze zwierzetami
		int neighbour_x[] = { x		,	x	 ,  x - 1,	px		,	px		,	px + 1 };
		int neighbour_y[] = { y + 1  , y - 1  ,	y	 ,	py + 1	,	py - 1	,     py };

		//Sprawdzenie czy jest miejsce na mapie

		int i = 0;
		for (i; i < 6; i++) {
			if (neighbour_x[i] >= 0 && neighbour_x[i] < 20 &&
				neighbour_y[i] >= 0 && neighbour_y[i] < 20 &&
				onMap[neighbour_x[i]][neighbour_y[i]] == nullptr)
			{
				place_on_map = true;
				break;
			}
		}

		if (place_on_map) {
			onMap[neighbour_x[i]][neighbour_y[i]] = new Snail(neighbour_x[i], neighbour_y[i]);
		}

		//TO DO setswiat i komunikaty
	}

	void Snail::action() {

		int change_place = rand() % 100;
		//w 90% przypadkach nie zmienia swojego polozenia
		if (change_place < 10) {

			const int size = 20;

			//ka¿de typowe zwierze w swojej turze przesuwa siê na wybrane losowo, s¹siednie pole

			int multiplication_direction = rand() % 4; //cztery mozliwe kierunki

			int temp_x = x;
			int temp_y = y;

			//ruch w gore
			if ((multiplication_direction == 0) && (y > 0)) {
				temp_y -= 1;
			}
			//ruch w dol
			else if ((multiplication_direction == 1) && (y < size - 1)) {
				temp_y += 1;
			}
			//ruch w lewo
			else if ((multiplication_direction == 2) && (x > 0)) {
				temp_x -= 1;
			}
			//ruch w prawo
			else if ((multiplication_direction == 2) && (x > size - 1)) {
				temp_x += 1;
			}

			//Rozne mozliwosci
			//brak kolizji -> przejscie na wylosowane pole
			if (onMap[temp_x][temp_y] == nullptr) {
				onMap[temp_x][temp_y] = onMap[x][y];
				onMap[x][y] = nullptr;
				x = temp_x;
				y = temp_y;
			}

			//kolizja z tym samym zwierzeciem
			else if (onMap[temp_x][temp_y]->getSymbol() == symbol && onMap[temp_x][temp_y] != &*this) {
				multiplication(onMap[temp_x][temp_y]);
			}

			//inna kolizja
			else if (onMap[temp_x][temp_y] != &*this) {
				onMap[temp_x][temp_y]->collision(&*this);
				collision(onMap[temp_x][temp_y]);
				//zwyciestwo przejscie na dalsze pole
				if (isAlive()) {
					onMap[temp_x][temp_y] = onMap[x][y];
					onMap[x][y] = nullptr;
					x = temp_x;
					y = temp_y;
				}
				//smierc
				else {
					onMap[x][y] = nullptr;
				}
			}

		}

	}

	void Snail::collision(organism::Organism *opponent) {
		int temp_strength = opponent->getStrength();
		int chance_unseen = rand() % 100;
		std::string comment;

		/*Niewra¿liwy na ataki zwierz¹t o sile <2.
		Ma 60% szans i¿ pozostanie niezauwa¿ony przez zwierzêta o sile >4.
		W obu przypadkach napastnik przesuwa siê na inne niezajête pole.*/

		if (temp_strength < 2 || (temp_strength > 4 && chance_unseen < 60))
		{
			//PRZEJSCIE OPONENTA NA SASIEDNIE NIEZAJETE POLE

			int oponent_x = opponent->getX();
			int oponent_y = opponent->getY();
			//						1					2					3					 4	// punkty sasiadujace 
			int neighbour_x[] = { oponent_x		 ,	oponent_x	   ,	oponent_x - 1	,	oponent_x + 1 };
			int neighbour_y[] = { oponent_y + 1  ,	oponent_y - 1  ,	oponent_y		,	oponent_y };

			for (int i = 0; i < 4; i++) {
				if (neighbour_x[i] >= 0 && neighbour_x[i] < 20 &&
					neighbour_y[i] >= 0 && neighbour_y[i] < 20 &&
					onMap[neighbour_x[i]][neighbour_y[i]] == nullptr)
				{
					int temp_x = oponent_x;
					int temp_y = oponent_y;

					onMap[temp_x][temp_y] = onMap[oponent_x][oponent_y];
					onMap[oponent_x][oponent_y] = nullptr;
					opponent->setX(temp_x);
					opponent->setY(temp_y);
					break;
					comment = "The snail goes to the neighboring field because is unseen by: ";
					world->log.push_back(comment += opponent->getSymbol());
				}
			}

		}
		else {
			int temp_strength = opponent->getStrength();
			
			if (strength >= temp_strength) {
				opponent->setAlive(false);
				
				comment = "Snail wins with: ";
				world->log.push_back(comment += opponent->getSymbol());
			}
			else {
				setAlive(false);
				comment = "Snail loses with: ";
				world->log.push_back(comment += opponent->getSymbol());
			}
		}

	}


}