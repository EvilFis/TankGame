#pragma once

#include <ctime>

class Rock {
private:
	unsigned short _rx, _ry, _countRock;
	char _type;
	int _cordsStone[5][2];
	HDC dc;
	HBRUSH _base_c, _damageR_c;

public:

	Rock(HDC detectedConsole, char type = 'b', unsigned short sizeX = 600, unsigned short sizeY = 600) {
		srand(time(0));
		this->_rx = sizeX;
		this->_ry = sizeY;
		this->_type = type;
		this->_countRock = 5;
		this->dc = detectedConsole;

		this->_base_c = CreateSolidBrush(RGB(255, 255, 255));
		this->_damageR_c = CreateSolidBrush(RGB(255, 128, 64));

		for (int i = 0; i < this->_countRock; i++) {
			this->_cordsStone[i][0] = rand() % this->_rx;
			this->_cordsStone[i][1] = rand() % this->_ry;
		}

	}

	void disp() {

		if (this->_type == 's') {

			for (int i = 0; i <= this->_countRock; i++){
				SelectObject(this->dc, this->_damageR_c);
				Rectangle(dc, this->_cordsStone[i][0], this->_cordsStone[i][1], (this->_cordsStone[i][0] + 15), (this->_cordsStone[i][1] + 15)); // Big rock
			}
		}
		else if (this->_type == 'b') {
			Rectangle(dc, (this->_rx), (this->_ry), (this->_rx + 10), (this->_ry + 10)); // Small rock
		}

	}

};