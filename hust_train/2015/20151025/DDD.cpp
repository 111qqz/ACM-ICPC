/*************************************************************************
	> File Name: code/hust/20151025/DDD.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月26日 星期一 20时16分47秒
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
	for ( int j = i+1 ;  j < n ; j++)
	{
	    if (q[i].dir==q[j].dir)
	    {
	//	if (q[i].fint<q[j].t) continue;
	//	cout<<"i:"<<q[i].id<<" j:"<<q[j].id<<endl;
		if (q[j].t-q[i].t+q[i].s==q[j].s&&q[i].fint>=q[j].t&&q[i].dir==1)
		{
		    cnt[q[i].id]++;
		    cnt[q[j].id]++;
		}
		if (q[i].s-(q[j].t-q[i].t)==q[j].s&&q[i].fint>=q[j].t&&q[i].dir==0) //wa了31次之后
										    //发现。。。除了写错之外。
										    //只有两个地方没考虑清楚。。
										    //一个是误以为同方向的可以一块考虑。
										    //实际上不能。因为这个wa了五六次。
															    //另一个是相向判相遇的时候，条件要判
				 //同一时刻的。。。比如j出现时，i在s[i]
		{
		    cnt[q[i].id]++;
		    cnt[q[j].id]++;
		}
	    }
	    else
	    {
		
		if (q[i].dir==1)
		{
		    int limt = min(q[i].fint,q[j].fint);
		    int nowi = q[i].s+(limt-q[i].t);
		    int nowj = q[j].s-(limt-q[j].t);
	//	    cout<<"limt:"<<limt<<endl;
	//	    cout<<"i:"<<q[i].id<<" j:"<<q[j].id<<"nowi:"<<nowi<<" nowj:"<<nowj<<endl;
		    if (nowi>=nowj&&q[i].s+(q[j].t-q[i].t)<=q[j].s)
		    {
			cnt[q[i].id]++;
			cnt[q[j].id]++;
		    }
		}
		else
		{
		    int limt = min(q[i].fint,q[j].fint);
		    int nowi = q[i].s-(limt-q[i].t);
		    int nowj = q[j].s+(limt-q[j].t);
	//	    cout<<"lim:"<<limt<<endl;
	//	    cout<<"ii:"<<q[i].id<<" j:"<<q[j].id <<"nowi:"<<nowi<<" nowj"<<nowj<<endl;
		    if (nowj>=nowi&&q[i].s-(q[j].t-q[i].t)>=q[j].s)
		    {
			cnt[q[i].id]++;
			cnt[q[j].id]++;
		    }
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
