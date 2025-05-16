#include "struct_type_project_1.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <locale>

const std::string DATA_FILE = "benefit_data.bin";

// ���������� � ����
void saveToFile(const std::vector<Benefit>& list) {
    std::ofstream fout(DATA_FILE, std::ios::binary);
    if (!fout) {
        std::cerr << "������� ��� ������� ����� ��� ������.\n";
        return;
    }
    for (const Benefit& b : list) {
        if (b.benefitCode <= 0) continue; // ���������� ��������� ������
        fout.write(reinterpret_cast<const char*>(&b), sizeof(Benefit));
    }
    if (!fout.good()) {
        std::cerr << "������� ������� ��� ����� � ����.\n";
    }
    fout.close();
    std::cout << "��� ��������� � ����: " << DATA_FILE << "\n";
}

// ����� �� �����
void searchByCode(const std::vector<Benefit>& list, int code) {
    bool found = false;
    for (const Benefit& b : list) {
        if (b.benefitCode == code && b.benefitCode > 0) {
            std::cout << "\n����� ��������:\n";
            std::cout << "��� �����: " << b.benefitCode << "\n";
            std::cout << "���� �����: " << (b.description[0] ? b.description : "����") << "\n";
            std::cout << "��������: " << (b.documentName[0] ? b.documentName : "����") << "\n";
            std::cout << "����� ���������: " << (b.documentNumber[0] ? b.documentNumber : "����") << "\n";
            std::cout << "���� ��������� ���������: " << (b.documentDate[0] ? b.documentDate : "����") << "\n";
            std::cout << "������� 䳿 �����: " << (b.startDate[0] ? b.startDate : "����") << "\n";
            std::cout << "ʳ���� 䳿 �����: " << (b.endDate[0] ? b.endDate : "����") << "\n";
            std::cout << "������ ��������� �����������: " << (b.targetPurpose[0] ? b.targetPurpose : "����") << "\n";
            std::cout << "��������: " << (b.comment[0] ? b.comment : "����") << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "����� �� ����� " << code << " �� ��������.\n";
    }
}