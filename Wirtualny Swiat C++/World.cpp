#include "World.h"


World::World() {
	mapOfOrganisms = new organism::Organism**[20];

	for (int i = 0; i < 20; i++) {

		mapOfOrganisms[i] = new organism::Organism*[20];
		for (int j = 0; j < 20; j++) {
			mapOfOrganisms[i][j] = nullptr;
		}
	}

	map = new char*[20];
	for (int i = 0; i < 20; i++) {
		map[i] = new char[20];

		for (int j = 0; j < 20; j++) {
			map[i][j] = ' ';
		}
	}
}


World::~World()
{
	int size = organisms.size();

	for (int i = 0; i < size; i++) {
		delete organisms[i];
	}
	
	for (int i = 0; i < 20; i++) {
		delete map[i];
	}
	delete[] map;
	
	organisms.clear(); //'czyszczenie vectora
	std::cout << "Niszczenie mapy" << std::endl;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mapOfOrganisms[i][j] = nullptr;
		}
	}

	for (int i = 0; i < 20; i++) {
		delete mapOfOrganisms[i];
	}
	delete[] mapOfOrganisms;
	
	std::cout << "Smierc organizmow" << std::endl;

	for (int i = 0; i < log.size(); i++) {
		std::cout << log[i] << std::endl;
	}

	log.clear();
	
}

bool World::sort(organism::Organism *i, organism::Organism *j) {
	int temp_i = i->getInitiative();
	int temp_j = j->getInitiative();

	if (temp_i==temp_j) {
		return (i->getAge() > j->getAge());
	}

	return (temp_i > temp_j);
}

bool World::sortAlive(organism::Organism *i, organism::Organism *j) {
	return (i->isAlive() > j->isAlive());
}

void World::createWorld() {
	std::sort(organisms.begin(), organisms.end(), sort);
}

void World::drawWorld() {

	std::system("CLS");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			map[i][j] = ' ';
		}
	}

	int size = organisms.size();

	for (int i = 0; i < size; i++) {
		organisms[i]->draw();
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << map[i][j];
		}
		if (i < log.size()) {
			std::cout << "\t" << log[i];
		}
		std::cout << std::endl;
	}
	log.clear();
	std::cout << std::endl << std::endl;
	std::cout << "Maciej Kubale nr albumu: 120486" << std::endl;
}

void World::nextRound() {

	int amount = organisms.size();

	//zwiekszenie wieku
	for (int i = 0; i < amount; i++) {
		organisms[i]->setAge();
	}

	//wykonanie akcji zywych organizmow
	for (int i = 0; i < amount; i++) {
		if (organisms[i]->isAlive()) {
			organisms[i]->action();
		}
	}
	/*sort( RanIt first, RanIt last, Comparator comp ); comp-porównuj¹cy dwa elementy z sortowanego zakresu. 
	Predykat ma zwracaæ wartoœæ false, je¿eli pierwszy argument powinien znajdowaæ siê za drugim,
	natomiast true w przeciwnym wypadku.*/
	std::sort(organisms.begin(), organisms.end(), sortAlive); //niezywe na koncu

	//usuwamy niezywe organizmy
	for (int i= organisms.size()-1; i>=0; i--) { // zamiast i=amount-1; - amount zmienilo sie podczas wykonywania akcji
		if (!organisms[i]->isAlive()) {
			delete organisms[i];
			organisms.erase(organisms.begin() + i);
		}
		else {
			break; 
		}
	}

	std::sort(organisms.begin(), organisms.end(), sort);
}

//Zapisuje do pliku polozenie (x,y), wiek i symbole wszystkich organizmow
std::string World::saveWorld() {
	std::string save;
	for (int i = 0; i < organisms.size(); i++) {

		save.push_back(organisms[i]->getSymbol()); //zamiast append, aby zapisac symbol (zamiast reprezentacji w kodzie ASCII)
		save.append("x");
		save.append(std::to_string(organisms[i]->getX()));
		save.append("y");
		save.append(std::to_string(organisms[i]->getY()));
		save.append("a");
		save.append(std::to_string(organisms[i]->getAge()));
		save.append(" ");

	}
	save.pop_back(); //usuwa ostatnia spacje
	save.append("\n");

	return save;
}

