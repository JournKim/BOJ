#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

#define mod 1000000

using namespace std;

char arr[5010];
int dp[5010];

int main()
{
	cin >> arr;
	
	int len = strlen(arr);
	
	dp[0] = 1;
	dp[1] = 1;
	
	if (arr[0] == '0')
	{
		cout << "0" << endl;
		return 0;
	}

	for (int i = 2; i <= len; i++)
	{
		int tmp = (arr[i - 2] - '0') * 10 + arr[i-1] - '0';
		if (tmp == 10 || tmp == 20)
		{
			dp[i] = dp[i - 2] % mod;
		}
		else if (tmp > 10 && tmp <= 26)
		{
			dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		}
		else
		{
			dp[i] = dp[i - 1] % mod;
		}
		//printf("tmp : %d , dp[%d] : %d\n", tmp, i, dp[i]);
	}

	cout << (dp[len]) % mod << endl;
}