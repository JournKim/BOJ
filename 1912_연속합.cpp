#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[100002];
vector<int> dp;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		dp.push_back(a[i]);
	}

	int sum=0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (dp[i] < sum)
			dp[i] = sum;

		if (sum < 0)
			sum = 0;
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;

}