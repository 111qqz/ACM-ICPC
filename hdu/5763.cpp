/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 11时07分24秒
File Name :code/hdu/5763.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int MOD = 1E9+7;
const int N=1E5+7;
int nxt[N];
char a[N],b[N];
bool v[N];
int dp[N];
void getnxt(char *s)
{
    int i = 0;
    int j = -1;
    nxt[0] = -1;
    int n = strlen(s);
    while (i<n)
	if (j==-1||s[i]==s[j]) nxt[++i]=++j;
	else j = nxt[j];
}
void kmp( char *a,char *b)
{
    int n = strlen(a);
    int m = strlen(b);
    getnxt(b);
    int i = 0 ;
    int j = 0 ;
    while (i<n)
    {
	if (j==-1||a[i]==b[j]) i++,j++;
	else j = nxt[j];
	if (j==m)
	{
	    v[i-m] = true;
//	    cout<<"i:"<<i<<" i-m:"<<i-m<<endl;
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	int cas = 0;
	while (T--)
	{
	    printf("Case #%d: ",++cas);
	    scanf("%s",a);
	    scanf("%s",b);
	    ms(v,false);
	    kmp(a,b);
	    int len1 = strlen(a);
	    int len2 = strlen(b);
	    ms(dp,0);
//	    for ( int i = 0 ; i < len1 ; i++) cout<<i<<" "<<v[i]<<endl;
	    
	    dp[0] = 1; //dp[i]表示到长度i为止的方案数。
	    for ( int i = 0 ; i < len1;  i++)  //这样考虑比较容易，我们考虑第i位的贡献。
	    {					//第i位的贡献无论如何都可以传递到下一位。如果第i位是某个匹配开始的位置，还可以传递到i+len2-1的位置。
		dp[i+1] = (dp[i+1] + dp[i])%MOD;
		if (v[i]) dp[i+len2] = (dp[i+len2] + dp[i]) % MOD;
	    }
//	    for ( int i = 0 ; i <= len1 ; i++) cout<<i<<" dp[i]:"<<dp[i]<<endl;
	    printf("%d\n",dp[len1]%MOD);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
