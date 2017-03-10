#include<iostream>
using namespace std;

#define mod 1000000000;

long long dp[256][256];

void DP()
{
	
	dp[0][0] = 1;

	for (int i = 0; i <= 200; i++)
	{
		for (int j = 1; j <= 200; j++)
		{
			////°£´Ù!
			for (int a = 0; a <= i; a++)
			{
				dp[i][j] += dp[i - a][j - 1];
				dp[i][j] %= mod;
			
			}
		}
	}
}

int main()
{
	DP();



	int N, K;
	cin >> N >> K;

	cout << dp[N][K] << endl;
}