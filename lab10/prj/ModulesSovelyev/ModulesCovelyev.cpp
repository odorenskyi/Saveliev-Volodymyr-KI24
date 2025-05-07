#include <iostream>
#include <cmath>  
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589793;

double s_calculation(double x, double y, double z) {
    if (y == 0) {
        cout << "Помилка: ділення на нуль неможливе (y не повинен бути 0)." << endl;
        return 1;
    }
    double part1 = sqrt(pow(z, 2) * y / 2.0);      
    double part2 = (PI * x + exp(abs(y))) / y;  
    double S = part1 + part2;
    return S;
}
double CalculateSalary(double baseSalary, double& tax, double& pensionFund, double& unemploymentFund, double& reserveFund, double& militaryTax) {
    tax = baseSalary * 0.15;
    pensionFund = baseSalary * 0.02;
    unemploymentFund = baseSalary * 0.006;
    reserveFund = baseSalary * 0.02;
    militaryTax = baseSalary * 0.01;
    double totalDeductions = tax + pensionFund + unemploymentFund + reserveFund + militaryTax;
    return baseSalary - totalDeductions;
}
void CalculateApartmentCost(double area, double& costUSA, double& costEU) {
    if (area <= 37) costUSA = 3788;
    else if (area <= 39) costUSA = 3940;
    else if (area <= 41) costUSA = 4142;
    else if (area <= 43) costUSA = 4344;
    else costUSA = 4546;

    if (area <= 37) costEU = 8;
    else if (area <= 39) costEU = 9;
    else if (area <= 41) costEU = 10;
    else if (area <= 43) costEU = 11;
    else costEU = 12;
}
int CalculateBinaryCount(int N) {
    if (N < 0 || N > 7483650) {
        return -1;
    }

    int zeros = 0;
    int ones = 0;
    int temp = N;

    while (temp > 0) {
        (temp & 1) ? ones++ : zeros++;
        temp >>= 1;
    }

    if (N == 0) {
        zeros = 1;
        ones = 0;
    }

    return (N & 1) ? ones : zeros;
}
void process_text_file(const string& input_filename, const string& output_filename,
    const string& author_name, const string& institution,
    const string& city, const string& country, int year) {

    ifstream in_file(input_filename);
    ofstream out_file(output_filename);

    if (!in_file.is_open() || !out_file.is_open()) {
        cerr << "Помилка: неможливо відкрити файли!" << endl;
        return;
    }

    out_file << "Автор: " << author_name << "\n";
    out_file << "Установа: " << institution << "\n";
    out_file << "Місто: " << city << "\n";
    out_file << "Країна: " << country << "\n";
    out_file << "Рік: " << year << "\n\n";

    string line;
    int paragraph_count = 0;
    bool has_ukraine = false, has_university = false, has_notebook = false;
    bool in_paragraph = false;

    string ukraine_words[] = { "україна", "україни", "україні", "україну", "Україна", "України", "Україні", "Україну" };
    string university_words[] = { "університет", "університету", "університети", "університетів", "Університет", "Університету", "Університети", "Університетів" };
    string notebook_words[] = { "блокнот", "блокнота", "блокноту", "блокноти", "Блокнот", "Блокнота", "Блокноту", "Блокноти" };

    while (getline(in_file, line)) {
        if (line.empty()) {
            if (in_paragraph) {
                paragraph_count++;
                in_paragraph = false;
            }
        }
        else {
            in_paragraph = true;

            for (const string& word : ukraine_words) {
                if (!has_ukraine && line.find(word) != string::npos) {
                    has_ukraine = true;
                }
            }

            for (const string& word : university_words) {
                if (!has_university && line.find(word) != string::npos) {
                    has_university = true;
                }
            }

            for (const string& word : notebook_words) {
                if (!has_notebook && line.find(word) != string::npos) {
                    has_notebook = true;
                }
            }
        }
    }

    if (in_paragraph) {
        paragraph_count++;
    }

    out_file << "Кількість абзаців: " << paragraph_count << "\n";
    out_file << "Наявність слів:\n";
    out_file << "Україна: " << (has_ukraine ? "так" : "ні") << "\n";
    out_file << "Університет: " << (has_university ? "так" : "ні") << "\n";
    out_file << "Блокнот: " << (has_notebook ? "так" : "ні") << "\n";
}
void append_punctuation_count(const string& input_filename, const string& output_filename) {
    ifstream in_file(input_filename);
    if (!in_file.is_open()) {
        ofstream error_file(output_filename);
        error_file << "Помилка: неможливо відкрити файл!\n";
        error_file.close();
        return;
    }

    stringstream buffer;
    buffer << in_file.rdbuf();
    string content = buffer.str();
    in_file.close();

    // Видаляємо \r для коректної роботи на Windows
    content.erase(remove(content.begin(), content.end(), '\r'), content.end());

    int punctuation_count = count_if(content.begin(), content.end(), [](char c) {
        return c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':';
        });

    ofstream out_file(output_filename);
    out_file << "Кількість знаків пунктуації: " << punctuation_count << "\n";
    time_t now = time(nullptr);
    tm local_time{};
#ifdef _WIN32
    localtime_s(&local_time, &now);
#else
    local_time = *localtime(&now);
#endif
    out_file << "Дата та час запису: " << put_time(&local_time, "%Y-%m-%d %H:%M:%S") << "\n";
    out_file.close();
}
void append_calculation_results(const string& output_filename, double x, double y, double a, unsigned int b) {
    ofstream out_file(output_filename, ios::app);
    if (!out_file.is_open()) {
        cerr << "Помилка: неможливо відкрити файл!\n";
        return;
    }

    double result = s_calculation(x, y, a);
    out_file << fixed << setprecision(6);
    out_file << "\nРезультат s_calculation(" << x << ", " << y << ", " << a << "): " << result << "\n";

    string binary = b == 0 ? "0" : "";
    unsigned int temp = b;
    while (temp > 0) {
        binary = (temp % 2 == 0 ? "0" : "1") + binary;
        temp /= 2;
    }

    out_file << "Число " << b << " у двійковому коді: " << binary << "\n";
}