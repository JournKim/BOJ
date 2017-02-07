#include<iostream>
using namespace std;


int min(int a, int b, int c)
{
	int ret = a;
	if (ret > b)
		ret = b;
	if (ret > c)
		ret = c;
	return ret;
}

int arr[1000003] = { 0, };

void DP(int n)
{
	// dp ¾øÀ¸¸é
	int a, b, c;
	a = b = c = 99999999;
	
	if (n % 3 == 0)
	{
		a = arr[n/3];
	}
		
	if (n % 2 == 0)
		b = arr[n/2];
	c = arr[n - 1];

	arr[n] = min(a, b, c) + 1;

}

int main()
{
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	int N;
	cin >> N;

	for (int i = 5; i <= N; i++)
		DP(i);

	cout << arr[N] << endl;
}