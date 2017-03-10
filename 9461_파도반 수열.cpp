#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long a[128];

void dp()
{
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	a[6] = 3;
	a[7] = 4;
	a[8] = 5;
	a[9] = 7;
	a[10] = 9;
	for (int i = 11; i < 103; i++)
	{
		a[i] = a[i - 1] + a[i - 5];
	}
}

int main()
{
	dp();

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;

		cout << a[N] << endl;
	}
}