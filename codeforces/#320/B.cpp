/*************************************************************************
	> File Name: code/cf/#320/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年11月10日 星期二 15时47分29秒
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
const int N = 8E2+7;
int n;
int ans[N];
struct node
{
    int x,y;
    int val;
    bool operator<(const node &a)const{
	return val<a.val;
    }
}e;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   
   ms(ans,-1);
   scanf("%d",&n);
   priority_queue<node>q;
   for ( int i = 2 ; i <= 2*n ; i++)
       for ( int j = 1 ; j < i ; j++)
       {
	   int tmp;
	   scanf("%d",&tmp);
	   e.x = i;
	   e.y = j;
	   e.val = tmp;
	   q.push(e);
       }

   while (!q.empty())
    {
	node pre = q.top();q.pop();
//	cout<<"val:"<<pre.val<<endl;

	if (ans[pre.x]==-1&&ans[pre.y]==-1)
	{
	    ans[pre.x] = pre.y;
	    ans[pre.y] = pre.x;
	}
    }
    for ( int i = 1 ; i <= 2*n ; i++)
	if (i!=2*n) printf("%d ",ans[i]);
	else printf("%d\n",ans[i]);
  
   
 #ifndef ONLINE_JUDGE  
  #endif
  fclose(stdin);
	return 0;
}
