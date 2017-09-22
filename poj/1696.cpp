/*************************************************************************
	> File Name: code/poj/1696.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月08日 星期日 15时38分37秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define fst first              
#define sec second      
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
const int inf = 0x3f3f3f3f;
const int N=55;
int pos;
int n;

struct point
{   
    int id;
    int x,y;
    point(){}
    point (int _x,int _y)
    {
	x = _x;y=_y;
    }
    point operator -(const point &b)const
    {
	return point (x-b.x,y-b.y);
    }

    int operator^(const point &b)const
    {
	return x*b.y-y*b.x;
    }
    
    void input()
    {
	scanf("%d %d %d",&id,&x,&y);
    }
    int dis(point p)
    {
	return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);
    }
    int det(point p)
    {
	return x*p.y-y*p.x;
    }
    




}p[N];
            
bool cmp(point a,point b)
{
    int cross = (a-p[pos])^(b-p[pos]);
    if (cross==0)
	return p[pos].dis(a)<p[pos].dis(b);
    else if (cross<0) return false;
    else return true;
}

int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   int T;
   scanf("%d",&T);
   while (T--)
   {
       scanf("%d",&n);
       for ( int i = 0 ; i < n ; i++)
	{
	    p[i].input();
	    if (p[i].y<p[0].y||(p[i].y==p[0].y&&p[i].x<p[0].x))
		swap(p[0],p[i]);
	}
       
       pos = 0;
       for ( int i = 1 ; i < n ; i++)
	{
	    sort(p+i,p+n,cmp);
	    pos++;
	}
       printf("%d",n);
       for ( int i = 0 ; i < n ; i++)
	   printf(" %d",p[i].id);
       puts("");

   }
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
