#include<iostream>
#include<algorithm>
using namespace std;

int man[1001];

int main()
{
	int n;
	cin >> n;
	cin >> man[0];
	int max=0;
	if (n == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> man[i];
		if (man[i] > max)
			max = man[i];
	}

	sort(man + 1, man + n);
	int mindControl = 0;
	while (man[n - 1] >= man[0])
	{
		man[0]++;
		man[n - 1]--;
		mindControl++;
		sort(man + 1, man + n);
	}
	cout << mindControl << endl;
	


}