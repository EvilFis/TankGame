#pragma once

#include "Bullet.h"

class Tank {
	private:
		unsigned short _tx, _ty, _sizeX, _sizeY, _tank_s_w, _tank_s_h;
		char key, backKey;
		Bullet *bullet;
		HBRUSH _base_c, _cabin_c, _catarpillar_c, _gun_c;

		HDC dc;

	public:

		Tank(HDC detectedConsole, short sizeX=600, short sizeY=600) {
			this->_tank_s_w = 45;
			this->_tank_s_h = 45;

			this->_tx = (sizeX / 2) - (_tank_s_w / 2);
			this->_ty = 500;
			this->_sizeX = sizeX;
			this->_sizeY = sizeY;
			this->dc = detectedConsole;

			this->_base_c = CreateSolidBrush(RGB(255, 255, 255));
			this->_cabin_c = CreateSolidBrush(RGB(0, 163, 233));
			this->_catarpillar_c = CreateSolidBrush(RGB(7, 17, 205));
			this->_gun_c = CreateSolidBrush(RGB(152, 216, 234)); 

			bullet = new Bullet(detectedConsole, 10, 10);

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

				SelectObject(this->dc, this->_base_c);
				BOOL cp = Rectangle(dc, this->_tx - 5, (this->_ty - 5), (this->_tx + 5), (this->_ty + 5)); // Центр точка
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

				SelectObject(this->dc, this->_base_c);
				BOOL cp = Rectangle(dc, this->_tx - 5, (this->_ty - 5), (this->_tx + 5), (this->_ty + 5)); // Центр точка
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

				SelectObject(this->dc, this->_base_c);
				BOOL cp = Rectangle(dc, this->_tx - 5, (this->_ty - 5), (this->_tx + 5), (this->_ty + 5)); // Центр точка
			}
			else if (direction == 'a') {
				SelectObject(this->dc, this->_cabin_c);
				BOOL cabina = Rectangle(dc, (this->_tx - 25), (this->_ty - 10), (this->_tx + 15), (this->_ty + 15)); // Кабина

				SelectObject(this->dc, this->_gun_c);
				BOOL tower = Rectangle(dc, (this->_tx + 10), (this->_ty - 5), (this->_tx - 5 ), (this->_ty + 10)); // Башня

				SelectObject(this->dc, this->_cabin_c);
				BOOL gateway = Rectangle(dc, (this->_tx +5 ), (this->_ty + 5), (this->_tx), (this->_ty + 0)); // Шлюз

				SelectObject(this->dc, this->_gun_c);
				BOOL gun = Rectangle(dc, (this->_tx - 5), (this->_ty + 5), (this->_tx - 40), (this->_ty)); // Пушка
				BOOL doulo_gun = Rectangle(dc, (this->_tx - 47), (this->_ty - 2), (this->_tx - 40), (this->_ty + 7)); // Дуло пушки

				SelectObject(this->dc, this->_catarpillar_c);
				BOOL catarpillar_r = Rectangle(dc, (this->_tx - 30), (this->_ty - 10), (this->_tx + 22), (this->_ty - 25)); // Гусеница правая
				BOOL catarpillar_l = Rectangle(dc, (this->_tx - 30), (this->_ty + 15), (this->_tx + 22), (this->_ty + 30)); // Гусеница левая

				SelectObject(this->dc, this->_base_c);
				BOOL cp = Rectangle(dc, this->_tx - 5, (this->_ty - 5), (this->_tx + 5), (this->_ty + 5)); // Центр точка
			}

			
			(HBRUSH)SelectObject(this->dc, this->_base_c);
		}

		void fire() {

		}

		char move() {
			if (_kbhit()) {

				this->key = _getch();

				switch (this->key) {
					case 'w':
						if (this->_ty > this->_tank_s_h) {
							this->_ty -= 3;
						}
						return 'w';
					case 's':
						if (this->_ty < this->_sizeY - 110) {
							this->_ty += 3;
						}
						return 's';
					case 'd':
						if (this->_tx < this->_sizeX - this->_tank_s_w - 20) {
						this->_tx += 3;
						}
						return 'd';
					case 'a':
						if (this->_tx > this->_tank_s_w){
							this->_tx -= 3;
						}
						return 'a';
					case ' ':
						fire();
						break;
				}
			}
		}	
};
