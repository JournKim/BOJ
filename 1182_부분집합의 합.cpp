#include<iostream>
#include<vector>

using namespace std;

int arr[22];
vector<int> v;

int num = 0;
void run(int round, int n, int sum, int S)
{
	if (round == n)
	{
		
		if (sum == S && !v.empty())
		{
			num++;
		}
		
		return;
	}

	//�ִ´�
	v.push_back(arr[round]);
	run(round + 1, n, sum + arr[round], S);
	v.pop_back();
	//�ȳִ´�
	
	run(round + 1, n, sum, S);
}

int main()
{
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	run(0, N, 0, S);

	cout << num << endl;
}