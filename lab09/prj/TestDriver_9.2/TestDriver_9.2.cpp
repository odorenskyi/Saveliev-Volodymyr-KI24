#include <iostream>
#include <windows.h>
#include "ModulesCovelyev.h"

int main() {
    SetConsoleOutputCP(1251);
    double area;
    double costUSA, costEU;

    // Тест 1: Площа 36 м² (≤37)
    area = 36.0;
    double expectedCostUSA1 = 3788; // Для площі ≤37 м²
    double expectedCostEU1 = 8;     // Для площі ≤37 м²
    CalculateApartmentCost(area, costUSA, costEU);
    std::cout << "Тест 1: Площа = " << area << " м²\n";
    std::cout << "Вартість у США: Очікувана = " << expectedCostUSA1 << ", Отримана = " << costUSA << " -> "
        << (costUSA == expectedCostUSA1 ? "Passed" : "Failed") << "\n";
    std::cout << "Вартість у ЄС: Очікувана = " << expectedCostEU1 << ", Отримана = " << costEU << " -> "
        << (costEU == expectedCostEU1 ? "Passed" : "Failed") << "\n\n";

    // Тест 2: Площа 38 м² (≤39)
    area = 38.0;
    double expectedCostUSA2 = 3940; // Для площі ≤39 м²
    double expectedCostEU2 = 9;     // Для площі ≤39 м²
    CalculateApartmentCost(area, costUSA, costEU);
    std::cout << "Тест 2: Площа = " << area << " м²\n";
    std::cout << "Вартість у США: Очікувана = " << expectedCostUSA2 << ", Отримана = " << costUSA << " -> "
        << (costUSA == expectedCostUSA2 ? "Passed" : "Failed") << "\n";
    std::cout << "Вартість у ЄС: Очікувана = " << expectedCostEU2 << ", Отримана = " << costEU << " -> "
        << (costEU == expectedCostEU2 ? "Passed" : "Failed") << "\n\n";

    // Тест 3: Площа 40 м² (≤41)
    area = 40.0;
    double expectedCostUSA3 = 4142; // Для площі ≤41 м²
    double expectedCostEU3 = 10;    // Для площі ≤41 м²
    CalculateApartmentCost(area, costUSA, costEU);
    std::cout << "Тест 3: Площа = " << area << " м²\n";
    std::cout << "Вартість у США: Очікувана = " << expectedCostUSA3 << ", Отримана = " << costUSA << " -> "
        << (costUSA == expectedCostUSA3 ? "Passed" : "Failed") << "\n";
    std::cout << "Вартість у ЄС: Очікувана = " << expectedCostEU3 << ", Отримана = " << costEU << " -> "
        << (costEU == expectedCostEU3 ? "Passed" : "Failed") << "\n\n";

    // Тест 4: Площа 42 м² (≤43)
    area = 42.0;
    double expectedCostUSA4 = 4344; // Для площі ≤43 м²
    double expectedCostEU4 = 11;    // Для площі ≤43 м²
    CalculateApartmentCost(area, costUSA, costEU);
    std::cout << "Тест 4: Площа = " << area << " м²\n";
    std::cout << "Вартість у США: Очікувана = " << expectedCostUSA4 << ", Отримана = " << costUSA << " -> "
        << (costUSA == expectedCostUSA4 ? "Passed" : "Failed") << "\n";
    std::cout << "Вартість у ЄС: Очікувана = " << expectedCostEU4 << ", Отримана = " << costEU << " -> "
        << (costEU == expectedCostEU4 ? "Passed" : "Failed") << "\n\n";

    // Тест 5: Площа 46 м² (>43)
    area = 46.0;
    double expectedCostUSA5 = 4546; // Для площі >43 м²
    double expectedCostEU5 = 12;    // Для площі >43 м²
    CalculateApartmentCost(area, costUSA, costEU);
    std::cout << "Тест 5: Площа = " << area << " м²\n";
    std::cout << "Вартість у США: Очікувана = " << expectedCostUSA5 << ", Отримана = " << costUSA << " -> "
        << (costUSA == expectedCostUSA5 ? "Passed" : "Failed") << "\n";
    std::cout << "Вартість у ЄС: Очікувана = " << expectedCostEU5 << ", Отримана = " << costEU << " -> "
        << (costEU == expectedCostEU5 ? "Passed" : "Failed") << "\n\n";
    system("pause");
    return 0;
}
