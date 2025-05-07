#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include "ModulesCovelyev.h"

using namespace std;

// Допоміжна функція для створення тимчасового вхідного файлу
void createInputFile(const string& filename, const string& content) {
    ofstream file(filename, ios::binary);
    file << content;
    file.close();
}

// Допоміжна функція для читання вмісту вихідного файлу
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back(); // Видаляємо \r для Windows
        }
        content += line + "\n";
    }
    file.close();
    return content;
}

void testAppendPunctuationCount() {
    // Тестові кейси
    struct TestCase {
        string inputContent;
        string expectedOutputPrefix; // Очікуваний вміст без дати/часу
    };

    TestCase testCases[] = {
        // Тест 1: Речення з пунктуацією (8 знаків)
        {
            "Це текст, із кількома знаками! Пунктуація: так, ще.\nДругий рядок; із комами,, і крапками.\n",
            "Кількість знаків пунктуації: 9\n"
        },
        // Тест 2: Текст без пунктуації (0 знаків)
        {
            "Це текст без пунктуації\nДругий рядок також без знаків\n",
            "Кількість знаків пунктуації: 0\n"
        },
        // Тест 3: Речення з пунктуацією (9 знаків)
        {
            "Це текст, із кількома знаками! Пунктуація: так, ще.\nДругий рядок; із комами, і крапками, ще.\n",
            "Кількість знаків пунктуації: 9\n"
        }
    };

    for (int i = 0; i < 3; i++) {
        // Створення тимчасових вхідного та вихідного файлів
        string inputFile = "test_input_" + to_string(i + 1) + ".txt";
        string outputFile = "test_output_" + to_string(i + 1) + ".txt";

        // Видаляємо файли, якщо вони існують
        remove(inputFile.c_str());
        remove(outputFile.c_str());

        // Підготовка вхідного файлу
        createInputFile(inputFile, testCases[i].inputContent);

        // Виклик функції
        append_punctuation_count(inputFile, outputFile);

        // Зчитування фактичного вмісту вихідного файлу
        string actualOutput = readOutputFile(outputFile);

        // Очікуваний вміст (префікс + дата/час)
        string expectedOutputPrefix = testCases[i].expectedOutputPrefix;

        // Виведення результатів
        cout << "Тест кейс " << (i + 1) << " | Вхідний файл: " << inputFile << " | Вихідний файл: " << outputFile << "\n";
        cout << "Вхідний вміст:\n" << testCases[i].inputContent << "\n";
        cout << "Очікуваний вміст (префікс):\n" << expectedOutputPrefix << "<дата та час>\n" << "\n";
        cout << "Фактичний вміст:\n" << actualOutput << "\n";

        // Перевірка
        bool passed = (actualOutput.find(expectedOutputPrefix) == 0 &&
            actualOutput.find("Дата та час запису: ") != string::npos);

        if (passed) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
            if (actualOutput.find(expectedOutputPrefix) != 0) {
                cout << "Помилка: Фактичний вміст не починається з очікуваного префікса\n";
            }
            if (actualOutput.find("Дата та час запису: ") == string::npos) {
                cout << "Помилка: Рядок 'Дата та час запису: ' не знайдено\n";
            }
        }
        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251); // Підтримка українських символів
    testAppendPunctuationCount();
    system("pause");
    return 0;
}