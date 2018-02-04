/*************************************************************************
	> File Name: code/0926/1008test.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月26日 星期六 14时24分30秒
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
const int maxn = 1E9+5;
const int N=1E5+7;
int q;
LL mod;
LL c[N];
LL a[N];
map<int,LL>::iterator it;
map<int,LL>mp;
int cnt;
LL lowbit( LL x)
{
    return x&(-x);
}

void update ( LL x,LL delta)
{
    delta = delta % mod;
    for ( LL i = x ; i <= q+1 ; i = i + lowbit(i))
    {
	c[i] = (c[i]*delta)%mod;
    }
}

void update2( LL x)
{
    for ( LL i = x ; i <= q ; i  = i + lowbit(i))
    {
	c[i] = 1;
    }
}

LL sum (LL x)
{
    LL res  = 1;
    for ( LL i = x; i  >= 1 ; i = i - lowbit(i))
    {
	res = (res * c[i]) % mod;
    }
    return res;
}

void init()
{
    for  (int i = 0 ; i <= 100005 ; i++)
    {
	c[i] = 1;
    }
}
int main() 
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   int T;
   cin>>T;
    int cas = 0 ;
   while (T--)
    {
	cas++;
	ms(a,0);
	printf("Case #%d:\n",cas);
	mp.clear();
	scanf("%d %lld",&q,&mod);
	cnt = 0 ;
	init();
	for ( int i = 1 ; i <= q ; i++) 
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==1)
	    {
		cnt++;
		int y;
		scanf("%d",&y);
		a[cnt]  =  y;
		update (cnt,y);
		mp[i] = cnt;
		printf("%lld\n",sum(cnt));
    //
    //		for ( int j = 1 ;  j <= cnt  ; j++) cout<<"j:"<<j<<"sum[j]:"<<sum(j)<<endl;
	//		cout<<endl;
	    }
	    else
	    {
		int n;
		scanf("%d",&n);
		a[mp[n]] = 1;
		update2 (mp[n]);
	//	cout<<"n:"<<n<<" mp[n]"<<mp[n]<<endl;
    		printf("%lld\n",sum(cnt));
	//	update (1,1)
	//			for ( int  j = 1 ; j <= cnt  ; j++) cout<<"j:"<<j<<"sum[j]:"<<sum(j)<<endl;
 

	    }
	}
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
