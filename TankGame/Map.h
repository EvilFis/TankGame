#pragma once

#include "Tank.h"
#include "ETank.h"
#include "Bullet.h"
#include "Rock.h"
#include "Storm.h"

class Map
{
	private:

		unsigned short _sizeX, _sizeY;
		bool render;
		char direction;

		HDC dc;
		RECT mapPar;
		HBRUSH _base_c, _bg_c;
		Tank* tank;
		Rock* rock_damage;
		Rock* rock_static;


	public:

		Map(HDC detectedConsole, unsigned short sizeX, unsigned short sizeY) {

			this->_sizeX = sizeX;
			this->_sizeY = sizeY;

			this->dc = detectedConsole;
			this->mapPar = { 0, 0, sizeX, sizeY };
			this->_base_c = CreateSolidBrush(RGB(255, 255, 255));
			this->_bg_c = CreateSolidBrush(RGB(253, 193, 94));

			this->direction = 'w';

			tank = new Tank(detectedConsole);
			rock_damage = new Rock(detectedConsole, 's', sizeX, sizeY);
			rock_static = new Rock(detectedConsole, 'b', sizeX, sizeY, 100);
		}

		
	public:

		void disp() {

			SelectObject(this->dc, this->_bg_c); // Кисточка для окраски танка
			BOOL cabina = Rectangle(dc, 0, 0, this->_sizeX, this->_sizeY ); // Задний фон

			rock_static->disp();
			rock_damage->disp();

			tank->disp(this->direction);
			this->direction = tank->move();


		}

};

