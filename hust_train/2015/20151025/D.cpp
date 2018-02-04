/*************************************************************************
	> File Name: code/hust/20151025/D.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月25日 星期日 16时13分54秒
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
    int dir;
    int fint;
    int cost;
    int id;
}q[N];

bool cmp( Q a, Q b)
{
    return a.t<b.t;
}
int cnt[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   for ( int i = 0 ; i < n ; i++)scanf("%d %d %d",&q[i].t,&q[i].s,&q[i].f);
   for ( int i = 0 ; i < n ; i++)
    {
	q[i].id = i;
	if (q[i].s<q[i].f)
	{
	    q[i].dir = 1;
	    q[i].cost = q[i].f - q[i].s;
	}
	else
	{
	    q[i].dir = 0;  //1表示正向，0表示x轴富方向。
	    q[i].cost = q[i].s - q[i].f;
	}
	q[i].fint = q[i].t + q[i].cost;
    }
   sort(q,q+n,cmp);

 //  for ( int i = 0 ; i < n ; i++) printf("q[i].f:%d\n ",q[i].f);
   ms(cnt,0);
   for ( int i = 0 ; i < n ; i++)
    {
	for ( int j = i+1 ; j < n ; j++)
	{
	    if (i==j) continue;
	   // if (q[j].t>q[i].fint) break;
	    if (q[i].dir==q[j].dir)
	    {
		if(q[j].t-q[i].t+q[i].s==q[j].s)
		{
		    cnt[i]++;
		    cnt[j]++;
//		    cout<<"i:"<<i<<" J:"<<j<<endl;
		}
	    }
	    else
	    {
		if (q[i].fint<q[j].fint)
		{

		    if (q[i].dir==1)
		    {
			int tmpj = q[j].s-(q[i].fint-q[j].t);
			//	    cout<<"tmpj:"<<tmpj<<endl;
			//	    cout<<"i:"<<i<<" q[i].f:"<<q[i].f<<endl;
			if (tmpj<q[j].f) continue;
			if (tmpj<=q[i].f)
			{
			    //	cout<<"i:"<<i<<" j:"<<j<<" tmpj1:"<<tmpj<<endl;
			    cnt[i]++;
			    cnt[j]++;
			    //	//	cout<<"aaa?"                                   <<endl;
			}


		    }
		    else 
		    {

			int tmpj =q[j].s +(q[i].fint-q[j].t);
			// cout<<"j:"<<j<<" tmpj:"<<tmpj<<endl;
			//  cout<<"q[i].fint:"<<q[i].fint<<" q[i].t:"<<q[i].t<<endl;
			//  cout<<"i:"<<i<<" j:"<<j<<" tmpjj:"<<tmpj<<endl;
			if (tmpj>q[j].f) continue;
			if (tmpj>=q[i].f)
			{

			    	cnt[i]++;
			    	cnt[j]++;
			}
		    } 
		}
		else
		{
		    if (q[i].dir==1)
		    {

    			int tmpi = q[i].s+q[j].fint-q[j].t;
			    if (tmpi>q[i].f) continue;
	    		    if (tmpi>=q[j].f)
			    {
				cnt[i]++;
				cnt[j]++;
			    }
		    }
		    else
		    {
			int tmpi = q[i].s-(q[j].fint-q[i].t);
			if (tmpi>q[i].f) continue;
			if (tmpi<=q[j].f)
			{
			    cnt[i]++;
			    cnt[j]++;
			}
		    }
		}
	    }
	}
    }
   bool space = false;
   for ( int i = 0 ; i < n ; i++)
    {
	if (space)
	{
	    printf(" %d",cnt[q[i].id]);
	}
	else
	{
	    printf("%d",cnt[q[i].id]);
	    space = true;
	}
    }
   printf("\n");

    

  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
