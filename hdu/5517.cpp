/* ***********************************************
Author :111qqz
Created Time :2017年10月10日 星期二 23时16分14秒
File Name :5517.cpp
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
#define PB push_back
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
int n,m;
struct node
{
    int a,b;
    void input()
    {
	scanf("%d%d",&a,&b);
    }
    bool operator < (node x)
    {
	return b<x.b;
    }
}p[N];
struct node2
{
    int c,d,e;
    void input()
    {
	scanf("%d%d%d",&c,&d,&e);
    }
    bool operator < (node2 x)
    {
	return e<x.e;
    }
}q[N];
struct point
{
    int x,y,z;
}p
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d %d",&n,&m);
	    for ( int i = 1 ; i <= n ; i++) p[i].input();
	    for ( int i = 1 ; i <= m ; i++) q[i].input();
	    sort(p+1,p+n+1);
	    sort(q+1,q+m+1);

	    int i = 1,j = 1;
	    vector < int>A;
	    vector< pair<int,int> >B;
	    for (  ; i <= n ; i++)
	    {
		while (j<=m&&p[i].b>q[j].e) j++;
		int flag = 0;
		while (j<=m&&p[i].b==q[j].e)
		{
		    flag=1;
		    B.PB(MP(q[j].d,q[j].e));
		    j++;
		}
		if (flag) j--;
		while (i<=n&&p[i].b==q[j].e)
		{
		    flag=2;
		    A.PB(p[i].b);
		    i++;
		}
		if (flag==2)
		{




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
