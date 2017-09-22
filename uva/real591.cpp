/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 14时15分09秒
File Name :code/uva/real591.cpp
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
const int N=105;
int h[N];
int n ;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int cas = 0  ;
	while (~scanf("%d",&n)&&n)
	{
	    int sum = 0 ; 
	    for ( int i = 0 ; i < n ; i++)
	    {
		scanf("%d",&h[i]);
		sum +=h[i];
	    }
	    int ans = 0 ; 
	    int ave = sum/n;
	    for ( int i = 0 ; i < n ; i++)
	    {
		if (h[i]<ave)
		{
		    ans+=ave-h[i];
		}
	    }
	    printf("Set #%d\n",++cas);
	    printf("The minimum number of moves is %d.\n",ans);
	    puts("");
	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
