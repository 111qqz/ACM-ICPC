/* ***********************************************
Author :111qqz
Created Time :2016年11月22日 星期二 22时43分26秒
File Name :code/poj/1971.cpp
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
const int MAXHASH = 7345787;
struct point
{
    int x,y;
    bool operator < (point b)const
    {
	if (x==b.x) return y<b.y;
	return x<b.x;
    }
}p[1005],mid[1001*1001];
int n;
int mp[MAXHASH];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ms(mp,0);
	    scanf("%d",&n);
	    for ( int i = 1; i <= n ; i++) scanf("%d%d",&p[i].x,&p[i].y);
	    int cnt = 0 ;
	    for ( int i = 1; i <= n ; i++)
		for ( int j = i +1 ; j <= n ;j++)
		{
		    mid[++cnt].x = p[i].x + p[j].x;
		    mid[cnt].y = p[i].y + p[j].y;
		}

	    sort(mid+1,mid+cnt+1);
	    LL ans = 0 ;
	    int num = 0 ;
	    for ( int i = 1; i <= cnt-1 ; i++)
	    {
		if (mid[i].x==mid[i+1].x&&mid[i].y==mid[i+1].y)
		{
		    num++;
		    ans = ans + num;
		}
		else
		{
		    num = 0 ;
		}
	    }
	    printf("%lld\n",ans);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
