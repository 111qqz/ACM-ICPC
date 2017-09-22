/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 18时41分58秒
File Name :code/bzoj/1597.cpp
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
const int N=5E4+7;

LL llmax(LL x,LL y)
{
    if (x>y) return x;
    return y;
}
struct Rec
{
    LL x,y;
    
    bool operator <(Rec b)const
    {
	return x*y<b.x*b.y;
    }

    LL area()
    {
	return x*y;
    }


}rec[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	for ( int i = 0 ; i < n; i ++) cin>>rec[i].x>>rec[i].y;

	sort(rec,rec+n);

	
	LL ans = rec[0].area();
	LL cur = rec[0].area();
	LL px = rec[0].x;
	LL py = rec[0].y;
	LL now  = 0;
	int d = 1;
	for ( int i = 1 ; i < n ; i++)
	{
	    LL nx = llmax(rec[i].x,px);
	    LL ny = llmax(rec[i].y,py);
	    if (nx*ny<px*py+rec[i].area())
	    {
		px = nx;
		py = ny;
		cur = px*py;	
	    }
	    else
	    {
		px = -1;
		py = -1;
		
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
