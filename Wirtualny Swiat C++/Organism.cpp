#include "Organism.h"
#include "World.h"

namespace organism {

	Organism::Organism() {
		alive = true;
		age = 0;

	}

	Organism::~Organism()
	{
	}

	void Organism::draw()
	{
		symbolOnMap[x][y] = symbol;
	}

	bool Organism::isAlive() const {
		return alive;
	}

	void Organism::setAlive(bool alive) {
		this->alive = alive;
	}

	void Organism::setAge() {
		this->age = age + 1;
	}

	void Organism::setAge(int age) {
		this->age = age;
	}

	void Organism::setX(int x) {
		this->x = x;
	}

	void Organism::setY(int y) {
		this->y = y;
	}

	
	void Organism::setWorld(World &swiat1) {
		this->world = &swiat1;
		this->onMap = swiat1.mapOfOrganisms;
		this->symbolOnMap = swiat1.map;
	}
	

	void Organism::setStrength(int addStrength) {
		strength = +addStrength;
	}

	int Organism::getInitiative() const {
		return initiative;
	}

	int Organism::getAge() const {
		return age;
	}

	int Organism::getStrength() const {
		return strength;
	}

	char Organism::getSymbol() const {
		return symbol;
	
	}

	int Organism::getX() const {
		return x;
	}

	int Organism::getY() const {
		return y;
	}

}