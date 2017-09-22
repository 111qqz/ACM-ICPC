/*************************************************************************
	> File Name: code/0920/r1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月20日 星期日 15时40分21秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=2E2+7;
const double eps = 1E-8;
int m,n;
int ans[N];
struct Point
{
    double x,y;
}p[N];

double a[N][N];

double dis( Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
 // #ifndef  ONLINE_JUDGE 
   // freopen("in.txt","r",stdin);  
//  #endif
    int T;
    cin>>T;
    while (T--)
    {
	scanf("%d %d",&m,&n);
	ms(p,0);
	ms(a,0);
	ms(ans,0);
	for ( int i = 0 ; i < m ; i++)
	{
	    scanf("%lf %lf",&p[i].x,&p[i].y);
	}


	if (n>m)
	{
	    puts("-1");
	    continue;
	}
	for ( int i = 0 ; i < m ; i++)
	{
	    for ( int j = 0 ; j < m ; j++)
	    {
		double tmp = dis(p[i],p[j]);
		a[i][j] = tmp;
	    }
	    a[i][m]= inf;

	    sort(a[i],a[i]+m);

	    double d1,d2;
	    d1 = a[i][n-1];
	    d2 = a[i][n];
	  //  cout<<"d1:"<<d1<<" d2:"<<d2<<endl;
	    
	    if (int(d1)==d1)
	    {
		if (d2>d1+1)
		{
		    ans[i] = int(d1) + 1;
		}
		else
		{
		    ans[i] = -1;
		}
	    }
	    else
	    {
		if (ceil(d1)>d2)
		    ans[i] = -1;
		else
		   ans[i] = ceil(d1);
	    }
	}
	sort(ans,ans+m);
	int ret = -1;
	for ( int i = 0 ; i < m ; i++)
	{
	    if (ans[i]>0)
	    {
		ret = ans[i];
		break;
	    }
	}
	printf("%d\n",ret);

    }
  
  
  // #ifndef ONLINE_JUDGE  
  //  fclose(stdin);
  //  #endif
	return 0;
}
