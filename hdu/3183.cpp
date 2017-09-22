/* ***********************************************
Author :111qqz
Created Time :2016年05月16日 星期一 13时15分44秒
File Name :code/hdu/3183.cpp
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
const int N=1E3+7;
int n,m;

int ans[N];
char st[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%s %d",st,&m))
	{
	    n = strlen(st);
	    ms(ans,0);

	    int x = 0 ;
	    for ( int i = 1 ; i <= n-m ; i++)
	    {
		int MIN = inf;
		for ( int j = x+1 ; j <= m+i ; j++)
		{
		    int val = st[j-1]-'0';
		    if (val<MIN)
		    {
			MIN = val;
			x = j;
		    }
		}
		ans[i] = MIN;
	    }

	    
	    bool zero = true;
	    bool output = false;
	    for ( int i = 1; i <= n-m ; i++)
	    {
		if (ans[i]!=0) zero = false;
		if (!zero)
		{
		    output = true;
		    printf("%d",ans[i]);
		}
	    }
	    if (output)
	    printf("\n");
	    else printf("0\n");

	}
	
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
