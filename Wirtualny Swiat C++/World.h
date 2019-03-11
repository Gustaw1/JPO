#pragma once
#include "Organism.h"
#include <vector>
#include <algorithm>    // std::sort
#include <iostream>
#include <string>

class World
{
private:
	static bool sort(organism::Organism *i, organism::Organism *j);
	static bool sortAlive(organism::Organism *i, organism::Organism *j);
public:
	World();
	~World();

	organism::Organism ***mapOfOrganisms;
	char **map;
	void nextRound();
	void drawWorld();
	void createWorld();
	
	std::vector<organism::Organism*> organisms; //lista irganizmow
	std::vector<std::string> log; //Lista zdarzen
	std::string saveWorld();
};

