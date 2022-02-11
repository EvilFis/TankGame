#pragma once

class Storm {
private:
	unsigned short _sx, _sy;

	HDC dc;

public:

	Storm(HDC detectedConsole) {
		this->_sx = 300;
		this->_sy = 50;

		this->dc = detectedConsole;
	}

	void disp() {
		
		//srand(time(0)); // Вызывается чтобы каждый раз значение rand выдавала разные значения
		for (short i = 0; i <= 3; i++) {
			Ellipse(this->dc, (this->_sx - (rand() % 25)), (this->_sy - (rand() % 25)), (this->_sx + (rand() % 50)), (this->_sy + (rand() % 50)));
		}

	}

};