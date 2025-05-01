#include <iostream>
#include <cmath>  
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
