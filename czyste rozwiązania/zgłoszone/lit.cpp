#include <cstdio>
#include <vector>

using namespace std;

#define ROZMIAR 20
#define MAXN 1000005

int drzewo[1 << (ROZMIAR+1)];
long long wynik;
int n;
int pozycja;
vector<int> tab[255];
char nazwisko1[MAXN];
char nazwisko2[MAXN];

void wstaw(int pozycja) {
	int v = (1 << ROZMIAR) + pozycja;
	drzewo[v] = 1;
	while (v != 1){
		v /= 2;
		drzewo[v]++;
	}
}

int ileprzed(int pozycja){
	int poczatek = (1 << ROZMIAR);
	int v = (1 << ROZMIAR) + pozycja;

	int wynik_zapytania = drzewo[poczatek];
	if (poczatek != v)
		wynik_zapytania += drzewo[v];

	while (poczatek / 2 != v / 2) {
		if (poczatek % 2 == 0) wynik_zapytania += drzewo[poczatek + 1];
		if (v % 2 == 1) wynik_zapytania += drzewo[v - 1];
		poczatek /= 2; v /= 2;
	}
	return wynik_zapytania;
}

int main(){
	scanf("%d", &n);
	scanf("%s", nazwisko1);
	for (int i = n - 1; i >= 0; --i)
		tab[int(nazwisko1[i])].push_back(i);
	scanf("%s", nazwisko2);

	for (int i = 0; i < n; ++i){
		pozycja = tab[int(nazwisko2[i])].back();
		tab[int(nazwisko2[i])].pop_back();
		wynik += pozycja - ileprzed(pozycja);
		wstaw(pozycja);
	}
	printf("%lld\n", wynik);

	return 0;
}
