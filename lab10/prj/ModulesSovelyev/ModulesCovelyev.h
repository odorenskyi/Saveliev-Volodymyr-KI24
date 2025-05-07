#pragma once
#include <string>
#include <iostream>
using namespace std;
double s_calculation(double x, double y, double z);
double CalculateSalary(double baseSalary, double& tax, double& pensionFund, double& unemploymentFund, double& reserveFund, double& militaryTax);
void CalculateApartmentCost(double area, double& costUSA, double& costEU);
int CalculateBinaryCount(int N);
void process_text_file(const string& input_filename, const string& output_filename,
    const string& author_name, const string& institution,
    const string& city, const string& country, int year); 
