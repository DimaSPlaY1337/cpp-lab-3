// cpp-lab-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>

using namespace std;

int n, m;

int recursion(int i, int n, int Masha, int Petya, long* massive)
{
	cout << " i = " << i << "; " <<
		"n = " << n << "; " <<
		"Masha = " << Masha << "; " <<
		"Petya = " << Petya << ". " << endl;
	if (i == n)
	{
		if (Masha < Petya)
		{
			cout << "Petya - Masha = " << Petya - Masha << endl;
			return Petya - Masha;
		}
		else
		{
			cout << "Masha - Petya = " << Masha - Petya << endl;
			return Masha - Petya;
		}
	}
	return min(recursion(i + 1, n, Masha + massive[i], Petya, massive), recursion(i + 1, n, Masha, Petya + massive[i], massive));
}

int main()
{
	cout << "Enter count of cupes(1<=...<=32): ";
	cin >> n;
	long* mas = new long[n];
	for (int i = 0; i < n; i++)
	{
		cout << i << "Enter gramm for each cupe: ";
		cin >> mas[i];
	}

	int x = recursion(0, n, 0, 0, mas);
	cout << "Min delta between doses: " << x;
}