/* ***********************************************
Author :111qqz
Created Time :2016年03月07日 星期一 17时06分53秒
File Name :code/cf/#345/C.cpp
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
const int N=2E5+7;
LL a,b,c;
int n;
struct node
{
    LL x,y;

    bool operator < (node b)const
    {
	if (x==b.x) return y<b.y;
	return x<b.x;
    }
}p[N];
LL cal( LL x)
{
    LL res ;
    res = x*(x+1)/2;
    return res;
}
bool cmp(node a,node b)
{
    return a.y<b.y;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
 #endif
//	ios::sync_with_stdio(false);
	cin>>n;
	if (n==1) 
	{
	    puts("0");
	    return  0;
	}
	for ( int i  = 0 ; i < n ; i++) cin>>p[i].x>>p[i].y;
	sort(p,p+n);

	a = 0 ;
	b = 0 ; 
	c = 0 ;
	LL cnta=0,cntb=0,cntc=0;
//	p[n].x=inf;
//	p[n].y=inf;
	for ( int i = 0 ; i < n ; i++)
	{
	    if (i!=n-1&&p[i].x==p[i+1].x)
	    {
		cnta++;
	    }
	    else
	    {
		a +=cal(cnta);
		cnta = 0 ;
	    }
	}

	for ( int i = 0 ; i < n ; i++)
	{
	    if (i!=n-1&&p[i].x==p[i+1].x&&p[i].y==p[i+1].y)
	    {
		cntc++;
	    }
	    else
	    {
		c+=cal(cntc);
		cntc = 0;
	    }
	}

	sort(p,p+n,cmp);

	for ( int i = 0 ; i< n ; i++)
	{

//	    cout<<"x:"<<p[i].x<<" y:"<<p[i].y<<endl;
	    if (i!=n-1&&p[i].y==p[i+1].y)
	    {
		cntb++;
	    }
	    else
	    {
		b +=cal(cntb);
		cntb = 0 ;
	    }
	}

	LL ans =0LL;
//	cout<<"a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
	ans = ans +a + b - c;
	cout<<ans<<endl;

//  #ifndef ONLINE_JUDGE  
 // fclose(stdin);
//  #endif
    return 0;
}
