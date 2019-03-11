#include "Animal.h"
#include "World.h"


namespace animal {

	Animal::Animal()
	{
	}

	Animal::~Animal()
	{
	}

	void Animal::action() {

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
			//komentarze
			std::string first_organism;
			std::string second_organism;
			std::string comment = " ate the ";
			std::string comment2 = " killed the ";

			if (isAlive() && onMap[x][y]!=nullptr) { //isAlive() 
				first_organism = onMap[x][y]->getSymbol();
				second_organism = onMap[temp_x][temp_y]->getSymbol();
				world->log.push_back(first_organism += comment += second_organism); //first killed second
				//->koniec komentarzy

				onMap[temp_x][temp_y] = nullptr; //tu ?=================================================
				onMap[temp_x][temp_y] = onMap[x][y];
				//tusprawdzenie
				onMap[x][y] = nullptr;
				x = temp_x;
				y = temp_y;
			}
		//smierc
			else {
				first_organism = onMap[x][y]->getSymbol();
				second_organism = onMap[temp_x][temp_y]->getSymbol();
				world->log.push_back(second_organism += comment2 += first_organism); //second killed first
				onMap[x][y] = nullptr;
			}
		}
	}

	void Animal::collision(organism::Organism *opponent) {
		int temp_strength = opponent->getStrength();

		if (strength>=temp_strength) {
			opponent->setAlive(false);

		}
		else {
			setAlive(false);
		}
	}

	void Animal::multiplication(Organism* partner) {

	}

	void Animal::multiplication(int newX, int newY) {

	}

}
