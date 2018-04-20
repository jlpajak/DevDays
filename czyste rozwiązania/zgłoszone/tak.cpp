#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> taksowki;

int n;
long long trasa;
long long baza;
long long taxi;
long long pozycja = 0;
long long droga;
int wynik = 0;

int main() {
	scanf("%lld %lld %d", &trasa,&baza,&n);
	for(int i=0; i<n; i++) {
		scanf("%lld", &taxi);
		taksowki.push_back(taxi);
	}
	sort(taksowki.begin(), taksowki.end());

	int k = n-1;
	while(k > 0 && taksowki[k-1] >= trasa-baza) --k;
	long long ostatnia = taksowki[k];
	taksowki.erase(taksowki.begin()+k);
	n--;

	for(int i=0; i<n; i++)
	{
		droga = baza - pozycja + trasa - pozycja;
		if(droga <= ostatnia) {
			pozycja = trasa;
			wynik=i+1;
			break;
		}
		taxi = taksowki.back();
		taksowki.pop_back();
		if(baza-pozycja > taxi) {break;}
		pozycja += (taxi - (baza-pozycja));
		if(pozycja >= trasa) {wynik=i+1; break;}
		if(pozycja > baza) {pozycja = baza;}
	}
	if (pozycja < trasa) {
		droga = baza - pozycja + trasa - pozycja;
		if(droga <= ostatnia) {wynik=n+1;}
	}

	printf("%d", wynik);
	return 0;
}
