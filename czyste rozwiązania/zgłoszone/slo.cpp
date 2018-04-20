#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000000
#define MAXN 1000000

int wagi[MAXN];
int poczatek[MAXN];
int koniec[MAXN];
bool przestawione[MAXN];
int minwag = INF;
int mincyklu;
int n;
int pozycja;
long long suma_cyklu;
int dlugosc_cyklu;

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &wagi[i]);
		minwag = min(minwag, wagi[i]);
	}
	for (int i=0; i<n; i++)
	{
		scanf("%d", &poczatek[i]);
		--poczatek[i];
	}
	for (int i=0; i<n; i++)
	{
		scanf("%d", &pozycja);
		--pozycja;
		koniec[pozycja] = poczatek[i];
	}
	long long wynik = 0;
	for (int slon=0; slon<n; slon++)
		if (!przestawione[slon])
		{
			suma_cyklu = 0;
			int obecna_pozycja = slon;
			dlugosc_cyklu = 0;
			mincyklu = INF;
			for (;;)
			{
				mincyklu = min(mincyklu, wagi[obecna_pozycja]);
				suma_cyklu += wagi[obecna_pozycja];
				obecna_pozycja = koniec[obecna_pozycja];
				przestawione[obecna_pozycja] = true;
				++dlugosc_cyklu;
				if (obecna_pozycja==slon)
					break;
			}
			wynik += min(suma_cyklu+(dlugosc_cyklu-2)*mincyklu, suma_cyklu+mincyklu+(dlugosc_cyklu+1)*minwag);
		}
		printf("%lld\n", wynik);
}
