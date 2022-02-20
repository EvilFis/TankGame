#pragma once

#include <ctime>

class Rock {
private:
	unsigned short _rx, _ry, _count_damage_rock, _count_static_rock;
	char _type;
	int _cordsStone[5][2], _biasX, _biasY;
	HDC dc;
	HBRUSH _base_c, _damageR_c, _staticR_c;

public:

	Rock(HDC detectedConsole, char type = 'b', unsigned short sizeX = 600, unsigned short sizeY = 600, time_t user_time = 0) {
		srand(time(&user_time));
		this->_rx = sizeX;
		this->_ry = sizeY;
		this->_type = type;
		this->_count_damage_rock = 5;
		this->_count_static_rock = 3;
		this->dc = detectedConsole;
		this->_biasX = rand() % 20;
		this->_biasY = rand() % 20;

		this->_base_c = CreateSolidBrush(RGB(255, 255, 255));
		this->_damageR_c = CreateSolidBrush(RGB(254, 128, 67));
		this->_staticR_c = CreateSolidBrush(RGB(254, 128, 100));

		if (this->_type == 's') {
			for (int i = 0; i < this->_count_damage_rock; i++) {
				this->_cordsStone[i][0] = rand() % this->_rx;
				this->_cordsStone[i][1] = rand() % this->_ry;
			}
		}
		else if (this->_type == 'b') {
			for (int i = 0; i < this->_count_static_rock; i++) {
				this->_cordsStone[i][0] = rand() % this->_rx;
				this->_cordsStone[i][1] = rand() % this->_ry;
			}
		}
		

	}

	void disp() {

		if (this->_type == 's') {

			for (int i = 0; i <= this->_count_damage_rock; i++){
				SelectObject(this->dc, this->_damageR_c);
				Rectangle(dc, this->_cordsStone[i][0], this->_cordsStone[i][1], (this->_cordsStone[i][0] + 15), (this->_cordsStone[i][1] + 15)); // Damage stone
			}
		}
		else if (this->_type == 'b') {


			for (int i = 0; i < _count_static_rock; i++) {

				SelectObject(this->dc, this->_staticR_c);
				Rectangle(dc, this->_cordsStone[i][0], this->_cordsStone[i][1], (this->_cordsStone[i][0] + 20), (this->_cordsStone[i][1] + 20)); // Static stone

				if (i == 0) {
					continue;
				}

				for (int j = 1; j <= 5; j++) {
					Rectangle(dc, this->_cordsStone[i][0]+ this->_biasX *j, this->_cordsStone[i][1]+this->_biasY*j,
						(this->_cordsStone[i][0] + this->_biasX * j + 20), (this->_cordsStone[i][1] + this->_biasY * j + 20)); // Static stone
				}
			}
		}

	}

};