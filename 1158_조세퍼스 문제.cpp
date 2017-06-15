#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}
	int out = 0;
	cout << "<";
	int outMember;
	while (!v.empty())
	{
		out = (out+M-1)%v.size();
		outMember = v[out];
		cout << outMember;
		v.erase(v.begin() + out);
		if (!v.empty())
			cout << ", ";
	}
	cout << ">";
	
}