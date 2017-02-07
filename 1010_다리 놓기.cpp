#include<iostream>
using namespace std;

long long arr[32][32];

int main()
{
	// arr[i][j] : 왼쪽에 i개 있을 때, 가장 아래쪽 다리가 오른쪽 j번째 다리에 연결되는 경우의 수.
	for (int i = 1; i <= 30;i++)
		arr[1][i] = 1; // 왼쪽에 1개 있으면 전부 1가지씩.

	
	for (int i = 2; i <= 30; i++)
	{
		arr[i][i] = arr[i - 1][i-1];
		for (int j = i+1; j <= 30; j++)
		{
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int result = 0;
		for (int i = 1; i <= M; i++)
		{
			result += arr[N][i];
		}
		cout << result << endl;
	}
}