#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int dlugosc_rury;
int ilosc_krazkow;
int otwor;
int krazek;

int main()
{
	scanf("%d %d", &dlugosc_rury, &ilosc_krazkow);
	vector<int> rura;

	scanf("%d", &otwor);
	rura.push_back(otwor);
	for (int i = 1; i < dlugosc_rury; i++) {
		scanf("%d", &otwor);
		rura.push_back(min(otwor, rura[i-1]));
	}

	int glebokosc = dlugosc_rury;
	for (int i = 0; i < ilosc_krazkow; i++) {
		scanf("%d", &krazek);
		while (glebokosc>0 && rura[glebokosc-1]<krazek) glebokosc--;
		glebokosc--;
	}

	printf("%d\n", max(0, glebokosc + 1));
	return 0;
}
