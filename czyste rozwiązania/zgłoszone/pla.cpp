#include <cstdio>

using namespace std;

const int MAXN=250001;

int kolejka[MAXN];
int n;
int wynik;
int dump;
int wysokosc;
int dlugosc;

int main(){
	scanf("%d\n",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d\n",&dump,&wysokosc);
		while((dlugosc > 0) && (kolejka[dlugosc - 1] > wysokosc)) { dlugosc --;}
		if ((dlugosc == 0) || (kolejka[dlugosc-1] < wysokosc)) {
			wynik++;
			kolejka[dlugosc++]=wysokosc;
		}
	}
	printf("%d\n",wynik);
	return 0;
}
