#include <cstdio>
using namespace std;

#define MAXN 1000001

int n;
int przelozony[MAXN], pensja[MAXN];
int znane[MAXN];
int ile_podwladnych[MAXN];
int bezposredni_podwladni[MAXN];
int jedyny_podwladny[MAXN];
int hierarchia[MAXN];
int poczatek = 0, koniec = 0;

void znane_pensje() {
	for (int i = 1; i < n; i++)
		if (pensja[i])
			znane[pensja[i]] = i;
		else if (!jedyny_podwladny[przelozony[i]])
			jedyny_podwladny[przelozony[i]] = i;
		else jedyny_podwladny[przelozony[i]] = -1;
}

void struktura_zatrudnienia() {
	for (int i = 1; i < n; i++)
		bezposredni_podwladni[i] = 0;
	for (int i = 1; i < n; i++)
		++bezposredni_podwladni[przelozony[i]];
	for (int i = 1; i < n; i++)
		if (bezposredni_podwladni[i] == 0)
			hierarchia[koniec++] = i;
	while (poczatek < koniec) {
		int pracownik = hierarchia[poczatek++];
		int zwierzchnik = przelozony[pracownik];
		if (pensja[pracownik] == 0) {
			if (!--bezposredni_podwladni[zwierzchnik]) hierarchia[koniec++] = zwierzchnik;
			ile_podwladnych[zwierzchnik] += ile_podwladnych[pracownik] + 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", przelozony + i, pensja + i);
		if (przelozony[i] == i) pensja[i] = n;
		if (pensja[i]) przelozony[i] = n+1;
	}
	++n;
	przelozony[n] = n;
	pensja[n] = n;
	znane_pensje();
	struktura_zatrudnienia();
	int i = 1;
	int niewykorzystane_pensje = 0, mozliwosci = 0;
	while (i < n) {
		while (i < n && znane[i] == 0) { i++; niewykorzystane_pensje++; mozliwosci++; }
		while (i < n && znane[i] != 0) {
			int pracownik = znane[i], l = i;
			niewykorzystane_pensje -= ile_podwladnych[pracownik];
			if (niewykorzystane_pensje == 0) {
				while (mozliwosci-- && jedyny_podwladny[pracownik] > 0) {
					while (znane[l]) l--;
					pracownik = jedyny_podwladny[pracownik];
					pensja[pracownik] = l;
					znane[l] = pracownik;
				}
				mozliwosci = 0;
			}
			if (ile_podwladnych[pracownik] != 0)
				mozliwosci = 0;
			++i;
		}
	}
	for (int i = 1; i < n; i++)
		printf("%d\n", pensja[i]);
	return 0;
}
