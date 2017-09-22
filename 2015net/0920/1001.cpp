/*************************************************************************
	> File Name: code/0920/1001.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月20日 星期日 12时23分42秒
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
const int N=1E2+5;
const double eps = 1E-8;
int m,n;
int ans[N];
struct Q{
    double x,y;
}q[N];
double dis (Q a,Q b)
{
    double res = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    return sqrt(res);
}
multiset<double>se[N];
multiset<double>::iterator it;
int main()
{
  #ifndef  ONLINE_JUDGE
    freopen("in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	ms(ans,0);
	scanf("%d %d",&m,&n);
	ms(q,0);
	for ( int i = 0 ; i < m ; i++)
	{
	    scanf("%lf %lf",&q[i].x,&q[i].y);
	}
	if (n>m)
	{
	    printf("%d\n",-1);
	    continue;
	   // cout<<"why"<<endl;
	}
	for ( int i = 0 ; i < m ; i ++)
	{
	    se[i].clear();
	   // se[i].insert(0); 
	    for ( int j = 0 ; j < m ; j++)
	    {
		
		double tmp = dis(q[i],q[j]);
		se[i].insert(tmp);
//		cout<<"i:"<<i<<"  j:"<<j<<" tmp:"<<tmp<<endl;
	    }
	    int cnt = 0 ;
	    se[i].insert(999999);
//	    for ( it=se[i].begin();it!=se[i].end();it++)
//	    {
//		cnt++;		cout<<"debug:"<<cnt<<" "<<*it<<endl;
//	    }
		double d1,d2;
	    cnt =  0;
	    for ( it =se[i].begin();it!=se[i].end();it++)
	    {
		cnt++;
		if (cnt==n)
		{
		    d1 = *it;
		}
		if (cnt==n+1)
		{
		    d2 = *it;
		    break;
		}
	    }
	  //  cout<<"d1:"<<d1<<"d2:"<<d2<<endl;
		
	    
	    if (fabs(int(d1)-d1)<eps)
	    {
		if (d2-d1-1>eps)
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
		if (ceil(d1)-d2>eps)
		{
		    ans[i] = -1;
		}
		else
		{

		    ans[i] = ceil(d1);
		}
	    }
	}
	int ret = -1;
	sort(ans,ans+m);
	for ( int i = 0 ; i < m ; i++)
	{
	    if (ans[i]>0)
	    {
		ret = ans[i];
//		cout<<"i:"<<i<<"   ";
		break;
	    }
	}
	printf("%d\n",ret);   
    }
   #ifndef ONLINE_JUDGE  
    fclose(stdin);
      #endif
	return 0;
}
