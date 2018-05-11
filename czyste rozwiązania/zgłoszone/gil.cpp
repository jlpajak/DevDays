#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

#define MAXN 200100

int gildia[MAXN];
int miasta;
int liczba_polaczen;
int a,b;

int main(void){
	scanf("%d %d", &miasta, &liczba_polaczen);
	for(int i=0; i<liczba_polaczen; i++){
		scanf("%d %d", &a, &b);
		if(gildia[a] && !gildia[b]) gildia[b] = 3-gildia[a];
		else if(!gildia[a] && gildia[b]) gildia[a] = 3-gildia[b];
		else if(!gildia[a] && !gildia[b]) gildia[a] = 1, gildia[b] = 2;
	}

	for(int i=1; i<=miasta; i++)
		if(!gildia[i]){
			printf("NIE");
			return 0;
		}

		printf("TAK\n");
		for(int i=1; i<=miasta; i++)
			printf("%c\n", gildia[i]==1?'K':'S');

		return 0;
}