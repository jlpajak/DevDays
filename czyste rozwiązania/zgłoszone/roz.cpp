#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 87;

long long fib[MAXN];
int n;
long long Q;
long long q;
int wynik;

int main() {
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < MAXN; i++) { 
		fib[i] = fib[i-1]+fib[i-2]; 
	}

	scanf("%d", &n);
	while (n--) {

		scanf("%lld", &Q);
		wynik = 0;
		q = Q;

		while (Q != 0) {
			for (int i = 0; i < MAXN; i++) { 
				q = min(q, abs(Q-fib[i])); 
			}
			Q = q;
			wynik++;
		}

		printf("%d\n", wynik);
	}

	return 0;
}
