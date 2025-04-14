#include <iostream>
#include <windows.h>
#include "ModulesCovelyev.h"
#include <cmath>
using namespace std;

// Підключення функції
const double PI = 3.141592653589793;

void test_s_calculation() {
	double x[10] = { 1.0,  0.5,  0.25,  1.5,  2.0,
					 1.25, 3.0,  3.05,  4.5,  5.0 };
	double y[10] = { 2.0,  1.5,  0.5,   1.0,  2.5,
					 3.5,  0.75, 2.2,   4.0,  1.1 };
	double z[10] = { 3.0,  2.5,  1.5,   4.0,  5.0,
					 2.75, 4.5,  3.85,  6.0,  2.2 };
	double expected[10] = { 8.2653243762602209, 6.2000537742164035, 5.6182388681951529, 10.259097933589924,  12.976441650902700,
							14.221463131479398, 18.144713263807148,12.495582744038261,25.669110617813146, 18.642590296156861 };

	cout << "Запуск тестів для функції s_calculation:\n\n";


	for (int i = 0; i < 10; i++) {
		double result = s_calculation(x[i], y[i], z[i]);
		cout << "Тест #" << (i + 1)
			<< " | x = " << x[i]
			<< ", y = " << y[i]
				<< ", z = " << z[i]
					<< " | Результат: " << result
						<< " | Очікувано: " << expected[i];
					if (fabs(result - expected[i]) < 1e-6) {
						cout << " -> PASSED\n";
					}
					else {
						cout << " -> FAILED\n";
					}
	}
}

int main() {
	SetConsoleOutputCP(1251);
	test_s_calculation();
	system("pause");
	return 0;
}
