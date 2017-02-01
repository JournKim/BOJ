#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int m;
	int max = 0;
	int min = 9999;

	for (int i = 0; i<n; i++)
	{
		cin >> m;
		if (m > max)
			max = m;
		if (m < min)
			min = m;
	}

	cout << min * max << endl;
}