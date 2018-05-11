#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 1000001

long long wynik[MAXN];
int n;
int karta;
vector<int> karty;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &karta);
		karty.push_back(karta);
	}

	sort(karty.begin(), karty.end());

	wynik[0] = karty[0];

	for(int i=1; i<n; i++) { wynik[i] = max((long long)karty[i] - wynik[i-1], wynik[i-1]); }

	printf("%lld\n", wynik[n-1]);
	
	return 0;
}
