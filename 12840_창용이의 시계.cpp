#include<iostream>
using namespace std;

int nowtime[3];
int now = 0;
void convert()
{
	int tmp = now;
	nowtime[0] = tmp / 3600;
	tmp = tmp % 3600;
	nowtime[1] = tmp / 60;
	nowtime[2] = tmp % 60;
}

int main()
{
	int day = 60 * 60 * 24;
	int tc;
	scanf("%d %d %d", &nowtime[0], &nowtime[1], &nowtime[2]);
	now = nowtime[0] * 3600;
	now += nowtime[1] * 60;
	now += nowtime[2];
	int dir,mov;
	cin >> tc;
	while (tc--)
	{
		scanf("%d", &dir);
		switch (dir)
		{
		case 1:
			scanf("%d", &mov);
			now += mov;
			now %= day;
			break;
		case 2:
			scanf("%d", &mov);
			now -= mov;
			while (now < 0)
				now += day;
			break;
		case 3:
			convert();
			printf("%d %d %d\n", nowtime[0], nowtime[1], nowtime[2]);
			break;
		}
	}
}