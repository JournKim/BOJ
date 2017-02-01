#include<iostream>
using namespace std;

int main()
{
	int result = 0;
	char tmp;
	char hexNum[8];
	
	cin >> hexNum;

	for (int i = 0; hexNum[i] != '\0'; i++)
	{
		result *= 16;
		tmp = hexNum[i];
		if (tmp >= '0' && tmp <= '9')
			result += (tmp - '0');
		else
			result += (tmp - 'A' + 10);

	}

	cout << result << endl;
}