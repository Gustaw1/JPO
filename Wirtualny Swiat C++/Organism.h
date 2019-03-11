#pragma once

#include <cstdlib>
#include <vector>

class World;

namespace organism {

	class Organism
	{
	public:
		Organism();
		virtual ~Organism();

		//podstawowe metody :
		virtual void action() = 0; //okre�la zachowanie organizmu w trakcie tury
		virtual void collision(Organism *opponent) = 0; //okre�la zachowanie organizmu w trakcie kontaktu/zderzenia z innym organizmem
		void draw(); //powoduje narysowanie symbolicznej reprezentacji organizmu

		//----dodatkowe metody:------

		/*metoda multiplication: rozmna�anie w ramach metody collision()
		przy kolizji z organizmem tego samego gatunku nie dochodzi do walki,
		oba zwierz�ta pozostaj� na swoich miejscach,
		ko�o nich pojawia si� trzecie zwierze, tego samego gatunku.*/
		virtual void multiplication(Organism* partner) = 0;
		virtual void multiplication(int newX, int newY) = 0;
		bool isAlive() const;
		void setAlive(bool alive);
		void setAge(int age);
		void setAge();
		void setStrength(int addStrength);
		void setX(int x);
		void setY(int y);

		void setWorld(World &world);

		int getInitiative() const;
		int getAge() const;
		int getStrength() const;
		char getSymbol() const;
		int getX() const;
		int getY() const;

	protected:
		//podstawowe pola
		int strength=0;
		int initiative=0;
		//polozenie x,y
		int x = 0;
		int y=0;
		//referencja do �wiata w kt�rym znajduje si� organizm
		World *world;
		//-----dodatkowe pola------
		//int last_x, last_y;
		int age=0;
		char symbol=NULL;
		Organism ***onMap;
		char **symbolOnMap=nullptr;
		bool alive=false;
	};

}