#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;
double f(double x);
double f_pr(double x);
int rec(double x0, double x1);

const int a = 0;  
const int b = 1;
int counter = 0;
double x0, x1;

const double e = M_E;
const double E = 0.000001;
bool flag = 1;

int main() 
{
	setlocale(LC_ALL, "Russian");

	for (double i = a; i <= b; i += E)
	{
		if (abs(f_pr(i)) >= 1)
			flag = 0;
	}
	if (flag)
	{
		do
		{
			cout << "Введите значение x0, лежащее на отрезке [" << a << ";" << b << "]: ";
			cin >> x0;
		} while ((x0 < a) || (x0 > b));

		rec(x0, x1);
	}
	else { cout << "Условие совместимости функции невыполнено!"; }
	
	return 0;
}

double f(double x)
{
	return log(1 + pow(2, 0.5));
}

double f_pr(double x)
{
	return 1/(1 + pow(2, 0.5)) * 0;
}

int rec(double x0, double x1)
{
	counter++;
	x1 = f(x0);
	if (abs(x0 - x1) <= E)
	{
		cout << "Первое решение: " << x0 << endl;
		cout << "Второе решение: " << x1 << endl;
		cout << "Количество потребовавшийхся итераций: " << counter << endl;
		return 0;
	}
	x0 = x1;
	rec(x0, x1);
}

