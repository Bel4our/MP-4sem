#include <iostream>
#include <random>

using namespace std;

string generateRandomString(int size)
{
	string str;
	for (int i = 0; i < size; i++)
	{
		str += rand() % 26 + 'a';
	}
	return str;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	string str1 = generateRandomString(300);
	string str2 = generateRandomString(200);

	cout << "Первая строка: " << endl;
	cout << str1 << endl;

	cout << endl << "Вторая строка: " << endl;
	cout << str2 << endl;

	return 0;
}