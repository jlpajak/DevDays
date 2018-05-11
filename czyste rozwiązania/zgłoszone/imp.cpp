#include <cstdio>

#define MAXN 3000

using namespace std;

bool kmatrix[MAXN][MAXN];
bool erased[MAXN];
int n, m, a, b;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		scanf("%d %d", &a, &b);
		kmatrix[a-1][b-1] = kmatrix[b-1][a-1] = 1;
	}
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n && !erased[i]; ++j)
			if(!kmatrix[i][j] && !erased[j]){
				erased[i] = 1;
				erased[j] = 1;
			}
	}
	int left = (n/3);
	for(int i = 0; left && i < n; ++i){
		if(!erased[i]){
			--left;
			printf("%d ", i+1);
		}
	}
	return 0;
}
