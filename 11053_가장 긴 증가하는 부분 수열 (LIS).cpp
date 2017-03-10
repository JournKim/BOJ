#include<iostream>
using namespace std;

int a[1024];


int main()
{
	int dp[1024];

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	int max = 1;
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i])
			max = dp[i];
	}

	cout << max << endl;
}