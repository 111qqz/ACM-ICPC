/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 17时35分48秒
File Name :code/cf/#331/C.cpp
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
int n ;
struct point
{
    int x,y;
    int s;
    int id;

    bool operator <(point b)const
    {
	return s<b.s;
    }
}p[N];

bool cmp(point a,point b)
{
    return a.y-a.x<b.y-b.x;
}
struct node
{
    int val;
    int id;

    bool operator <(node b)const
    {
	return  val<b.val;
    }
}w[N];

int ans[N];

void solve()
{
    for ( int i = 0 ; i< n ; i++)
    {
	if (w[i].val!=p[i].s)
	{
	    puts("NO");
	    return ;
	}
	ans[w[i].id] = i;
    }
    puts("YES");
    for ( int i = 0 ; i < n ; i++)
    {
	cout<<p[ans[i]].x<<" "<<p[ans[i]].y<<endl;
    }

}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 0 ; i < n; i ++)
	{
	    scanf("%d %d",&p[i].x,&p[i].y);
	    p[i].s =p[i].y-p[i].x;
	    p[i].id = i;
	}
	sort(p,p+n);
	
	for ( int i = 0 ; i< n ;i++)
	{
	    scanf("%d",&w[i].val);
	    w[i].id = i ;
	}
	sort(w,w+n);

//	for ( int i = 0 ; i < n ; i++)
//	    cout<<w[i].val<<endl;
	
	solve();


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
