#include<iostream>
#include<string>

using namespace std;

int arr[26];

int main()
{
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); ++i)
	{
		++arr[input[i] - 'a'];
	}

	for (int i = 0; i < 26; ++i)
	{
		printf("%d ", arr[i]);
	}
}