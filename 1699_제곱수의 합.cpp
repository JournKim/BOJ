#include<iostream>
#include<vector>
using namespace std;

int dp[100002];
vector<int> sq;

int main()
{
	sq.push_back(0);
	

	int N;
	cin >> N;

	for (int i = 1; true; i++)
	{
		sq.push_back(i*i);
		if (sq.back() > N)
		{
			sq.pop_back();
			break;
		}
	}

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		int min = dp[i - 1] + 1;
		for (int j = 1; j<=sq.size(); j++)
		{
			if (i - sq[j] < 0)
				break;
			if (min > dp[i - sq[j]] + 1)
				min = dp[i - sq[j]] + 1;
		}
		dp[i] = min;
	}

	cout << dp[N] << endl;
}