/* ***********************************************
Author :111qqz
Created Time :Fri 14 Oct 2016 02:56:28 PM CST
File Name :code/sy15/K.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N = 1E5+7;
const int MOD = 1E9+7;
int n;
int a[10];
int dp[N][2][2][2][2][2];
int dfs( int pos,int c0,int c1,int c2,int c3,int c4,bool limit)
{
    if (pos==0) return 1;
  //  printf("%d %d %d %d %d\n",c0,c1,c2,c3,c4);
    if (!limit&&dp[pos][c0>=a[0]][c1>=a[1]][c2>=a[2]][c3>=a[3]][c4>=a[4]]!=-1) return dp[pos][c0>=a[0]][c1>=a[1]][c2==a[2]][c3 >= a[3]][c4 >= a[4]];

    int mn = limit?1:0;
    int res = 0 ;
    for ( int i = mn ; i <= 4 ; i++)
    {
	if (i==0&&c0>=a[0]) continue;
	if (i==1&&c1>=a[1]) continue;
	if (i==2&&c2>=a[2]) continue;
	if (i==3&&c3>=a[3]) continue;
	if (i==4&&c4>=a[4]) continue;
	res = (res + dfs(pos-1,c0+(i==0),c1+(i==1),c2+(i==2),c3+(i==3),c4+(i==4) , false))%MOD;
    }
    if (!limit) dp[ pos ][ c0>=a[0]][ c1>=a[1] ][ c2>=a[2] ][ c3>=a[3]][ c4>=a[4] ] = res;
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while  (T--)
	{
	    scanf("%d",&n);
	    for ( int i = 0 ; i <=4  ; i++) scanf("%d",&a[i]);
	    ms(dp,-1);
	    int ans = dfs(n,0,0,0,0,0,true);
	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
