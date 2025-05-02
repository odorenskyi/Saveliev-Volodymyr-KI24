#include <iostream>
#include <windows.h>
#include "ModulesCovelyev.h"
#include <OutputName.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(65001);
    SetConsoleCP(1251);
    Information();
    char choice, exitChoice;

    do {
        std::cout << "Виберіть дію:\n";
        std::cout << "'v' - обчислення s_calculation\n";
        std::cout << "'n' - обчислення зарплати (задача 9.1)\n";
        std::cout << "'m' - обчислення вартості квартир (задача 9.2)\n";
        std::cout << "'q' - обчислення кількості двійкових нулів або одиниць (задача 9.3)\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 'v': {
            double x, y, z;
            std::cout << "Введіть x: ";
            std::cin >> x;
            std::cout << "Введіть y: ";
            std::cin >> y;
            std::cout << "Введіть z: ";
            std::cin >> z;
            double result = s_calculation(x, y, z);
            std::cout << "Результат S = " << result << "\n";
            break;
        }
        case 'n': {
            double baseSalary, tax, pensionFund, unemploymentFund, reserveFund, militaryTax;
            std::cout << "Введіть базову зарплату (грн): ";
            std::cin >> baseSalary;
            double netSalary = CalculateSalary(baseSalary, tax, pensionFund, unemploymentFund, reserveFund, militaryTax);
            std::cout << "Чистий дохід: " << netSalary << " грн\n";
            std::cout << "Податок: " << tax << " грн\n";
            std::cout << "Пенсійний фонд: " << pensionFund << " грн\n";
            std::cout << "Фонд безробіття: " << unemploymentFund << " грн\n";
            std::cout << "Резервний фонд: " << reserveFund << " грн\n";
            std::cout << "Військовий збір: " << militaryTax << " грн\n";
            break;
        }
        case 'm': {
            double area, costUSA, costEU;
            std::cout << "Введіть площу квартири (м²): ";
            std::cin >> area;
            CalculateApartmentCost(area, costUSA, costEU);
            std::cout << "Вартість у США: " << costUSA << " (у.о.)\n";
            std::cout << "Вартість у ЄС: " << costEU << " (у.о.)\n";
            break;
        }
        case 'q': {
            int N;
            std::cout << "Введіть число N (0-7483650): ";
            std::cin >> N;
            int result = CalculateBinaryCount(N);
            if (result == -1) {
                std::cout << "Помилка: число поза діапазоном (0-7483650).\n";
            }
            else {
                std::cout << "Результат: " << result << " (";
                std::cout << ((N & 1) ? "кількість одиниць" : "кількість нулів") << ")\n";
            }
            break;
        }
        default: {
            std::cout << "Невірний символ!\n";
            Beep(500, 500); // Звуковий сигнал про помилку
            break;
        }
        }

        std::cout << "Бажаєте завершити? ('w' або 'W' для виходу, будь-який інший символ для продовження): ";
        std::cin >> exitChoice;

    } while (exitChoice != 'w' && exitChoice != 'W');

    std::cout << "Програма завершена.\n";
    system("pause");
    return 0;
}