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
			// ���� ����(j==0)�� ���� left�� ����.
			if (j > 0)
			{
				left = arr[i - 1][j - 1];
			}
			// ���� ������(j == i)�� ���� right�� ����.
			if (j < i)
			{
				right = arr[i - 1][j];
			}

			// ������ ����,������ �� ū ���� ���Ѵ�.
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