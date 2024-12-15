#include <iostream>
#include <cmath>

using namespace std;

double x0, x1;
const int a = 0;
const int b = 1;
const double E = 0.000001;
int counter = 1;
bool flag = 1;

double f(double x)
{
	return exp(x) - exp(-x) - 2;
}

double f1(double x)
{
	return exp(x) + exp(-x);
}

double f2(double x)
{
	return exp(x) - exp(-x);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (f(a) * f2(a) > 0)
	{
		x0 = a;
		x1 = x0 - (f(x0) / f1(x0));
	}
	else if (f(b) * f2(b) > 0)
	{
		x0 = b;
		x1 = x0 - (f(x0) / f1(x0));
	}
	else
	{
		cout << "На заданном интервале невозможно определить корень уравнения!";
		flag = 0;
	}

	while ((abs(x0 - x1) > E) && flag)
	{
		x0 = x1;
		x1 = x0 - (f(x0) / f1(x0));
		counter++;
	}
	if (flag)
	{
		cout << "Первый корень уравнения: " << x0 << endl;
		cout << "Второй корень уравнения: " << x1 << endl;
		cout << "Количесвто потребовавшихся касательных: " << counter << endl;
	}
	return 0;
}