#include<cstdio>
#include<algorithm>
using namespace std;

#define REP(i,n) for (int i=0; i<(n); ++i)

#define MAX_N 1000000
#define MAX_S 100

int odl[MAX_N];
long long zas[MAX_S];
int pocz[MAX_N*2], ile[MAX_N*2];
int n, s;
long long suma;

int licz(long long d) {
	int s = 0;
	int k = n;
	long long z = suma;
	for (;;) {
		while (z > d) {
			z -= odl[s % n];
			++s;
		}
		if (pocz[s] <= k % n)
			return ile[s] + 1;
		ile[k] = ile[s] + 1;
		pocz[k] = pocz[s];
		z += odl[k % n];
		++k;
	}
}

int main() {
	scanf("%d%d", &n, &s);
	REP(i,n) scanf("%d", &odl[i]);
	REP(i,s) scanf("%lld", &zas[i]);
	int max_odl = 0;
	REP(i,n) max_odl = max(max_odl, odl[i]);
	suma = 0;
	REP(i,n) suma += odl[i];
	REP(i,n) pocz[i] = i;
	REP(i,n) ile[i] = 0;
	REP(i,s) {
		if (zas[i] < max_odl) {
			printf("NIE\n");
		} else {
			int odp = licz(zas[i]);
			printf("%d\n", odp);
		}
	}
}