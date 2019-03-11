#include "Mosquito.h"
#include "World.h"

namespace animal {

	Mosquito::Mosquito(int x, int y){
		this->x = x;
		this->y = y;
		initiative = 1;
		strength = 1;
		symbol = 'M';
	}


	Mosquito::~Mosquito()
	{
		world->log.push_back("The Mosquito died");
	}

	void Mosquito::isMosquitoAneighbour() {

		//						1		2			3		 4	// punkty sasiadujace 
		int neighbour_x[] = { x		 ,	x	  ,  x - 1 ,	x+1 };
		int neighbour_y[] = { y + 1  , y - 1  ,		y  ,	y   };

		//Sprawdzenie czy obok sa komary, dodanie +1 do sily i inicjatywy za kazdego obok

		for (int i = 0; i < 4; i++) {
			if (neighbour_x[i] >= 0 && neighbour_x[i] < 20 &&
				neighbour_y[i] >= 0 && neighbour_y[i] < 20 &&
				onMap[neighbour_x[i]][neighbour_y[i]] != nullptr &&
				(onMap[neighbour_x[i]][neighbour_y[i]]->getSymbol() == symbol))
			{
				initiative++;
				strength++;
			}
		}
	}
	

	//50% szans na ucieczke, 0-zostal, 1-uciekl
	bool Mosquito::MosquitoEscaped() {
		return rand() % 2;
	}

	void Mosquito::action() {
		const int size = 20;

		isMosquitoAneighbour(); //Sprawdzamy czy jest komar na sasiednim polu

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
		else if ((multiplication_direction == 3) && (x < size - 1)) {
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
			//pokonany - 50% szans na ucieczke 0-zostal (smierc), 1-uciekl na poprzednie pole
			else if (MosquitoEscaped()==0) {
				
				onMap[x][y] = nullptr;
			}
			else {
				world->log.push_back("Mosquito escaped");
			}
		}
	
	}

	void Mosquito::multiplication(organism::Organism *partner) {

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
			onMap[neighbour_x[i]][neighbour_y[i]] = new Mosquito(neighbour_x[i], neighbour_y[i]);
			onMap[neighbour_x[i]][neighbour_y[i]]->setWorld(*world);
			world->organisms.push_back(onMap[neighbour_x[i]][neighbour_y[i]]);
			world->log.push_back("The birth of a Mosquito");
		}


	}

	void Mosquito::collision(organism::Organism *opponent) {
		int temp_strength = opponent->getStrength();
		std::string comment;

		if (strength>=temp_strength) {
			opponent->setAlive(false);
			comment = "Mosquito wins with: ";
			world->log.push_back(comment += opponent->getSymbol());
		}
		else {
			setAlive(false);
			comment = "Mosquito loses with: ";
			world->log.push_back(comment += opponent->getSymbol());
		}
	}
}