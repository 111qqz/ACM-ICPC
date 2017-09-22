/* ***********************************************
Author :111qqz
Created Time :2015年12月27日 星期日 20时46分30秒
File Name :code/cf/#337/D.cpp
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
const int N=1E5+7;
int n;
LL ans;
struct point
{
    LL x,y;

    void input()
    {
    //	scanf("%d %d",&x,&y);
	cin>>x>>y;
    }

    bool operator ==(point c)const
    {
	return x==c.x&&y==c.y;
    }

};

struct line
{
    point a,b;

    void input()
    {
	a.input();
	b.input();
    }

    bool operator<( line c)const
    {
	if (a.x==c.a.x)
	{
	    return  a.y<c.a.y;
	}
	if (a.y==c.a.y)
	{
	    return a.x<c.a.x;
	}
    }

    bool operator==(line c)const
    {
	return a==c.a&&b==c.b;
    }
}li[N],h[N],v[N],uh[N],uv[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	int cntv = 0;
	int cnth = 0 ;
	ans = 0 ;
	for ( int i =  1 ; i <= n ; i++)
	{
	    li[i].input();
	    if (li[i].a.x==li[i].b.x)
	    {
		
		cntv++;
		if (li[i].a.y>li[i].b.y) swap(li[i].a.y,li[i].b.y);
		v[cntv] = li[i];
	//	ans += abs(li[i].a.y-li[i].b.y)+1;
	    }
	    else
	    {
		cnth++;
		if (li[i].a.x>li[i].b.x) swap(li[i].a.x,li[i].b.x);
	//	ans += abs(li[i].a.x-li[i].b.x)+1;
		h[cnth] = li[i];
	    }
	}

//	cout<<"ans:"<<ans<<endl;
	sort(h,h+cnth);
	sort(v,v+cntv);



	
	for ( int i =1 ; i <= cnth ; i++)
	{
	    if (h[i]==h[i-1]) continue;
	    ans +=abs(h[i].b.x-h[i].a.x)+1;
	}

	for ( int i = 1 ; i <= cntv ; i ++)
	{
	    if (v[i]==v[i-1]) continue;
	    ans +=abs(v[i].a.y-v[i].b.y)+1;
	}
	for ( int i = 1 ; i <= cnth ; i++)
	{
	    if (h[i]==h[i-1]) continue;
//	    ans +=abs(h[i].b.x-h[i].a.x)+1;
	    for ( int j =1  ; j <= cntv ; j++)
	    {
		if (v[j]==v[j-1]) continue;
//		ans +=abs(v[i].a.y-v[i].b.y)+1;
	//	cout<<v[j].a.y<<" "<<v[j].b.y<<" "<<h[i].a.y<<endl;
//		cout<<ans<<endl;	
	
		if (v[j].a.y<=h[i].a.y&&h[i].a.y<=v[j].b.y)
		{
		  //  cout<<"324324243"<<endl;
		    ans--;
		}
	    }
	}

	cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
