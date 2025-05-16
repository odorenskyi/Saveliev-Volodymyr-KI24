#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <locale>
#include <windows.h>

#include "struct_type_project_1.h" 
#include "ModulesBalan.h"
#include "ModulesFedotov.h"
#include "ModulesSavelyev.h"

std::vector<Benefit> loadFromFile() {
    std::vector<Benefit> list;
    std::ifstream fin("benefit_data.bin", std::ios::binary);
    if (fin) {
        Benefit b;
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(Benefit))) {
            if (b.benefitCode > 0) {
                list.push_back(b);
            }
        }
        fin.close();
    }
    return list;
}

void menu() {
    std::vector<Benefit> directory = loadFromFile();
    int choice;
    do {
        std::cout << "\n||| ДОВІДНИК ПІЛЬГ: МЕНЮ |||\n"; 
        std::cout << "1. Знайти пільгу за кодом\n"; 
        std::cout << "2. Показати всі записи\n"; 
        std::cout << "3. Зберегти у текстовий файл\n"; 
        std::cout << "4. Створити новий запис\n"; 
        std::cout << "5. Видалити пільгу за кодом\n"; 
        std::cout << "0. Завершити та зберегти\n"; 
        std::cout << "Оберіть опцію: "; 
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            int code;
            std::cout << "Вкажіть код пільги для пошуку: "; 
            std::cin >> code;
            std::cin.ignore();
            searchByCode(directory, code);
            break;
        }
        case 2:
            displayAll(directory);
            break;
        case 3: {
            std::string filename;
            std::cout << "Вкажіть назву файлу для експорту: ";
            std::getline(std::cin, filename);
            exportToTextFile(directory, filename);
            break;
        }
        case 4:
            addBenefit(directory);
            break;
        case 5: {
            int code;
            std::cout << "Вкажіть код пільги для видалення: ";
            std::cin >> code;
            std::cin.ignore();
            deleteByCode(directory, code);
            break;
        }
        case 0:
            saveToFile(directory);
            std::cout << "Дані успішно збережено. Програма завершує роботу...\n"; 
            break;
        default:
            std::cout << "Помилка вибору. Виберіть ще раз.\n"; 
        }
    } while (choice != 0);
}

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    menu();
    system("pause");
    return 0;
}