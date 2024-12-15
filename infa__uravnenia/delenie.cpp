#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
	return exp(x) - exp(-x) - 2;
}
double a = 0;
double b = 1;
const double E = 0.000001;
double c;
int counter = 0;

int main()
{
	setlocale(LC_ALL, "Russian");
	if (f(a) * f(b) < 0)
	{
		while (abs(a - b) > E)
		{
			c = (a + b) / 2;
			if (f(a) * f(c) > 0)
				a = c;
			else b = c;
			counter++;
		}
		cout << "Первое решение: " << a << endl;
		cout << "Второе решение: " << b << endl;
		cout << "Количество потребовавшихся делений: " << counter << endl;
	}
	else cout << "Решений на выделенном промежутке нет!";
	
	return 0;
}