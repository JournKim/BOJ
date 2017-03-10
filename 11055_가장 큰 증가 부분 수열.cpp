#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;
vector<int> dp;

int main()
{
	int N;
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
		dp.push_back(tmp);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && dp[i] < dp[j] + a[i])
			{
				dp[i] = dp[j] + a[i];
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());

	cout << ans << endl;
}