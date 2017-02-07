#include<iostream>
using namespace std;

long long arr[100][2];

int main()
{
	arr[1][0] = 0;
	arr[1][1] = 1;
	arr[2][0] = 1;
	arr[2][1] = 0;

	int N;
	cin >> N;

	for (int i = 3; i <= N; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}


	cout << arr[N][0] + arr[N][1] << endl;
}