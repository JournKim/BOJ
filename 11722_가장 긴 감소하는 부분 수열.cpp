#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;
vector<int> dp;

int main()
{
	a.assign(1024, 0);
	dp.assign(1024, 1);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] < a[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());

	cout << ans << endl;

}