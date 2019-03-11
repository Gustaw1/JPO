#pragma once
#include "Organism.h"
#include "Animals.h"
#include "Plants.h"

#include "World.h"

#include <fstream>

class Data
{
public:
	Data();
	~Data();
	void load(World &swiat1);
	void random_init(World &swiat1, char kind, int count);
	void random_init1(World &swiat1);
};

