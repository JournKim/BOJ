#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
class board {
public:
	vector<vector<int>> b;
	int size;

	int run(vector<vector<int>> v, int round)
	{
		int max = 0;

		if (round == 5)
		{
			/*for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					cout << v[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
*/
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (max < v[i][j])
						max = v[i][j];
				}
			}

			return max;
		}
		
		//cout << "up ";
		int tmp = run(up(v), round + 1);
		if (tmp > max)
			max = tmp;
		//cout << "down ";
		tmp = run(down(v), round + 1);
		if (tmp > max)
			max = tmp;
		//cout << "left ";
		tmp = run(left(v), round + 1);
		if (tmp > max)
			max = tmp;
		//cout << "right ";
		tmp = run(right(v), round + 1);
		if (tmp > max)
			max = tmp;

		

		return max;
	}

	//constructor
	board(int n)
	{
		size = n;
		b.assign(n, vector<int>(n, 0));
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> b[i][j];
			}
		}
	}

	vector<vector<int>> up(vector<vector<int>> v)
	{
		deque<int> q;
		stack<int> s;
		vector<vector<int>> result;
		result.assign(size, vector<int>(size, 0));
		for (int col = 0; col < size; col++)
		{
			for (int i = 0; i < size; i++)
			{
				int tmp = v[i][col];
				if (tmp == 0)
					continue;
				if (s.empty())
					s.push(tmp);
				else
				{
					if (s.top() == tmp)
					{
						s.pop();
						tmp *= 2;

						q.push_back(tmp);

					}
					else
					{
						q.push_back(s.top());
						s.pop();
						s.push(tmp);
					}

				}
			}
			if (!s.empty())
			{
				q.push_back(s.top());
				s.pop();
			}

			for (int i = 0; !q.empty(); i++)
			{
				result[i][col] = q.front();
				q.pop_front();
			}
		}
		return result;
	}

	vector<vector<int>> down(vector<vector<int>> v)
	{
		deque<int> q;
		stack<int> s;
		vector<vector<int>> result;
		result.assign(size, vector<int>(size, 0));
		for (int col = 0; col < size; col++)
		{
			for (int i = size-1; i >=0; i--)
			{
				int tmp = v[i][col];
				if (tmp == 0)
					continue;
				if (s.empty())
					s.push(tmp);
				else
				{
					if (s.top() == tmp)
					{
						s.pop();
						tmp *= 2;

						q.push_back(tmp);

					}
					else
					{
						q.push_back(s.top());
						s.pop();
						s.push(tmp);
					}

				}
			}
			if (!s.empty())
			{
				q.push_back(s.top());
				s.pop();
			}

			for (int i = size-1; !q.empty(); i--)
			{
				result[i][col] = q.front();
				q.pop_front();
			}
		}
		return result;
	}

	vector<vector<int>> left(vector<vector<int>> v)
	{
		deque<int> q;
		stack<int> s;
		vector<vector<int>> result;
		result.assign(size, vector<int>(size, 0));
		for (int row = 0; row < v.size(); row++)
		{
			for (int i = 0; i < size; i++)
			{
				int tmp = v[row][i];
				if (tmp == 0)
					continue;
				if (s.empty())
					s.push(tmp);
				else
				{
					if (s.top() == tmp)
					{
						s.pop();
						tmp *= 2;
						
						q.push_back(tmp);
						
					}
					else
					{
						q.push_back(s.top());
						s.pop();
						s.push(tmp);
					}
						
				}
			}
			if (!s.empty())
			{
				q.push_back(s.top());
				s.pop();
			}

			for (int i = 0; !q.empty(); i++)
			{
				result[row][i] = q.front();
				q.pop_front();
			}
		}
		return result;
	}

	vector<vector<int>> right(vector<vector<int>> v)
	{
		deque<int> q;
		stack<int> s;
		vector<vector<int>> result;
		result.assign(size, vector<int>(size, 0));
		for (int row = 0; row < v.size(); row++)
		{
			for (int i = size-1; i >=0; i--)
			{
				int tmp = v[row][i];
				if (tmp == 0)
					continue;
				if (s.empty())
					s.push(tmp);
				else
				{
					if (s.top() == tmp)
					{
						s.pop();
						tmp *= 2;

						q.push_back(tmp);

					}
					else
					{
						q.push_back(s.top());
						s.pop();
						s.push(tmp);
					}

				}
			}
			if (!s.empty())
			{
				q.push_back(s.top());
				s.pop();
			}

			for (int i = size-1; !q.empty(); i--)
			{
				result[row][i] = q.front();
				q.pop_front();
			}
		}
		return result;
	}
};
int main()
{
	int N;
	cin >> N;

	board b(N);

	cout << b.run(b.b, 0) << endl;
}