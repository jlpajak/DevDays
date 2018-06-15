#include <cstdio>
#include <vector>

#define MAXN 1000001

using namespace std;

int m,c,n,k;
bool winning[MAXN];
int maxWinning;
int last[MAXN];
long long customers = 0 ;
int winners = 0;
vector <long long> lucky;
bool sold[MAXN];

int main () {
	scanf("%d", &m);
	for (int i = 0; i<m; i++){
		scanf("%d", &c);
		winning[c] = true;
	}
	maxWinning = c;
	scanf("%d", &n);
	for (int i = 0; i<n; i++){
		scanf("%d", &k);
		if (!last[k]){
			last[k] = k;
		}
		for (int served = 1; served <= k; served++ )
		{
			while(last[k] <= maxWinning && sold[last[k]]){
				last[k] += k;
			}
			if (last[k] > maxWinning){
				break;
			}
			if (winning[last[k]]){
				lucky.push_back(customers + served);
				winners ++;
			}
			sold[last[k]] = true;
			last[k] += k;
		}
		customers += k;
	}
	printf("%d\n", winners);
	for (int i = 0; i<winners; i++){
		printf("%lld\n", lucky[i]);
	}
	return 0;
}
