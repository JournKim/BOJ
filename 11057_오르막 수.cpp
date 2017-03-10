#include<iostream>
using namespace std;

int dp[1024][10];

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += dp[N][i];
		result %= 10007;
	}

	cout << result << endl;
}