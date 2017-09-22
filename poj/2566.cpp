/*************************************************************************
	> File Name: code/poj/2566.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月24日 星期四 22时10分08秒
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
const int N=1E5+7;
const int inf = 0x3f3f3f3f;
int a[N];
int n ,k;
struct Q
{
    int id;
    int sum;
}pre[N];

bool cmp(Q a,Q b)
{
    if (a.sum<b.sum) return true;
    if (a.sum==b.sum&&a.id<b.id) return true;
    return false;
}

void solve ( int t)
{
    int ansl,ansr,ans;
    int l = 0 ;
    int r = 1;
    int mi = inf;
    while ( r<= n )
    {
	int tmp = pre[r].sum - pre[l].sum;
	
	if (abs(tmp-t)<mi)
	{
	    mi = abs(tmp-t);
	    ansl = min(pre[l].id,pre[r].id)+1;
	    ansr = max(pre[l].id,pre[r].id);
	    ans = tmp;
	}
	if (tmp<t)
	{
	    r++;
	}
	else
	if (tmp>t)
	{
	    l++;
	}
	else break;

	if (l==r) r++;
    }
    printf("%d %d %d\n",ans,ansl,ansr);
} 

int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    while (scanf("%d %d",&n,&k)!=EOF)
    {
	if (n==0&&k==0) break;
	pre[0].id = 0 ;
	pre[0].sum = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    scanf("%d",&a[i]);
	    pre[i].sum = pre[i-1].sum + a[i];
	    pre[i].id = i ;
	   // cout<<pre[i].sum<<" ";
	}
//	cout<<endl;

	sort(pre,pre+n+1,cmp);
//	for ( int i = 0 ; i <= n ; i++) cout<<pre[i].sum<<" "; cout<<endl;
	for ( int i = 1 ; i <= k ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    solve(x);
	}
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}


