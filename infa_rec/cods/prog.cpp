#include <iostream>
#include<cmath>
using namespace std;

double rec(int n, double x, double S = 0)
{
	if (n == 0)
		return S;
	else return rec(n - 1, x, S + pow(-1, n) * (pow((1 + x), 2 * n) / n));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x; 
	int n;
	cout << "Введите значение x: ";
	cin >> x;
	cout << "Введите значение n: ";
	cin >> n;
	while (n < 0)
	{
		cout << "Неверный ввод! Введите значение n: ";
		cin >> n;
	}
	cout << "S = " << rec(n, x) << endl;

	return 0;
}