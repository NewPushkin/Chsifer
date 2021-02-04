#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int main()
{
    setlocale(LC_CTYPE, "Russian");
	string s, s1;
	int n, old, gold, rot;
	cout << "Введите исходник: ";
	getline(cin, s);
	cout << "Смещение: ";
	cin >> rot;
	n = s.size();
	char* A = new char[n + 1];
	strcpy(A, s.c_str());
	for (int i = 0; i < n; i++)
	{
		old = int(A[i]);
		if (old > 64 && old < 91)
		{
			rot -= (rot / 26) * 26;
			gold = old + rot;
			if (gold > 90) gold -= 26;
			A[i] = char(gold);
		}
		else if (old > 96 && old < 123)
		{
			rot -= (rot / 26) * 26;
			gold = old + rot;
			if (gold > 122) gold -= 26;
			A[i] = char(gold);
		}
		else if (old > -65 && old < -32)
		{
			rot -= (rot / 32) * 32;
			gold = old + rot;
			if (gold > -97) gold += 32;
			A[i] = char(gold - 16);
		}
		else if (old > -33 && old < 0)
		{
			rot -= (rot / 32) * 32;
			gold = old + rot;
			if (gold > -1) gold += 32;
			A[i] = char(gold + 16);
		}
	}
	cout << "Зашифрованное: ";
	for (int i = 0; i < n; i++) cout << A[i];
}