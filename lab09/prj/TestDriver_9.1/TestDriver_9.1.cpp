#include <iostream>
#include "ModulesCovelyev.h"
#include <windows.h>
int main() {
    SetConsoleOutputCP(1251);
    double baseSalary = 450.0;
    double tax, pensionFund, unemploymentFund, reserveFund, militaryTax;

    // Очікувані значення
    double expectedTax = 450 * 0.15; // 67.5
    double expectedPensionFund = 450 * 0.02; // 9
    double expectedUnemploymentFund = 450 * 0.006; // 2.7
    double expectedReserveFund = 450 * 0.02; // 9
    double expectedMilitaryTax = 450 * 0.01; // 4.5
    double expectedNetSalary = 450 - (expectedTax + expectedPensionFund + expectedUnemploymentFund + expectedReserveFund + expectedMilitaryTax); // 357

    // Виклик функції
    double netSalary = CalculateSalary(baseSalary, tax, pensionFund, unemploymentFund, reserveFund, militaryTax);

    // Перевірка результатів
    std::cout << "Тест 1: Обчислення зарплати та виплат\n";
    std::cout << "Чистий дохід: Очікуваний = " << expectedNetSalary << ", Отриманий = " << netSalary << " -> "
        << (netSalary == expectedNetSalary ? "Passed" : "Failed") << "\n";
    std::cout << "Податок: Очікуваний = " << expectedTax << ", Отриманий = " << tax << " -> "
        << (tax == expectedTax ? "Passed" : "Failed") << "\n";
    std::cout << "Пенсійний фонд: Очікуваний = " << expectedPensionFund << ", Отриманий = " << pensionFund << " -> "
        << (pensionFund == expectedPensionFund ? "Passed" : "Failed") << "\n";
    std::cout << "Фонд безробіття: Очікуваний = " << expectedUnemploymentFund << ", Отриманий = " << unemploymentFund << " -> "
        << (unemploymentFund == expectedUnemploymentFund ? "Passed" : "Failed") << "\n";
    std::cout << "Резервний фонд: Очікуваний = " << expectedReserveFund << ", Отриманий = " << reserveFund << " -> "
        << (reserveFund == expectedReserveFund ? "Passed" : "Failed") << "\n";
    std::cout << "Військовий збір: Очікуваний = " << expectedMilitaryTax << ", Отриманий = " << militaryTax << " -> "
        << (militaryTax == expectedMilitaryTax ? "Passed" : "Failed") << "\n";
    system("pause");
    return 0;
}