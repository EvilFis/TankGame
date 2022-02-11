#pragma once

#pragma once

#include <vector>

class ETank {
private:
	unsigned short _tx, _ty;

	HBRUSH _base_c, _cabin_c, _catarpillar_c, _gun_c;

	HDC dc;

public:

	ETank(HDC detectedConsole) {
		this->_tx = 300;
		this->_ty = 200;

		this->dc = detectedConsole;

		this->_base_c = CreateSolidBrush(RGB(255, 255, 255));
		this->_cabin_c = CreateSolidBrush(RGB(236, 28, 37));
		this->_catarpillar_c = CreateSolidBrush(RGB(137, 1, 21));
		this->_gun_c = CreateSolidBrush(RGB(254, 154, 170));

	}

	void disp(char direction = 'w') {

		TextOutA(this->dc, 550, 20, &direction, 1);

		if (direction == 'w') {
			SelectObject(this->dc, this->_cabin_c);
			BOOL cabina = Rectangle(dc, (this->_tx - 10), (this->_ty - 25), (this->_tx + 15), (this->_ty + 15)); // Кабина

			SelectObject(this->dc, this->_gun_c);
			BOOL tower = Rectangle(dc, (this->_tx - 5), (this->_ty - 5), (this->_tx + 10), (this->_ty + 10)); // Башня

			SelectObject(this->dc, this->_cabin_c);
			BOOL gateway = Rectangle(dc, this->_tx, this->_ty, (this->_tx + 5), (this->_ty + 5)); // Шлюз

			SelectObject(this->dc, this->_gun_c);
			BOOL gun = Rectangle(dc, this->_tx, (this->_ty - 40), (this->_tx + 5), (this->_ty - 5)); // Пушка
			BOOL doulo_gun = Rectangle(dc, this->_tx - 2, (this->_ty - 47), (this->_tx + 7), (this->_ty - 40)); // Дуло пушки

			SelectObject(this->dc, this->_catarpillar_c);
			BOOL catarpillar_r = Rectangle(dc, this->_tx + 15, (this->_ty - 30), (this->_tx + 30), (this->_ty + 22)); // Гусеница правая
			BOOL catarpillar_l = Rectangle(dc, this->_tx - 25, (this->_ty - 30), (this->_tx - 10), (this->_ty + 22)); // Гусеница левая
		}
		else if (direction == 's') {
			SelectObject(this->dc, this->_cabin_c);
			BOOL cabina = Rectangle(dc, (this->_tx - 10), (this->_ty - 25), (this->_tx + 15), (this->_ty + 15)); // Кабина

			SelectObject(this->dc, this->_gun_c);
			BOOL tower = Rectangle(dc, (this->_tx - 5), (this->_ty - 20), (this->_tx + 10), (this->_ty - 5)); // Башня

			SelectObject(this->dc, this->_cabin_c);
			BOOL gateway = Rectangle(dc, this->_tx, this->_ty - 15, (this->_tx + 5), (this->_ty - 10)); // Шлюз

			SelectObject(this->dc, this->_gun_c);
			BOOL gun = Rectangle(dc, this->_tx, (this->_ty + 30), (this->_tx + 5), (this->_ty - 5)); // Пушка
			BOOL doulo_gun = Rectangle(dc, this->_tx - 2, (this->_ty + 37), (this->_tx + 7), (this->_ty + 30)); // Дуло пушки

			SelectObject(this->dc, this->_catarpillar_c);
			BOOL catarpillar_r = Rectangle(dc, this->_tx + 15, (this->_ty - 30), (this->_tx + 30), (this->_ty + 22)); // Гусеница правая
			BOOL catarpillar_l = Rectangle(dc, this->_tx - 25, (this->_ty - 30), (this->_tx - 10), (this->_ty + 22)); // Гусеница левая
		}
		else if (direction == 'd') {
			SelectObject(this->dc, this->_cabin_c);
			BOOL cabina = Rectangle(dc, (this->_tx - 25), (this->_ty - 10), (this->_tx + 15), (this->_ty + 15)); // Кабина

			SelectObject(this->dc, this->_gun_c);
			BOOL tower = Rectangle(dc, (this->_tx - 20), (this->_ty - 5), (this->_tx - 5), (this->_ty + 10)); // Башня

			SelectObject(this->dc, this->_cabin_c);
			BOOL gateway = Rectangle(dc, (this->_tx - 15), (this->_ty + 5), (this->_tx - 10), (this->_ty + 0)); // Шлюз

			SelectObject(this->dc, this->_gun_c);
			BOOL gun = Rectangle(dc, (this->_tx - 5), (this->_ty + 5), (this->_tx + 30), (this->_ty)); // Пушка
			BOOL doulo_gun = Rectangle(dc, (this->_tx + 37), (this->_ty - 2), (this->_tx + 30), (this->_ty + 7)); // Дуло пушки

			SelectObject(this->dc, this->_catarpillar_c);
			BOOL catarpillar_r = Rectangle(dc, (this->_tx - 30), (this->_ty - 10), (this->_tx + 22), (this->_ty - 25)); // Гусеница правая
			BOOL catarpillar_l = Rectangle(dc, (this->_tx - 30), (this->_ty + 15), (this->_tx + 22), (this->_ty + 30)); // Гусеница левая
		}
		else if (direction == 'a') {
			SelectObject(this->dc, this->_cabin_c);
			BOOL cabina = Rectangle(dc, (this->_tx - 25), (this->_ty - 10), (this->_tx + 15), (this->_ty + 15)); // Кабина

			SelectObject(this->dc, this->_gun_c);
			BOOL tower = Rectangle(dc, (this->_tx + 10), (this->_ty - 5), (this->_tx - 5), (this->_ty + 10)); // Башня

			SelectObject(this->dc, this->_cabin_c);
			BOOL gateway = Rectangle(dc, (this->_tx + 5), (this->_ty + 5), (this->_tx), (this->_ty + 0)); // Шлюз

			SelectObject(this->dc, this->_gun_c);
			BOOL gun = Rectangle(dc, (this->_tx - 5), (this->_ty + 5), (this->_tx - 40), (this->_ty)); // Пушка
			BOOL doulo_gun = Rectangle(dc, (this->_tx - 47), (this->_ty - 2), (this->_tx - 40), (this->_ty + 7)); // Дуло пушки

			SelectObject(this->dc, this->_catarpillar_c);
			BOOL catarpillar_r = Rectangle(dc, (this->_tx - 30), (this->_ty - 10), (this->_tx + 22), (this->_ty - 25)); // Гусеница правая
			BOOL catarpillar_l = Rectangle(dc, (this->_tx - 30), (this->_ty + 15), (this->_tx + 22), (this->_ty + 30)); // Гусеница левая
		}

		(HBRUSH)SelectObject(this->dc, this->_base_c);
	}

	char move() {
		if (_kbhit()) {
			switch (_getch()) {
			case 'i':
				this->_ty -= 5;
				return 'w';
			case 'k':
				this->_ty += 5;
				return 's';
			case 'l':
				this->_tx += 5;
				return 'd';
			case 'j':
				this->_tx -= 5;
				return 'a';
			}
		}
	}


private:

};
