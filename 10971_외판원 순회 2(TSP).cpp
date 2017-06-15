#include<iostream>
#include<deque>
using namespace std;

int arr[10][10];

bool check[10];
int min_cost = 987654321;
int N;
int n_chk = 0;
deque<int> q;

void dfs(int start, int cost, int _from)
{
	if (n_chk == N - 1)
	{
		if (arr[start][_from] != 0 && min_cost > cost + arr[start][_from])
		{
			min_cost = cost + arr[start][_from];
		}
		return;
	}
	n_chk++;
	check[start] = true;;
	q.push_back(start);
	for (int i = 0; i < N; i++)
	{
		if (arr[start][i]!=0 && !check[i])
		{
			dfs(i, cost + arr[start][i], _from);
		}
	}
	q.pop_back();
	check[start] = false;
	n_chk--;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		dfs(i, 0, i);
	}
	

	cout << min_cost << endl;
}