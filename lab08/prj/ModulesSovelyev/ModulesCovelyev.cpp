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
