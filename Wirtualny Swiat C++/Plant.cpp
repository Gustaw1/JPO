#include "Plant.h"


namespace plant {

	Plant::Plant() {
		initiative = 0;
		strength = 0;
	}

	Plant::~Plant() {}

	void Plant::action() {

		const int size = 20;
		int ifMultiplication = rand() % 100;
		//10% szans na rozsianie
		if (ifMultiplication < 10)  {

			int multiplication_direction = rand() % 4; //cztery mozliwe kierunki

			int temp_x = x;
			int temp_y = y;

			//ruch w gore
			if ((multiplication_direction==0) && (y>0)) {
				temp_y -= 1;
			}
			//ruch w dol
			else if ((multiplication_direction == 1) && (y < size - 1)) {
				temp_y += 1;
			}
			//ruch w lewo
			else if ((multiplication_direction == 2) && (x>0)) {
				temp_x -= 1;
			}
			//ruch w prawo
			else if ((multiplication_direction == 3) && (x < size - 1)) {
				temp_x += 1;
			}


			//jezeli wolne miejsce na mapie to rozmnazamy rosline
			if (onMap[temp_x][temp_y] == nullptr) {
				multiplication(temp_x, temp_y);
			}

		}
	}

	void Plant::collision(organism::Organism *opponent) {
	
	}

	void Plant::multiplication(Organism* partner) {

	}
	

}