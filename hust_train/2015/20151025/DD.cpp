/*************************************************************************
	> File Name: code/hust/20151025/DD.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月25日 星期日 19时54分25秒
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
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E3+7;
int n;

struct Q
{
    int t,s,f;
    int fint;
    int cost;
    int id;
    int dir;

}q[N];

int cnt[N];


bool cmp(Q a,Q b)
{
    return a.t<b.t;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   for ( int i = 0 ; i < n ;i++)
    {
	scanf("%d %d %d",&q[i].t,&q[i].s,&q[i].f);
	q[i].id= i;
	if (q[i].s<q[i].f)
	{
	    q[i].dir = 1;
	    q[i].cost = q[i].f-q[i].s;
	}
	else
	{
	    q[i].dir = 0;
	    q[i].cost = q[i].s - q[i].f;
	}
	q[i].fint = q[i].t + q[i].cost;
    }

    sort(q,q+n,cmp);
    ms(cnt,0);
    for ( int i = 0 ; i < n ; i++)
	for ( int j = 0 ;  j < n ; j++)
	{
	    if (i==j) continue;
	    if (q[i].dir==q[j].dir)
	    {
	//	cout<<"i:"<<q[i].id<<" j:"<<q[j].id<<endl;
		if (q[j].t-q[i].t+q[i].s==q[j].s&&!(q[j].f<q[i].s)&&!(q[i].f<q[j].s))
		{
		    cnt[q[i].id]++;
		    cnt[q[j].id]++;
		}
		if (q[i].t+q[i].s==q[j].t+q[j].s&&!(q[j].f>q[i].s)&&!(q[i].f>q[i].s))
		{
		    cnt[q[i].id]++;
		    cnt[q[j].id]++;
		}
	    }
	    else
	    {
		if (q[i].dir==1)
		{
		 //   int limt = min(q[i].fint,q[j].fint);
		  //  int nowi = q[i].s+(limt-q[i].t);
		  //  int nowj = q[j].s-(limt-q[j].t);
		    int x = q[j].t-q[i].t+q[j].s-q[i].s;
		 //   cout<<"limt:"<<limt<<endl;
		//    cout<<"i:"<<q[i].id<<" j:"<<q[j].id<<"nowi:"<<nowi<<" nowj:"<<nowj<<endl;
		    if (2*q[i].s<=x&&x<=2*q[i].f&&2*q[j].s>=x&&x>=2*q[j].f)
		    {
			cnt[q[i].id]++;
			cnt[q[j].id]++;
		    }
		}
		else
		{
		//    int limt = min(q[i].fint,q[j].fint);
		//    int nowi = q[i].s-(limt-q[i].t);
		//    int nowj = q[j].s+(limt-q[j].t);
		  //  cout<<"lim:"<<limt<<endl;
		  //  cout<<"ii:"<<q[i].id<<" j:"<<q[j].id <<"nowi:"<<nowi<<" nowj"<<nowj<<endl;
	//	    if (nowj>=nowi&&q[i].s>q[j].s)
	//	    {
	//		cnt[q[i].id]++;
	//		cnt[q[j].id]++;
	//	    }
		}
	    }
	}
    for ( int i = 0 ; i < n ; i++)
    {
	if (i!=n-1)
	{
	    printf("%d ",cnt[i]);
	}
	else
	{
	    printf("%d\n",cnt[i]);
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
