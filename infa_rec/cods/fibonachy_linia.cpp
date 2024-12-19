#include <iostream>
using namespace std;

int fib(int n, int a = 0, int b = 1)
{
	if (n == 1)
		return a;

	else return fib(n - 1, b, a + b);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ����������� ������ ������������������: ";
	cin >> n;
	while (n < 0)
	{
		cout << "�������� �������� ����, ������� ����������� ����� ������������������ ��������: ";
		cin >> n;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << fib(i) << endl;
	}
	return 0;
}