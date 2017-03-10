#include<iostream>
using namespace std;

int dp[32];

int main()
{
	int N;
	cin >> N;
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 9 + 2;
	for (int i = 6; i <= N; i += 2)
	{
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2)
		{
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[N] << endl;
}