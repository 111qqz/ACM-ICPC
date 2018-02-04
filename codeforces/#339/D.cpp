/* ***********************************************
Author :111qqz
Created Time :2016年02月20日 星期六 13时11分30秒
File Name :code/cf/#339/D.cpp
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
LL n,A,cf,cm,m;
LL b[N];
LL c[N]; //c[i]表示将i个变为最大值需要的最少花费
LL sum[N] ; //sum[i]表示花费最少的i个的价值和
struct node
{
    LL val;
    int id;

    bool operator < (node b)const
    {
	return val>b.val;
    }
}a[N];

bool cmp (LL a,LL b)
{
    return a<b;
}
bool cmp2( node a,node b)
{
    return a.id<b.id;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n>>A>>cf>>cm>>m;
	for ( int i = 1 ; i <= n ; i++) cin>>a[i].val,a[i].id =  i,b[i] = a[i].val;
	sort(b+1,b+n+1,cmp);
	sort(a+1,a+n+1);
	
	LL cost = 0 ;
	c[0] = 0;
	for ( int i = 1 ; i <= n ; i++)
	{
	    cost +=A-a[i].val;
	    c[i] = cost;
	}
	sum[0] = 0LL;
	for ( int i = 1 ; i <= n ; i++) sum[i] = sum[i-1] + b[i];

	LL maxnum;
	LL minval;
	LL ans = -1;
	for ( int i = 0 ; i <= n ; i++) //i表示达到最大值的有i个
	{
	    LL M = m;
	    LL left = M - c[i];
	    if (left<0) break;

	    LL l=0,r=A;
	    
	    while (l<r) //在剩下的n-i个数里二分最小值
	    {
		LL mid = (l+r+1)>>1;
		int x= lower_bound(b+1,b+n-i+1,mid)-b-1;
		if (mid*x-sum[x]<=left) l = mid;
		else r = mid -1;
	    }

	    if (cf*i+cm*l>ans)
	    {
		ans = cf*i+cm*l;
		maxnum  = i;
		minval = l;
	    }
	}

	for ( int i = 1 ; i <= maxnum ; i++) a[i].val = A;
	for ( int i = 1 ; i <= n ; i++) if (a[i].val<minval) a[i].val = minval;
	sort(a+1,a+n+1,cmp2);
	cout<<ans<<endl;
	for ( int i = 1 ; i <= n-1 ; i++) cout<<a[i].val<<" ";
	cout<<a[n].val<<endl;





  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
