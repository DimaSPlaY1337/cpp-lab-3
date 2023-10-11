#include <iostream>

using namespace std;

int recursion(int i, int n, int Masha, int Petya, long* massive)
{
	if (i == n)
	{
		return abs(Petya - Masha);
	}
	return min(recursion(i + 1, n, Masha + massive[i], Petya, massive), recursion(i + 1, n, Masha, Petya + massive[i], massive));
}

int main()
{
	int n, m;

	cout << "Enter count of cupes(1<=...<=32): ";
	cin >> n;

	long* mas = new long[n];
	for (int i = 0; i < n; i++)
	{
		cout << i << " Enter gramm for each cupe: ";
		cin >> mas[i];
	}

	int x = recursion(0, n, 0, 0, mas);
	cout << "Min delta between doses: " << x;
}