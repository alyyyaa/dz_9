//Дано целое число X и текстовый файл с именем FileName. В файле записан набор целых чисел, расположенных в невозрастающем порядке. С помощью метода 
//бинарного поиска определить индекс самого левого вхождения числа Х в исходный набор. Чисел в исходном наборе не более 200.
#include <iostream>
#include <fstream>
using namespace std;

int m[200];

void main()
{
	string fileName;
	cin >> fileName;
	fstream f;
	f.open(fileName, ios::in);

	int x;
	cin >> x;

	int k = 0;
	while (!f.eof())
	{
		f >> m[k];
		k++;
	}

	int l = 0, r = k, n;


	while (l < r)
	{
		n = (l + r) / 2;

		if (m[n] > x)
			l = n + 1;
		else r = n;
	}


	if (m[n] == x) cout << n;
	else
		if (m[n + 1] == x) cout << n + 1;
		else
			cout << -1;
}