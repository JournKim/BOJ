#include<iostream>
using namespace std;
int arr[500][500];
int main()
{
	int n;
	cin >> n;
	cin >> arr[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
		for (int j = 0; j <= i; j++)
		{
			int left, right;
			left = right = 0;
			// 가장 왼쪽(j==0)일 때는 left가 없음.
			if (j > 0)
			{
				left = arr[i - 1][j - 1];
			}
			// 가장 오른쪽(j == i)일 때는 right가 없음.
			if (j < i)
			{
				right = arr[i - 1][j];
			}

			// 위층의 왼쪽,오른쪽 중 큰 수에 더한다.
			if (left > right)
			{
				arr[i][j] = left + arr[i][j];
			}
			else
			{
				arr[i][j] = right + arr[i][j];
			}
		}
	}
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[n - 1][i] > max)
			max = arr[n - 1][i];
	}
	cout << max << endl;
}