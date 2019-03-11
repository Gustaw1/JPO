#include "Organism.h"
#include "Animals.h"
#include "Plants.h"
#include "World.h"
#include <time.h>
#include <fstream>
#include "Data.h"


int main() {
	{
		srand(time(NULL));
		//Stworzenie swiata
		World swiat1;
		//Dodanie klasy z danymi wejsciowymi
		Data data1;

		data1.random_init1(swiat1);
		swiat1.drawWorld();

		std::string control;
		while (true) {
			std::cout << "Dostepne polecenia: load/save/exit/next (nastepna runda)" << std::endl;
			std::cout << "Wpisz polecenie: ";
			std::cin >> control;

			//wczytanie z pliku podanego przez uzytkownia
			if (control == "load") {
				data1.load(swiat1);
				swiat1.drawWorld();
			}
			//zapisanie
			if (control == "save") {

				std::cout << "Podaj nazwe pliku do zapisu: ";
				std::string filename;
				std::cin >> filename;
				std::ofstream file(filename);
				try {
					if (file.is_open()) {
						file << swiat1.saveWorld();
					}
					else {
						std::string wyjatek = "Nie mozna utworzyc pliku";
						throw wyjatek;  //rzucamy wyj¹tek
					}
				}
				catch (std::exception const& e) {
					std::cout << "Blad " << e.what();
					std::cout << "Uzywam domyslnego (save.txt)" << std::endl;
					std::ofstream file("save.txt");
					file << swiat1.saveWorld();
				}
				file.close();
			}

			//zakonczenie programu
			else if (control == "exit") {
				break;
			}

			//kolejne runda

			else if (control == "next") {
				swiat1.nextRound();
				swiat1.drawWorld();
			}
		}
	}
	system("pause");
	return 0;
}
