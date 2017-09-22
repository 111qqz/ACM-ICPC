/*************************************************************************
	> File Name: code/zoj/3635.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月22日 星期四 10时03分36秒
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
const int N=5E5+7;
int t[N],a[N];
int ans[N],k;
int n,m;


int lowbit( int x)
{
    return x&(-x);
}
void update ( int x,int delta)
{
    for ( int i = x ; i <= n ; i = i + lowbit(i))
    {
	t[i] = t[i] + delta;
    }
}

int sum( int x)
{
    int res = 0 ; 
    for ( int i = x; i >= 1 ; i = i - lowbit(i))
    {
	res = res + t[i];
    }
    return res;
}

int bin_search(int l,int r)
{
    while (l<r)
    {
	int mid = (l+r)>>1;
	if (sum(mid)<k)
	    l = mid + 1;
	else r = mid ;
    }
    return r;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d",&n)!=EOF)
    {
    
	ms(t,0);
	ms(ans,0);
	ms(a,0);
	for ( int i = 1 ; i <= n ; i++) update(i,1);  //1表示没有被占，初始所有位置都没有被占。

	for ( int i =  1 ; i <= n ; i++)
	{
	
	    scanf("%d",&k);            //每次要占第k个没有被占的位置，由于被占的位置被设置成0,所以就是找第k大的。
	    
	    int posi = bin_search(1,n);
	    ans[i] =posi;
	    update(posi,-1);	//将被占的位置设置成0

	}




	scanf("%d",&m);
	int x;
	for ( int i = 1 ; i < m ; i++)
	{
	    scanf("%d",&x);
	    printf("%d ",ans[x]);
	}
	scanf("%d",&x);
	printf("%d\n",ans[x]);
	
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
