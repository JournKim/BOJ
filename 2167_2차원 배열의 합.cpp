#include<iostream>
using namespace std;

int arr[300][300];

int main()
{
	int N, M;
	cin >> N >> M;
	// input arr
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (j > 0)
				arr[i][j] += arr[i][j - 1];
			if (i > 0)
				arr[i][j] += arr[i - 1][j];
			if (i > 0 && j > 0)
			{
				arr[i][j] -= arr[i - 1][j - 1];
			}
		}
	}
	
	int K, i, j, x, y;
	cin >> K;
	while (K--) {
		cin >> i >> j >> x >> y;
		i--;
		j--;
		x--;
		y--;
		
		int sum = arr[x][y];
		//cout << "1 : " << sum << endl;
		if (i > 0)
			sum -= arr[i - 1][y];
		//cout << "2 :" << sum << endl;

		if (j > 0)
			sum -= arr[x][j - 1];
		//cout << "3 : " << sum << endl;
		if (i > 0 && j > 0)
		{
			sum += arr[i - 1][j - 1];
		}
		cout << sum << endl;
	}
	
}