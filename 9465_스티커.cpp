#include<iostream>
using namespace std;

int board[100002][2];
int dp[100002][2];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int DP(int n)
{
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = board[1][0];
	dp[1][1] = board[1][1];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + board[i][0];
		dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + board[i][1];
	}

	int max = dp[n][0];

	if (max < dp[n][1])
		max = dp[n][1];

	return max;

}
  
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> board[i][0];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> board[i][1];
		}

		cout << DP(n) << endl;
	}
}