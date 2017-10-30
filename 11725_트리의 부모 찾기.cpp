#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node
{
public:
	int parent;
	vector<int> v;
};

void dfs(node* v, int root, int from)
{
	v[root].parent = from;
	for (int i = 0; i < v[root].v.size(); ++i)
	{
		if (v[root].v[i] == from)
			continue;
		dfs(v, v[root].v[i], root);
	}
}

node v[100002];

int main()
{
	int n;
	cin >> n;
	//vector<node> v(n);

	int a, b;
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d %d", &a, &b);
		v[a - 1].v.push_back(b - 1);
		v[b - 1].v.push_back(a - 1);
	}

	dfs(v, 0, -1);

	for (int i = 1; i < n; ++i)
	{
		printf("%d\n", v[i].parent + 1);
		//cout << v[i].parent + 1 << endl;
	}
}