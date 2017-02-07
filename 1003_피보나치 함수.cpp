#include<iostream>

using namespace std;

int arr[41][2];

void fib(int n)
{
	arr[n][0] = arr[n - 1][0] + arr[n - 2][0];
	arr[n][1] = arr[n - 1][1] + arr[n - 2][1];
}

int main()
{
	arr[0][0] = 1;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1;


	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 2; i <= n; i++)
			fib(i);
		cout << arr[n][0] << " " << arr[n][1] << endl;
	}
}