#pragma once

class Rock {
private:
	unsigned short _rx, _ry;
	char _type;

	HDC dc;

public:

	Rock(HDC detectedConsole, char type = 'b', unsigned short rx = 300, unsigned short ry = 300) {
		this->_rx = rx;
		this->_ry = ry;
		this->_type = type;

		this->dc = detectedConsole;
	}

	void disp() {

		if (this->_type == 'b') {
			Rectangle(dc, (this->_rx), (this->_ry), (this->_rx + 20), (this->_ry + 20)); // Big rock
		}
		else if (this->_type == 's') {
			Rectangle(dc, (this->_rx), (this->_ry), (this->_rx + 10), (this->_ry + 10)); // Small rock
		}

	}

};