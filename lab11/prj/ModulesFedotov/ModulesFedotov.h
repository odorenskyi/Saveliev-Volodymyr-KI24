#ifndef MODULESFEDOTOV_H
#define MODULESFEDOTOV_H

#include <vector>
#include <string>
#include "struct_type_project_1.h"
// ���������� � ����
void saveToFile(const std::vector<Benefit>& list);

// ����� �� �����
void searchByCode(const std::vector<Benefit>& list, int code);

#endif