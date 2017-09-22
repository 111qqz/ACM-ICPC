/* ***********************************************
Author :111qqz
Created Time :2016年08月14日 星期日 12时13分22秒
File Name :code/ccpc2016/1011.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

#define get(t) ((t & 1) ? (-1) : (1))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int mod = 772002;
const int N=14;
char s[N][N];
int a[N][N],can[N][N],f[50][2000],X[N],Y[N],tot[2000],tmp[N][N];
int ans,TOT,n,m;
const int dir2[8][2] = {
   {-1,-1},{-1,0},{-1,1},{0,1},
   {1,1},{1,0},{1,-1},{0,-1}
};
int work(){
   int cnt = 0,x,y,flag;
   for (int i = 1;i <= n;i ++) for (int j = 1;j <= m;j ++)
       if (a[i][j]) X[cnt] = i,Y[cnt ++] = j;
   for (int p = 0;p < (1 << cnt);p ++){
       tot[p] = 0;
       ms(tmp,0);
       for (int i = 0;i < cnt;i ++) if (p & (1 << i))tmp[X[i]][Y[i]] = 1;
       for (int i = 1;i <= n;i ++) for (int j = 1;j <= m;j ++) if (!tmp[i][j]){
           flag = 1;
           for (int k = 0;k < 8 && flag;k ++){
               x = i + dir2[k][0],y = j + dir2[k][1];
               if (x < 1 || x > n || y < 1 || y > m) continue;
               if (tmp[x][y]) flag = 0;
           }
           if (flag) tot[p] ++;
       }
   }
   ms(f,0);
   f[0][0] = 1;
   int opp;
   for (int i = 1;i <= TOT;i ++){
       for (int p = 0;p < (1 << cnt);p ++)    if (f[i - 1][p]){
           opp = 0;
           for (int j = 0;j < cnt;j ++) if (!(p & (1 << j)))
               opp |= (1 << j),
               (f[i][p | (1 << j)] += f[i - 1][p]) %= mod;
           (f[i][p] += f[i - 1][p] * (tot[opp] - (i - 1)) % mod) %= mod;
       }
   }
   return f[TOT][(1 << cnt) - 1];
}
void tr(int x,int y,int t){
   a[x][y] = 1;
   int i,j,ret;
   for (int k = 0;k < 8;k ++) {
       i = x + dir2[k][0],j = y + dir2[k][1];
       if (i < 1 || i > n || j < 1 || j > m) continue;
       if (can[i][j]) continue;
       can[i][j] = t;
   }
   ret = work();
   ans = (ans + get(t) * ret) % mod;
   for (j = y + 1;j <= m;j ++) if (can[x][j] == 0) tr(x,j,t + 1);
   for (i = x + 1;i <= n;i ++) for (j = 1;j <= m;j ++)
       if (can[i][j] == 0) tr(i,j,t + 1);
   
   a[x][y] = 0;
   for (int k = 0;k < 8;k ++) {
       i = x + dir2[k][0],j = y + dir2[k][1];
       if (i < 1 || i > n || j < 1 || j > m) continue;
       if (can[i][j] == t) can[i][j] = 0;
   }
}
int main(){
    
//    freopen("code/in.txt","r",stdin);
    int cas = 0 ;
    while(scanf("%d%d",&n,&m)!=EOF){ 
	printf("Case #%d: ",++cas);
	int flag = 1,x,y;
	TOT = n * m;
	ms(s,0);
	ms(a,0);
	ms(can,0);
	ms(f,0);
	ms(tot,0);
	ms(tmp,0);
	ms(X,0);
	ms(Y,0);
	for (int i = 1;i <= n;i ++) {
	    scanf("%s",s[i]);
	    for (int j = 0;j < m;j ++)a[i][j + 1] = s[i][j] == 'X' ? 1 : 0;
	}
	for (int i = 1;i <= n && flag;i ++){
	    for (int j = 1;j <= m && flag;j ++) if (a[i][j]){
		if (can[i][j] == -1) flag = 0;
		can[i][j] = -1;
		for (int k = 0;k < 8;k ++) {
		    x = i + dir2[k][0],y = j + dir2[k][1];
		    if (x < 1 || x > n || y < 1 || y > m) continue;
		    can[x][y] = -1;
		}
	    }
	}
	if (!flag){puts("0");continue;}
	ans = work();
	for (int i = 1;i <= n;i ++) for (int j = 1;j <= m;j ++) if (can[i][j] == 0){
	    tr(i,j,1);
	}
	ans +=mod;
	ans%=mod;
    
	printf("%d\n",ans);
    }
	return 0;
}
