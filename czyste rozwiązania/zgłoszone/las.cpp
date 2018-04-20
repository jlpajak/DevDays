#include <cstdio>

using namespace std;

#define MAXN 1000005

int torty[MAXN];
int wybor[MAXN];

int n;

int policz(int w)
{
	if(wybor[w] == 0)
	{
		if(wybor[(w + n - 1) % n] == 1)
			return torty[w] / 2;
		return torty[w];
	}
	if(wybor[(w + 1) % n] == 0)
		return torty[(w + 1) % n] / 2;
	return torty[(w + 1) % n];
}

void popraw()
{
	for(int i = 0; i < n; i++)
	{
		int x = policz(i);
		wybor[i] ^= 1;
		int y = policz(i);
		if(x >= y)
			wybor[i] ^= 1;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", torty + i);
		torty[i] *= 2;
	}
	for(int i = 0; i < n; i++)
	{
		if(torty[i] < torty[(i + 1) % n])
			wybor[i] = 1;
		else
			wybor[i] = 0;
	}
	popraw();
	for(int i = 0; i < n; i++)
	{
		if(i)
			printf(" ");
		printf("%d", ((i + wybor[i]) % n) + 1);
	}
	printf("\n");
	return 0;
}
