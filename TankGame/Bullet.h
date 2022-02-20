#pragma once

class Bullet {
private:
	HDC dc;


public:

	unsigned short _bx, _by;

	Bullet(HDC detectedConsole, unsigned short _bx, unsigned short _by) {
		this->_bx = _bx;
		this->_by = _by;

		this->dc = detectedConsole;

	}

	void disp() {
		Rectangle(this->dc, this->_bx, this->_by, (this->_bx + 7), (this->_by + 7)); // Пуля
		//POINT ptTriangle[3] = { {50, 60}, {80, 100}, {50, 80} };
		//Polygon(this->dc, ptTriangle, 3);
	}

};

