#include<iostream>
using namespace std;

int price[10002];

int income[1024];

int DP(int n)
{
	int max = 0;
	int tmp;
	for (int i = 0; i < n/2 + 1; i++)
	{
		tmp = income[i] + income[n - i];
		if (tmp > max)
			max = tmp;
	}
	if (max < price[n])
		max = price[n];

	return max;
}


int main()
{


	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> price[i];
	}

	income[0] = 0;
	income[1] = price[1];

	for (int i = 2; i <= N; i++)
	{
		income[i] = DP(i);
	}

	cout << income[N] << endl;

}