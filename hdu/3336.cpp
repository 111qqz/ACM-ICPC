/* ***********************************************
Author :111qqz
Created Time :2016年08月12日 星期五 12时59分12秒
File Name :code/hdu/3336.cpp
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

using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int MOD = 10007;
const int N=2E5+7;
int n;
char s[N];
int nxt[N];
int ans;
void getnxt(char *s)
{
    int n = strlen(s);
    int i = 0 ;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||s[i]==s[j]) nxt[++i]=++j;
	else j = nxt[j];
}
void dfs( int x)
{
    if (x<=0) return ;
    ans = (ans + 1) % MOD;
    dfs(nxt[x]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	scanf("%d",&T);
	while (T--)
	{
	    scanf("%d",&n);
	    scanf("%s",s);
	    getnxt(s);
	    int len = strlen(s);
	    ans = len;
	    //for ( int i = 1 ; i <= len ; i++) cout<<"i:"<<i<<" "<<nxt[i]<<endl;
	    for ( int i = 1 ; i <= len ; i++)
		if (nxt[i]>0) dfs(nxt[i]);//cout<<"ans:"<<ans<<endl;

	    printf("%d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
