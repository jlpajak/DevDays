#include <cstdio>

const int MAX_N = 1001;

int u, n;
int kam[MAX_N];

int main()
{
	scanf("%d", &u);
	while (u--)
	{
		scanf("%d", &n);
		kam[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", kam + i);
		int XOR = 0;
		for (int i = n; i >= 1; i--)
			if ((n - i) % 2 == 0)
				XOR ^= kam[i] - kam[i - 1];
		puts(XOR ? "TAK" : "NIE");
	}
	return 0;
}
