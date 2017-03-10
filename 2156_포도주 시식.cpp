#include<iostream>
using namespace std;

int wine[10002];
long long dp[10002][3];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> wine[i];
	}

	dp[0][0] = 0;
	dp[0][1] = wine[0];
	dp[0][2] = wine[0];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i-1][0]);
		dp[i][1] = dp[i - 1][0] + wine[i];
		dp[i][2] = dp[i - 1][1] + wine[i];
	}

	long long  result = max(dp[n - 1][0], dp[n - 1][1]);
	result = max(result, dp[n - 1][2]);

	cout << result << endl;
}