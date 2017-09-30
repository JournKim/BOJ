#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int arr[1024];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	arr[n] = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		arr[i + 1] += arr[i];
	}
	cout << sum << endl;
}
