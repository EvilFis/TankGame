//#include "StdAfx.h" // Импорт в старых версиях VS
#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <clocale>

#include "Tank.h"
#include "Bullet.h"
#include "Rock.h"
#include "Storm.h"

using namespace std;

// Первоначальная настройка приложения
struct SettingApp {
    unsigned short width = GetSystemMetrics(SM_CXFULLSCREEN); // Ширина экрана
    unsigned short height = GetSystemMetrics(SM_CYFULLSCREEN); // Высота экрана
    unsigned short sizeX = 600; // Ширина консоли
    unsigned short sizeY = 600; // Высота консоли
    
    // Производим захват консоли
    HWND cap_con = GetConsoleWindow();
    HDC dc = GetDC(cap_con);

    // Функция для очистки консоли
    void clearConsole() {
        COORD WCoord = {0, 0}; // Координаты по ширене
        DWORD nKol = 0; // Кол-во столбцов
        size_t xy = (sizeX*sizeY); // Размер поля очистки
        BOOL fSucces = FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0, xy, WCoord, &nKol); // Очистка поля консоли
    }
};

int main() {

    setlocale(LC_ALL, "Russian"); // Установка вывода русского языка
    SetConsoleTitle(L"Tank Game"); // Название консольного приложения

    SettingApp settingApp; // Подключение настроек окна

    // Установка разрешения окна
    MoveWindow(settingApp.cap_con, // Захваченная консоль
              (settingApp.width / 2) - (settingApp.sizeX / 2),  // Центрируем окно по ширене
              (settingApp.height / 2) - (settingApp.sizeY / 2), // Центрируем окно по высоте
              settingApp.sizeX, // Устанавливем ширину консоли
              settingApp.sizeY, // Устанавливаем высоту консоли
              TRUE);

    Tank tank(settingApp.dc); // Класс танка для отрисовки
    Bullet bullet(settingApp.dc); // Класс пули для отрисовки
    Rock rock_small(settingApp.dc, 's', 350); // Класс маленького камня для отрисовки
    Rock rock_big(settingApp.dc, 'b'); // Класс большого камня для отрисовки
    Storm storm(settingApp.dc);

    while (true) {
        
        settingApp.clearConsole();

        tank.disp();
        bullet.disp();
        rock_small.disp();
        rock_big.disp();
        storm.disp();

        tank.move();
        storm.move();

    };

}
