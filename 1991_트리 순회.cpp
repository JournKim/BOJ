#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class node
{
public:
	char name;
	char left;
	char right;

	bool operator<(node& a)
	{
		return name < a.name;
	}
};

void preorder(vector<node>& v, int i)
{
	//printf("\t%c", v[i].name);
	//printf("\t %c %c %c\n", v[i].name, v[i].left, v[i].right);
	printf("%c", v[i].name);
	
	if (v[i].left != '.')
		preorder(v, v[i].left - 'A');

	
	if (v[i].right != '.')
		preorder(v, v[i].right - 'A');
}

void inorder(vector<node>& v, int i)
{
	//printf("\t%c", v[i].name);
	//printf("\t %c %c %c\n", v[i].name, v[i].left, v[i].right);
	

	if (v[i].left != '.')
		inorder(v, v[i].left - 'A');

	printf("%c", v[i].name);

	if (v[i].right != '.')
		inorder(v, v[i].right - 'A');
}

void postorder(vector<node>& v, int i)
{
	//printf("\t%c", v[i].name);
	//printf("\t %c %c %c\n", v[i].name, v[i].left, v[i].right);


	if (v[i].left != '.')
		postorder(v, v[i].left - 'A');

	if (v[i].right != '.')
		postorder(v, v[i].right - 'A');

	printf("%c", v[i].name);
}

int main()
{
	int n;
	cin >> n;
	vector<node> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].name >> v[i].left >> v[i].right;
		//printf("\t %c %c %c\n", v[i].name, v[i].left, v[i].right);
	}
	sort(v.begin(), v.end());
	
	preorder(v, 0);
	printf("\n");

	inorder(v, 0);
	printf("\n");

	postorder(v, 0);
	printf("\n");

}