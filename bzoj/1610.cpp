/* ***********************************************
Author :111qqz
Created Time :2016年02月28日 星期日 01时34分35秒
File Name :code/bzoj/1610.cpp
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
const int N=205;
const double oo=1897987987;
struct node
{
    double x,y;


    double getk(node b)
    {
	return (y-b.y)/(x-b.x);
    }
    

}p[N];
double k[40005];
int n;


int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	cin>>n;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cin>>p[i].x>>p[i].y;
	}

	int cnt = 0 ;
	for ( int i = 1 ; i <= n-1  ;i++)
	{
	    for ( int j = i+1 ; j <= n ; j++)
	    {
		++cnt;
	//	cout<<"i:"<<i<<" p[i].y:"<<p[i].y<<" j:"<<j<<" p[j].y:"<<p[j].y<<endl;
		if (dblcmp(p[i].x-p[j].x)==0) k[cnt]=oo;
		else k[cnt] = p[i].getk(p[j]);
	    }
	}

	//check k
//	for ( int i = 1 ; i <= cnt ; i++) cout<<k[i]<<endl;
	sort(k+1,k+cnt+1);

	int ans = 0 ;
	for ( int i = 1 ; i <= cnt ; i++)
	{
	    if (i==1||dblcmp(k[i]-k[i-1])!=0) ans++;
	}

	cout<<ans<<endl;



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
