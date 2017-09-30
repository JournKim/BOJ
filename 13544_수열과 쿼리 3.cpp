#include<cstdio>

using namespace std;

int arr[100002];

int main()
{
	int N,M;
	int last_ans = 0;

	int a, b, c;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &M);

	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		a = a^last_ans;
		b = b^last_ans;
		c = c^last_ans;
		last_ans = 0;
		for (int i = a - 1; i < b; ++i)
		{
			if (arr[i] > c)
				++last_ans;
		}
		printf("%d\n", last_ans);
	}
}