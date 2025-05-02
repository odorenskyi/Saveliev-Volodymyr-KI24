#include <iostream>
#include <windows.h>
#include "ModulesCovelyev.h"

void RunBinaryCountTests() {
    // Масив із тестовими числами для 8 випадків
    int numbers[] = { 0, 1, 10, 15, 100, 7483650, 1024, 12345 };
    // Очікувані результати: для D0 = 0 — кількість нулів, для D0 = 1 — кількість одиниць
    int expectedResults[] = { 1, 1, 2, 4, 4, 15, 10, 6 };

    for (int testNum = 0; testNum < 8; testNum++) {
        int N = numbers[testNum];
        int expected = expectedResults[testNum];

        // Виклик функції
        int result = CalculateBinaryCount(N);

        // Виведення результатів
        std::cout << "Тест " << (testNum + 1) << ": Число = " << N << "\n";
        std::cout << "Очікуваний результат: " << expected << ", Отриманий = " << result << " -> "
            << (result == expected ? "Passed" : "Failed") << "\n\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    RunBinaryCountTests();
    system("pause");
    return 0;
}
