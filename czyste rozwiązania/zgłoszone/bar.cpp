#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000 * 1000;
int n, wynik, mins;
int sumy[N + 1], nxt[N + 1], peak[N + 1];
char owoc[N];

void oblicz_sumy() {
	for(int i = 1; i <= n; i++) {
		sumy[i] = sumy[i - 1] + (owoc[i - 1] == 'p' ? 1 : -1);
		mins = min(mins, sumy[i]);
	}
}

void oblicz_nxt() {
	int last[N + 1];
	for(int i = 0; i <= n; i++) last[i] = -1;
	for(int i = n; i >= 0; i--) {
		nxt[i] = last[sumy[i] - mins];
		last[sumy[i] - mins] = i;
	}
}

void oblicz_wynik() {
	int cpeak = n;
	for(int i = 0; i <= n; i++) peak[i] = i;
	for(int i = n - 1; i >= 0; i--) if(owoc[i] == 'p') {
		if(nxt[i] != -1 && sumy[peak[nxt[i]]] >= sumy[cpeak]) {
			cpeak = peak[nxt[i]];
		}
		peak[i] = cpeak;
		wynik = max(wynik, cpeak - i);
	} else {
		cpeak = i;
	}
}

int main() {
	scanf("%d %s", &n, owoc);
	oblicz_sumy();
	oblicz_nxt();
	oblicz_wynik();
	printf("%d\n", wynik);
	return 0;
}
