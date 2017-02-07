#include<iostream>
using namespace std;

//#define min2(a,b) a>b?b:a

int min2(int a, int b)
{
	return a > b ? b : a;
}

int cost[1024][3];

int arr[1024][3];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	arr[0][0] = cost[0][0];
	arr[0][1] = cost[0][1];
	arr[0][2] = cost[0][2];
	for (int i = 1; i < N; i++)
	{
		arr[i][0] = min2(arr[i - 1][1], arr[i - 1][2]) + cost[i][0];
		arr[i][1] = min2(arr[i - 1][0], arr[i - 1][2]) + cost[i][1];
		arr[i][2] = min2(arr[i - 1][0], arr[i - 1][1]) + cost[i][2];
	}

	cout << min2(min2(arr[N-1][0], arr[N-1][1]), arr[N-1][2]) << endl;
}