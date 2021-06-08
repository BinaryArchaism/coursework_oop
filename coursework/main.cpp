#include <Windows.h>
#include "Tanks.h"
#include "Walls.h"

#include <iostream>

//макрос для определения кода нажатой клавиши
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

HDC hdc; // Контекст устройства

int main() {
	HWND hwnd = GetConsoleWindow(); // Дескриптор консольного окна	
	MoveWindow(hwnd, 100, 100, 1500, 900, TRUE);
	if (hwnd != NULL)
	{
		hdc = GetWindowDC(hwnd);
		if (hdc != 0)
		{
			
			// Танки
			BlueTank tank(200, 200);
			RedTank tankR(200, 200);
			RedTankDamaged tank3(200, 200);
			Tank* curTank = &tank;
			bool isBlue = true;
			bool isRed = false;
			bool redDamaged = false;

			// Преграды
			const int wallsCount = 12;
			RedWall redwall1(500, 200);
			RedWall redwall2(200, 400);
			RedWall redwall3(650, 450);
			RedWall redwall4(450, 450);
			GreenWall greenwall1(600, 200);
			GreenWall greenwall2(900, 100);
			GreenWall greenwall3(700, 100);
			GreenWall greenwall4(300, 200);
			WhiteWall whitewall1(100, 100);
			WhiteWall whitewall2(300, 300);
			WhiteWall whitewall3(600, 700);
			MagicWall magicwall(550, 450);
			Wall* walls[wallsCount];
			walls[0] = &redwall1;
			walls[1] = &redwall2;
			walls[2] = &greenwall1;
			walls[3] = &greenwall2;
			walls[4] = &whitewall1;
			walls[5] = &whitewall2;
			walls[6] = &whitewall3;
			walls[7] = &magicwall;
			walls[8] = &redwall3;
			walls[9] = &redwall4;
			walls[10] = &greenwall3;
			walls[11] = &greenwall4;
			for (int i = 0; i < wallsCount; i++)
					walls[i]->show();
			
			while (curTank->getHealth() > 0)
			{
				curTank->show();
				for (int i = 0; i < wallsCount; i++)
					if (walls[i]->isVisible())
						walls[i]->show();

				if (KEY_DOWN(VK_ESCAPE)) break; // Выйти из игры

				// Управление танком
				if (KEY_DOWN(VK_RIGHT)) {
					curTank->moveTo(curTank->getX() + curTank->getSpeed(), curTank->getY());
					Sleep(1);
				}
				if (KEY_DOWN(VK_LEFT)) {
					curTank->moveTo(curTank->getX() - curTank->getSpeed(), curTank->getY());
					Sleep(1);
				}
				if (KEY_DOWN(VK_UP)) {
					curTank->moveTo(curTank->getX(), curTank->getY() - curTank->getSpeed());
					Sleep(1);
				}
				if (KEY_DOWN(VK_DOWN)) {
					curTank->moveTo(curTank->getX(), curTank->getY() + curTank->getSpeed());
					Sleep(1);
				}
				
				// Обработка столкновений
				for (int i = 0; i < wallsCount; i++) {
					if (curTank->collision(walls[i])) {
						if (i == 7) {
							int x = curTank->getX();
							int y = curTank->getY();
							curTank->hide();
							curTank = &tankR;
							curTank->moveTo(x, y);
							isBlue = false;
							isRed = true;
						}
						walls[i]->hide();
						curTank->takeDamage(walls[i]->getDamage());
					}
				}
				curTank->printHealth();

				// Меняем танки при определенных условиях
				if (curTank->getHealth() <= 4 && isRed) {
					int h = curTank->getHealth();
					int x = curTank->getX();
					int y = curTank->getY();
					curTank->hide();
					curTank = &tank3;
					curTank->takeDamage(curTank->getHealth() - h);
					curTank->moveTo(x, y);
					isRed = false;
					redDamaged = true;
				}
			}
			std::cout << "\nGAME OVER\n";
			system("pause");
		}
	}
	return 0;
}