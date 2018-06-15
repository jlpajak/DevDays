#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

#define MAX_N 1000000
#define PII pair<int, int>
#define POZ first
#define TEMP second

int Tmin[MAX_N];
int Tmax[MAX_N];
int n, a, b, naj;
int wynik=0;

int main(void){


	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &Tmin[i], &Tmax[i]);

	deque<PII> Q;
	for(int i=0; i<n; i++){
		int a=Tmin[i], b=Tmax[i];
		int naj = i;
		while(!Q.empty() && Q.front().TEMP <= a){
			naj = min(naj, Q.front().POZ);
			Q.pop_front();
		}
		Q.push_front(PII(naj, a));
		while(!Q.empty() && Q.back().TEMP > b){
			wynik = max(wynik, i-Q.back().POZ);
			Q.pop_back();
		}
	}
	while(!Q.empty()){
		wynik = max(wynik, n-Q.back().POZ);
		Q.pop_back();
	}
	printf("%d\n", wynik);
	return 0;
}