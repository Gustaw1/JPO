#include "Data.h"

Data::Data()
{

}

Data::~Data()
{
}

void Data::random_init1(World &swiat1) {

	char Elephant = 'E';
	char Mosquito = 'M';
	char Sheep = 'S';
	char Snail = 'N';
	char Wolf = 'W';
	char Grass = 'g';
	char Guarana = 'u';
	char WolfBerries = 'w';

	random_init(swiat1, Mosquito, 5);
	random_init(swiat1, Guarana, 5);
	random_init(swiat1, Elephant, 5);
	random_init(swiat1, Sheep, 5);
	random_init(swiat1, Snail, 5);
	random_init(swiat1, Wolf, 5);
	random_init(swiat1, Grass, 5);
	random_init(swiat1, WolfBerries, 5);
}

void Data::load(World &swiat1)
{
	std::vector<std::string> load_organisms;

	std::string line;
	std::ifstream plik;
	std::string file_name;

	std::cout << "Podaj nazwe pliku do wczytania: ";
	std::cin >> file_name;
	plik.open(file_name.c_str());

	if (plik.good() == true)
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		//tu operacje na pliku
		while (plik >> line) {
			load_organisms.push_back(line);
		}
		plik.close();
	}
	else std::cout << "Brak podanego pliku" << std::endl;

	if (load_organisms.size() == 0) {
		std::cout << "Brak organizmow" << std::endl;
		exit(EXIT_FAILURE);
	}

	const char* sign;
	for (unsigned int i = 0; i < load_organisms.size(); i++) {

		sign = load_organisms[i].c_str();
		char organism = 0;
		int x = -1;
		int y = -1;
		int a = 0;

		while (*sign != 0) {
			switch (*sign) {
			case 'E':
				organism = 'E';
				break;
			case 'M':
				organism = 'M';
				break;
			case 'S':
				organism = 'S';
				break;
			case 'N':
				organism = 'N';
				break;
			case 'W':
				organism = 'W';
				break;
			case 'g':
				organism = 'g';
				break;
			case 'u':
				organism = 'u';
				break;
			case 'w':
				organism = 'w';
				break;
			case 'x':
				x = atoi(sign + 1);
				break;
			case 'y':
				y = atoi(sign + 1);
				break;
			case 'a': //wiek zwierzecia
				a = atoi(sign + 1);
				break;
			default:
				try {
					if (!isdigit(*sign)) {
						throw *sign;
					}
				}
				catch (char e) {
					std::cout << "Niepoprawny symbol w pliku: " << e << std::endl;
					exit(EXIT_FAILURE);
				}
				break;
			}
			sign++;
		}

		if (swiat1.mapOfOrganisms[x][y] == nullptr) {
			switch (organism) {
				//zwierzeta
			case 'E':
				swiat1.mapOfOrganisms[x][y] = new animal::Elephant(x, y);
				break;
			case 'M':
				swiat1.mapOfOrganisms[x][y] = new animal::Mosquito(x, y);
				break;
			case 'S':
				swiat1.mapOfOrganisms[x][y] = new animal::Sheep(x, y);
				break;
			case 'N':
				swiat1.mapOfOrganisms[x][y] = new animal::Snail(x, y);
				break;
			case 'W':
				swiat1.mapOfOrganisms[x][y] = new animal::Wolf(x, y);
				break;
				//rosliny
			case 'g':
				swiat1.mapOfOrganisms[x][y] = new plant::Grass(x, y);
				break;
			case 'u':
				swiat1.mapOfOrganisms[x][y] = new plant::Guarana(x, y);
				break;
			case 'w':
				swiat1.mapOfOrganisms[x][y] = new plant::WolfBerries(x, y);
				break;
			}
			//tworzenie
			swiat1.organisms.push_back(swiat1.mapOfOrganisms[x][y]);
			swiat1.mapOfOrganisms[x][y]->setWorld(swiat1);
			swiat1.mapOfOrganisms[x][y]->setAge(a);
		}
		else {
			std::cout << "Pole zajete" << std::endl;
		}
	}
}


void Data::random_init(World &swiat1, char kind, int count) {
	//kind - gatunek 
	int initial_age = 0;
	for (int i = 0; i < count; i++) {

		//losowanie miejsca
		int N = 20;
		int x = rand() % N;
		int y = rand() % N;

		//sprawdzamy czy jest puste pole na mapie
		if (swiat1.mapOfOrganisms[x][y] == nullptr) {

			switch (kind)
			{
				//zwierzeta
			case 'E':
				swiat1.mapOfOrganisms[x][y] = new animal::Elephant(x, y);
				break;
			case 'M':
				swiat1.mapOfOrganisms[x][y] = new animal::Mosquito(x, y);
				break;
			case 'S':
				swiat1.mapOfOrganisms[x][y] = new animal::Sheep(x, y);
				break;
			case 'N':
				swiat1.mapOfOrganisms[x][y] = new animal::Snail(x, y);
				break;
			case 'W':
				swiat1.mapOfOrganisms[x][y] = new animal::Wolf(x, y);
				break;
				//rosliny
			case 'g':
				swiat1.mapOfOrganisms[x][y] = new plant::Grass(x, y);
				break;
			case 'u':
				swiat1.mapOfOrganisms[x][y] = new plant::Guarana(x, y);
				break;
			case 'w':
				swiat1.mapOfOrganisms[x][y] = new plant::WolfBerries(x, y);
				break;
			default:
				break;
			}

			//dodawanie
			swiat1.organisms.push_back(swiat1.mapOfOrganisms[x][y]);
			swiat1.mapOfOrganisms[x][y]->setWorld(swiat1);
			swiat1.mapOfOrganisms[x][y]->setAge(initial_age);
		}
		else continue;

	}
}