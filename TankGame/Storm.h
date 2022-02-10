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
		
		srand(time(0)); // Вызывается чтобы каждый раз значение rand выдавала разные значения
		for (short i = 0; i <= 3; i++) {
			Ellipse(this->dc, this->_sx - 25, this->_sy - 25, (this->_sx + (rand() % 50)), (this->_sy + (rand() % 50)));
		}

	}

	void move() {
		if (_kbhit()) {
			switch (_getch()) {
			case 'i':
				this->_sy -= 5;
				break;
			case 'k':
				this->_sy += 5;
				break;
			case 'l':
				this->_sx += 5;
				break;
			case 'j':
				this->_sx -= 5;
				break;

			}
		}
	}

};