/* ***********************************************
Author :111qqz
Created Time :2017年11月17日 星期五 22时52分53秒
File Name :C.cpp
************************************************ */

#include <bits/stdc++.h>
#define PB push_back
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
const int N=2E3+7;
int n;
int a[N];
int dp[2*N][22];
int gcd( int a,int b)
{
    return b?gcd(b,a%b):a;
}
void rmq_init()
{
    for ( int i = 1 ; i <= n ; i++) dp[i][0] = a[i];
    for ( int j = 1 ; (1<<j)<= n ; j++)
	for ( int i =1 ; i + (1<<j)-1 <= n ; i++)
	    dp[i][j] = gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int rmq_gcd(int l,int r)
{
    if (l>r)swap(l,r);
    int k = 0 ;
    while (1<<(k+1)<=r-l+1) k++;
    return gcd(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	int cnt1 = 0 ;
	for ( int i = 1 ; i <= n ; i++) if (a[i]==1) cnt1++;
	if (cnt1>0)
	{
	    cout<<n-cnt1<<endl;
	    return 0;
	}
	rmq_init();
	int mnlen = n+1;
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = i ; j <= n ; j++)
	    {
		if (rmq_gcd(i,j)==1)
		{
		    mnlen = min(mnlen,j-i+1);
		}
	    }
	if (mnlen==n+1) puts("-1");
	else cout<<n-2+mnlen<<endl;
		    



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
