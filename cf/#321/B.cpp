/*************************************************************************
	> File Name: code/cf/#321/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月25日 星期五 17时21分55秒
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
const int N=1E5+7;
LL n,d;
struct Q
{
    LL m,f;
}q[N];

bool cmp(Q a,Q b)
{
    if (a.m<b.m) return true;
    return false;
}

void solve()
{

    LL head = 0 ;
    LL tail = 0 ;
    LL sum  = 0 ;
    LL  ans = -1 ;
    while (head<n)
    {
	while (q[tail].m-q[head].m<d&&tail<n)
	{
	    sum += q[tail].f;
//	    cout<<"sum:"<<sum<<endl;
	    tail++;
	}
//	cout<<"sum:"<<sum<<endl;
	ans = max (ans,sum);
	sum -= q[head].f;
	head++;

    }
    cout<<ans<<endl;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
    while(scanf("%lld %lld",&n,&d)!=EOF)
    {
	 for ( int i =  0; i  < n ; i++) cin>>q[i].m>>q[i].f;
	 sort(q,q+n,cmp);
//	 for ( int i = 0 ; i < n ; i++) cout<<q[i].m<<" "<<q[i].f<<endl;
	 solve();
    }
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
