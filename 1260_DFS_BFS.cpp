#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


vector<int> arr[1024];

bool check[1024];
vector<int> dfs;
void DFS(int v)
{
	check[v] = 1;
	dfs.push_back(v);

	for (int i = 0; i < arr[v].size(); i++)
	{
		if (!check[arr[v][i]])
			DFS(arr[v][i]);
	}
}

bool check2[1024];
queue<int> q;
vector<int> bfs;
void BFS(int v)
{
	check2[v] = true;
	q.push(v);

	while (!q.empty())
	{
		int front = q.front();
		for (int i = 0; i < arr[front].size(); i++)
		{
			if (!check2[arr[front][i]])
			{
				check2[arr[front][i]] = true;
				q.push(arr[front][i]);
			}
		}
		bfs.push_back(front);
		q.pop();
	}
}
int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	DFS(V);
	BFS(V);
	int i;
	for (i = 0; i < dfs.size()-1; i++)
	{
		printf("%d ", dfs[i]);
	}
	printf("%d\n", dfs[i]);

	for (i = 0; i < bfs.size()-1; i++)
	{
		printf("%d ", bfs[i]);
	}
	printf("%d\n", bfs[i]);
}