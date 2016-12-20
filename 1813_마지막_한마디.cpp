#include<iostream>
using namespace std;

int table[100002] = { 0, };


int main()
{
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		table[a]++;
	}
	int max = -1;
	for (int i = 0; i <= n; i++)
	{
		if (i == table[i])
		{
			max = i;
		}
	}
	cout << max << endl;
}