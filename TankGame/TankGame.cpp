//#include "StdAfx.h" // Импорт в старых версиях VS
#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <stdlib.h>
#include <clocale>

#include "Map.h"
#include "Tank.h"
#include "ETank.h"
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
        COORD WCoord = { 0, 0 }; // Координаты по ширене
        DWORD nKol = 0; // Кол-во столбцов
        size_t xy = 160000; // Размер поля очистки
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

    Map map(settingApp.dc, settingApp.sizeX, settingApp.sizeY); // Класс карты

    while (true) {

        settingApp.clearConsole();
        map.disp();

        //Sleep(20);

    };

}
