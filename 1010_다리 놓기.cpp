#include<iostream>
using namespace std;

long long arr[32][32];

int main()
{
	// arr[i][j] : ���ʿ� i�� ���� ��, ���� �Ʒ��� �ٸ��� ������ j��° �ٸ��� ����Ǵ� ����� ��.
	for (int i = 1; i <= 30;i++)
		arr[1][i] = 1; // ���ʿ� 1�� ������ ���� 1������.

	
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