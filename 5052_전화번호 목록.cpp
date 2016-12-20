#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


void phonebook()
{
	string book[10000];
	int length[10000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> book[i];
		//length[i] = book[i].length();
	}
	/*
	int tLen;
	string tStr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (length[j] > length[j + 1])
			{
				tLen = length[j];
				length[j] = length[j + 1];
				length[j + 1] = tLen;
				tStr = book[j];
				book[j] = book[j + 1];
				book[j + 1] = tStr;
			}
		}
	}
	cout << "!!!!!" << endl;
	for (int i = 0; i < n; i++) {
		cout << book[i] << endl;
	}
	*/
	sort(book, book + n);

	for (int i = 0; i < n-1; i++)
	{
		if (book[i].length() <= book[i + 1].length()) {
			//cout << book[i] << " , " << book[i + 1].substr(0,book[i].length()) << endl;
			//cout << book[i].compare(book[i + 1].substr(0,book[i].length())) << endl;
			if (book[i].compare(book[i + 1].substr(0,book[i].length())) == 0)
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		phonebook();
	}
}