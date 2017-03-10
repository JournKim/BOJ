#include<iostream>
using namespace std;

int dp[1024][2];
int dp2[1024][2];
int arr[1024];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i][0] < dp[j][0] + 1)
				dp[i][0] = dp[j][0] + 1;
			
			//if (arr[i] < arr[j] && dp[i][1] < dp[j][1] + 1)
			//	dp[i][1] = dp[j][1] +1;
		}
	}

	for (int i = N; i >= 1; i--)
	{
		for (int j = N; j > i; j--)
		{
			if (arr[i] > arr[j] && dp2[i][0] < dp2[j][0] + 1)
				dp2[i][0] = dp2[j][0] + 1;

			//if (arr[i] < arr[j] && dp2[i][1] < dp2[j][1] + 1)
			//	dp2[i][1] = dp2[j][1] + 1;
		}
	}

	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (max < dp[i][0] + dp2[i][0])
			max = dp[i][0] + dp2[i][0];
	}

	cout<<max<<endl;

}