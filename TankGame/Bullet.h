#pragma once

class Bullet {
private:
	unsigned short _bx, _by;

	HDC dc;

public:

	Bullet(HDC detectedConsole) {
		this->_bx = 50;
		this->_by = 50;

		this->dc = detectedConsole;

	}

	void disp() {
		Rectangle(this->dc, this->_bx, this->_by, (this->_bx + 7), (this->_by + 7)); // Пуля
		//POINT ptTriangle[3] = { {50, 60}, {80, 100}, {50, 80} };
		//Polygon(this->dc, ptTriangle, 3);
	}

};

