/*************************************************************************
	> File Name: code/bc/#57/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月30日 星期三 11时08分35秒
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
const int mod = 1E9+7; 
struct P
{
    int x,y;
}a[N<<1];
LL ans;
int n;
LL sum[N],p[N];
bool cmp(P a,P b) {return a.x<b.x;}

void init() { p[0] = 1;for (int i = 1 ; i < N  ; i ++) p[i] = p[i-1]*2 %mod;}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1 ; i <= 2*n ; i+=2)
	{
            scanf("%d %d",&a[i].x,&a[i+1].x);
            a[i].y=1;
	    a[i+1].y=-1;
        }

        sum[1]=p[n-1];
        for(int i = 2 ; i <= n ; i++ ) sum[i]=(sum[i-1]+p[n-i])%mod;
        sort(a+1,a+2*n+1,cmp);
        int ans=0;
	int cnt=0;
        for(int i = 1 ; i < 2*n ;i++)
	{
            cnt = cnt + a[i].y;
            ans=(ans+sum[cnt]*(a[i+1].x-a[i].x)%mod)%mod;
        }
        printf("%d\n",ans);
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
