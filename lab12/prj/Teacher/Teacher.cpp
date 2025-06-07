#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "ModulesSavelyev.h"

using namespace std;

struct TestSuite {
    float length = 0;         
    float width = 0;          
    float height = 0;         
    float expSurfaceArea = 0; 
    float resultSurfaceArea = 0; 
};


void createOrUpdateInputFile(const string& filename, const vector<TestSuite>& tests) {
    ofstream file(filename);
    if (file.is_open()) {
        file << setw(10) << left << "Length" << "|"
            << setw(10) << left << "Width" << "|"
            << setw(10) << left << "Height" << "|"
            << setw(20) << left << "Expected Surface Area" << "|"
            << setw(20) << left << "Result Surface Area" << "|\n";
        file << string(70, '-') << "\n";
        for (const auto& test : tests) {
            file << fixed << setprecision(2)
                << setw(10) << left << test.length << "|"
                << setw(10) << left << test.width << "|"
                << setw(10) << left << test.height << "|"
                << setw(20) << left << test.expSurfaceArea << "|"
                << setw(20) << left << test.resultSurfaceArea << "|\n"; 
        }
        file.close();
    }
}

string readOutputFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            content += line + "\n";
        }
        file.close();
    }
    return content;
}

vector<TestSuite> readCVSFiles(const string& filePath) {
    ifstream testSuite(filePath);
    vector<string> row;
    vector<TestSuite> autotest;
    TestSuite ts;
    string line, value;
    if (testSuite.is_open()) {
        getline(testSuite, line); 
        getline(testSuite, line); 
        while (getline(testSuite, line)) {
            row.clear();
            stringstream s(line);
            int count = 0;
            while (getline(s, value, '|')) {
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                if (!value.empty() && count < 5) {
                    if (count == 0) ts.length = stof(value);
                    else if (count == 1) ts.width = stof(value);
                    else if (count == 2) ts.height = stof(value);
                    else if (count == 3) ts.expSurfaceArea = stof(value);
                    else if (count == 4) ts.resultSurfaceArea = !value.empty() ? stof(value) : 0;
                    count++;
                }
            }
            if (count >= 4) {
                autotest.push_back(ts);
            }
        }
        testSuite.close();
    }
    return autotest;
}

void printTable(const vector<TestSuite>& tests) {
    cout << setw(10) << left << "Length" << "|"
        << setw(10) << left << "Width" << "|"
        << setw(10) << left << "Height" << "|"
        << setw(20) << left << "Expected Surface Area" << "|"
        << setw(20) << left << "Result Surface Area" << "|\n";
    cout << string(70, '-') << "\n";
    for (size_t i = 0; i < tests.size(); i++) {
        cout << fixed << setprecision(2)
            << setw(10) << left << tests[i].length << "|"
            << setw(10) << left << tests[i].width << "|"
            << setw(10) << left << tests[i].height << "|"
            << setw(20) << left << tests[i].expSurfaceArea << "|"
            << setw(20) << left << tests[i].resultSurfaceArea << "|\n";
    }
    cout << endl;
}

void updateInputFile(const string& filename, const vector<TestSuite>& tests) {
    ofstream file(filename);
    if (file.is_open()) {
        file << setw(10) << left << "Length" << "|"
            << setw(10) << left << "Width" << "|"
            << setw(10) << left << "Height" << "|"
            << setw(20) << left << "Expected Surface Area" << "|"
            << setw(20) << left << "Result Surface Area" << "|\n";
        file << string(70, '-') << "\n";
        for (const auto& test : tests) {
            file << fixed << setprecision(2)
                << setw(10) << left << test.length << "|"
                << setw(10) << left << test.width << "|"
                << setw(10) << left << test.height << "|"
                << setw(20) << left << test.expSurfaceArea << "|"
                << setw(20) << left << test.resultSurfaceArea << "|\n";
        }
        file.close();
    }
}

void testSurfaceArea(vector<TestSuite>& tests, ofstream& testResult) {
    ClassLab12_Savelyev rect;
    for (size_t i = 0; i < tests.size(); i++) {
        rect.setA(tests[i].length);
        rect.setB(tests[i].width);
        rect.setH(tests[i].height);
        tests[i].resultSurfaceArea = rect.getSurfaceArea(); 

        if (fabs(tests[i].resultSurfaceArea - tests[i].expSurfaceArea) < 0.01) {
            testResult << "test №" << i + 1 << " (Surface Area) -> passed" << endl << endl;
        }
        else {
            testResult << "test №" << i + 1 << " (Surface Area) -> failed" << endl
                << "відповіді не збігаються" << endl
                << "Це повинно бути -> " << fixed << setprecision(2) << tests[i].expSurfaceArea << " sq cm" << endl
                << "Отримано відповідь -> " << fixed << setprecision(2) << tests[i].resultSurfaceArea << " sq cm" << endl << endl;
        }
    }
}

int main() {
    const string inputFilePath = "TS.txt";
    vector<TestSuite> defaultTests = {
        {5.25, 4.0, 3.0, 97.50},   
        {15.5, 2.0, 1.0, 97.00},   
        {25.75, 3.0, 2.0, 269.50}, 
        {36.0, 5.0, 1.0, 442.00},  
        {46.25, 2.0, 1.0, 281.50}  
    };

    createOrUpdateInputFile(inputFilePath, defaultTests);

    ofstream testResult("TestResult.txt");
    if (!testResult.is_open()) {
        cout << "Не вдалося створити файл результатів!" << endl;
        return -1;
    }

    vector<TestSuite> autotest = readCVSFiles(inputFilePath);

    if (!autotest.empty()) {
        testSurfaceArea(autotest, testResult);
        printTable(autotest); 
    }
    else {
        cout << "Помилка: файл TS.txt порожній або не знайдено!" << endl;
    }

    if (!autotest.empty()) {
        updateInputFile(inputFilePath, autotest);
    }

    testResult.close();

    string outputContent = readOutputFile("TestResult.txt");
    cout << outputContent;

    system("pause");
    return 0;
}