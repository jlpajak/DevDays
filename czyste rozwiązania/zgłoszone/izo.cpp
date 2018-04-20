#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

long long wynik = 0;
int w;
int n;

int main() {
	scanf("%d", &n);
	vector<int> warstwy;
	for(int i = 0; i < n; i++){
		scanf("%d", &w);
		warstwy.push_back(w);
	}
	sort(warstwy.begin(), warstwy.end());
	if(n%2){
		wynik = warstwy[n/2];
		for (int k = (n/2 + 1); k<n; k++) {wynik += 2*warstwy[k];}
	}
	else{
		for (int j = n/2; j<n; j++) {wynik += 2*warstwy[j];}
	}
	printf("%lld", wynik);
	return 0;
}
