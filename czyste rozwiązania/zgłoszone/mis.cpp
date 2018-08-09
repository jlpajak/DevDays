#include <cstdio>
#include <cstring>

const int rodzaje_misiow=4;
const int max_misiow=38;
const int MOD=1000000;

int t[rodzaje_misiow];
int mem[rodzaje_misiow][rodzaje_misiow][max_misiow+2][max_misiow+2][max_misiow+2];
int nowy[rodzaje_misiow][rodzaje_misiow][max_misiow+2][max_misiow+2][max_misiow+2];

inline int ok(int a,int b,int c){
  return !((a/2==b/2 && b/2==c/2) || (a%2==b%2 && b%2==c%2));
}

int licz(){
  if (t[0]+t[1]+t[2]+t[3]==1) return 1;
  for (int i=0; i<rodzaje_misiow; ++i)
    for (int j=0; j<rodzaje_misiow; ++j)
      mem[i][j][(i==0)+(j==0)][(i==1)+(j==1)][(i==2)+(j==2)]++;

  for (int ile=2; ile<t[0]+t[1]+t[2]+t[3]; ++ile){
    memset(nowy,0,sizeof(nowy));

    for (int i=0; i<rodzaje_misiow; ++i)
      for (int j=0; j<rodzaje_misiow; ++j)
        for (int a=0; a<=t[0]; ++a)
          for (int b=0; b<=t[1]; ++b)
            for (int c=0; c<=t[2]; ++c) if (mem[i][j][a][b][c]){
              int d=ile-a-b-c;
              if (d>t[3]) continue;
              for (int rodzaj=0; rodzaj<rodzaje_misiow; ++rodzaj) if (ok(rodzaj,i,j)){
                nowy[rodzaj][i][a+(rodzaj==0)][b+(rodzaj==1)][c+(rodzaj==2)]+=mem[i][j][a][b][c];
                nowy[rodzaj][i][a+(rodzaj==0)][b+(rodzaj==1)][c+(rodzaj==2)]%=MOD;
              }
            }

    memcpy(mem,nowy,sizeof(mem));
  }
  int res=0;
  for (int i=0; i<rodzaje_misiow; ++i)
    for (int j=0; j<rodzaje_misiow; ++j)
      res=(res+mem[i][j][t[0]][t[1]][t[2]])%MOD;
  return res;
}
int main(){
  scanf("%d %d %d %d", t, t+1, t+2, t+3);
  printf("%d\n",licz());
  return 0;
}