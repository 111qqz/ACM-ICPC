/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 03时20分44秒
File Name :code/hdu/1358.cpp
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
const int N=1E6+7;
int nxt[N];
char a[N];
int n ;
void getnxt( char *s)
{
    int i = 0 ;
    int j = -1;	
    nxt[0] = -1;
    int n = strlen(s);
    while (i<n)
	if (j==-1||s[i]==a[j]) nxt[++i]=++j;
	else j = nxt[j];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int cas = 0 ; 
	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    printf("Test case #%d\n",++cas);
	    scanf("%s",a);
	    getnxt(a);
//	    for ( int i = 0 ; i <= n ; i++  ) printf("nxt[%d]:%d\n",i,nxt[i]);

	    for ( int i = 1 ; i <= n ; i++)
	    {
		if (nxt[i]==0) continue;
		int tmp = i-nxt[i];
		if (i%tmp==0)
		    printf("%d %d\n",i,i/tmp);
	    }

	    printf("\n");

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
