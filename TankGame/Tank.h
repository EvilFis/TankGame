#pragma once

class Tank {
	private:
		unsigned short _tx, _ty;

		HDC dc;

	public:

		Tank(HDC detectedConsole) {
			this->_tx = 200;
			this->_ty = 200;

			this->dc = detectedConsole;
		}

		void disp() {
			Rectangle(dc, (this->_tx - 10), (this->_ty - 25), (this->_tx + 15), (this->_ty + 15)); // Кабина
			Rectangle(dc, (this->_tx - 5), (this->_ty - 5), (this->_tx + 10), (this->_ty + 10)); // Башня
			Rectangle(dc, this->_tx, this->_ty, (this->_tx + 5), (this->_ty + 5)); // Шлюз
			Rectangle(dc, this->_tx, (this->_ty - 40), (this->_tx + 5), (this->_ty - 5)); // Пушка
			Rectangle(dc, this->_tx - 2, (this->_ty - 47), (this->_tx + 7), (this->_ty - 40)); // Дуло пушки
			Rectangle(dc, this->_tx + 15, (this->_ty - 30), (this->_tx + 30), (this->_ty + 22)); // Гусеница правая
			Rectangle(dc, this->_tx - 25, (this->_ty - 30), (this->_tx - 10), (this->_ty + 22)); // Гусеница левая
		}

		void move() {
			if (_kbhit()) {
				switch (_getch()) {
					case 'w':
						this->_ty -= 5;
						break;
					case 's':
						this->_ty += 5;
						break;
					case 'd':
						this->_tx += 5;
						break;
					case 'a':
						this->_tx -= 5;
						break;
						
				}
			}
		}
};
