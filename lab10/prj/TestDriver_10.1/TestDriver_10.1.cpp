#include "ModulesCovelyev.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Допоміжна функція для створення тимчасового вхідного файлу з заданим вмістом
void createInputFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

// Допоміжна функція для читання вмісту вихідного файлу
string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    file.close();
    return content;
}

void test_process_text_file() {
    // Тестові кейси
    struct TestCase {
        string test_name;
        string input_content;
        string expected_output;
        string author_name;
        string institution;
        string city;
        string country;
        int year;
    };

    TestCase test_cases[] = {
        {
            "Basic Functionality",
            "Це перший абзац про те що Україна славна та непереможна.\n\n"
            "Другий абзац розповідає про університет у місті Київ.\n\n"
            "Третій абзац згадує блокнот, який я купив учора.\n",
            "Автор: Володимир Савельєв\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік: 2025\n\n"
            "Кількість абзаців: 3\n"
            "Наявність слів:\n"
            "Україна: так\n"
            "Університет: так\n"
            "Блокнот: так\n",
            "Володимир Савельєв",
            "ЦНТУ",
            "Кропивницький",
            "Україна",
            2025
        },
        {
            "No Keywords",
            "Це текст без ключових слів.\n",
            "Автор: Володимир Савельєв\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік: 2025\n\n"
            "Кількість абзаців: 1\n"
            "Наявність слів:\n"
            "Україна: ні\n"
            "Університет: ні\n"
            "Блокнот: ні\n",
            "Володимир Савельєв",
            "ЦНТУ",
            "Кропивницький",
            "Україна",
            2025
        },
        {
            "Empty File",
            "",
            "Автор: Володимир Савельєв\n"
            "Установа: ЦНТУ\n"
            "Місто: Кропивницький\n"
            "Країна: Україна\n"
            "Рік: 2025\n\n"
            "Кількість абзаців: 0\n"
            "Наявність слів:\n"
            "Україна: ні\n"
            "Університет: ні\n"
            "Блокнот: ні\n",
            "Володимир Савельєв",
            "ЦНТУ",
            "Кропивницький",
            "Україна",
            2025
        }
    };

    for (int i = 0; i < 3; i++) {
        string input_file = "test_input_" + to_string(i + 1) + ".txt";
        string output_file = "test_output_" + to_string(i + 1) + ".txt";

        createInputFile(input_file, test_cases[i].input_content);

        process_text_file(input_file, output_file,
            test_cases[i].author_name,
            test_cases[i].institution,
            test_cases[i].city,
            test_cases[i].country,
            test_cases[i].year);

        string actual_output = readOutputFile(output_file);

        cout << "Тест кейс " << (i + 1) << " (" << test_cases[i].test_name << ") | Вхід: \"" << test_cases[i].input_content << "\"\n";
        cout << "Очікуваний результат:\n" << test_cases[i].expected_output << "\n";
        cout << "Фактичний результат:\n" << actual_output << "\n";

        if (actual_output == test_cases[i].expected_output) {
            cout << "Результат: PASSED\n";
        }
        else {
            cout << "Результат: FAILED\n";
        }

        cout << "--------------------------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(1251); // Українське кодування в консолі Windows
    test_process_text_file();
    system("pause");
    return 0;
}
