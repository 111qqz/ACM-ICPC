/* ***********************************************
Author :111qqz
Created Time :2016年01月31日 星期日 16时09分42秒
File Name :code/cf/#340/C.cpp
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
const int N=2E3+7;

struct point
{
    LL x,y;

    void in()
    {
	//scanf("%d %d",&x,&y);
	cin>>x>>y;
    }

    LL dis(point p)
    {
	return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
    }

}p[N],a,b;
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
    scanf("%d",&n);
    a.in();
    b.in();
    for ( int i = 1 ;i <= n ; i++) p[i].in();

    LL ans = 1E15;
    for ( int i = 0 ; i <= n ; i++)
    {
	
	LL d1 = a.dis(p[i]);
	if (i==0) d1=0;
	LL d2= 0;
	for ( int  j = 1 ; j <= n ; j++)
	{
	    if (i==j) continue;
	    if (a.dis(p[j])<=d1) continue;
	    LL tmp2 = b.dis(p[j]);
	    d2 = max(d2,tmp2);
	}
	ans = min(ans,d1+d2);
	//cout<<ans<<endl;
    }
    cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
