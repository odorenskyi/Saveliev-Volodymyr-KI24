#ifndef MODULESBALAN_H
#define MODULESBALAN_H

#include <vector>
#include <string>
#include "struct_type_project_1.h"
// ��������� ��� ������
void displayAll(const std::vector<Benefit>& list);

// ������� � ��������� ����
void exportToTextFile(const std::vector<Benefit>& list, const std::string& filename);

#endif