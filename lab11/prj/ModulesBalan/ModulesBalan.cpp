#include "struct_type_project_1.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <locale>

const std::string DATA_FILE = "benefit_data.bin";

// ��������� ��� ������
void displayAll(const std::vector<Benefit>& list) {
    if (list.empty()) {
        std::cout << "������� �������.\n";
        return;
    }

    std::cout << "\n�� ������ ��������:\n";
    for (const Benefit& b : list) {
        if (b.benefitCode <= 0) {
            std::cout << "����������� ����� (����������� ��� �����).\n";
            continue;
        }

        std::cout << "-------------------------\n";
        std::cout << "��� �����: " << b.benefitCode << "\n";
        std::cout << "���� �����: " << (b.description[0] ? b.description : "����") << "\n";
        std::cout << "��������: " << (b.documentName[0] ? b.documentName : "����") << "\n";
        std::cout << "����� ���������: " << (b.documentNumber[0] ? b.documentNumber : "����") << "\n";
        std::cout << "���� ��������� ���������: " << (b.documentDate[0] ? b.documentDate : "����") << "\n";
        std::cout << "������� 䳿 �����: " << (b.startDate[0] ? b.startDate : "����") << "\n";
        std::cout << "ʳ���� 䳿 �����: " << (b.endDate[0] ? b.endDate : "����") << "\n";
        std::cout << "������ ��������� �����������: " << (b.targetPurpose[0] ? b.targetPurpose : "����") << "\n";
        std::cout << "��������: " << (b.comment[0] ? b.comment : "����") << "\n";
    }
}

// ������� � ��������� ����
void exportToTextFile(const std::vector<Benefit>& list, const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "�� ������� ������� ���� ��� ������: " << filename << "\n";
        return;
    }

    for (const Benefit& b : list) {
        if (b.benefitCode <= 0) continue; // ���������� ��������� ������
        fout << "��� �����: " << b.benefitCode << "\n";
        fout << "���� �����: " << (b.description[0] ? b.description : "����") << "\n";
        fout << "��������: " << (b.documentName[0] ? b.documentName : "����") << "\n";
        fout << "����� ���������: " << (b.documentNumber[0] ? b.documentNumber : "����") << "\n";
        fout << "���� ��������� ���������: " << (b.documentDate[0] ? b.documentDate : "����") << "\n";
        fout << "������� 䳿 �����: " << (b.startDate[0] ? b.startDate : "����") << "\n";
        fout << "ʳ���� 䳿 �����: " << (b.endDate[0] ? b.endDate : "����") << "\n";
        fout << "������ ��������� �����������: " << (b.targetPurpose[0] ? b.targetPurpose : "����") << "\n";
        fout << "��������: " << (b.comment[0] ? b.comment : "����") << "\n";
        fout << "---------------------------\n";
    }

    fout.close();
    std::cout << "������������ � ����: " << filename << "\n";
}