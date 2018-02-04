/* ***********************************************
Author :111qqz
Created Time :2016年03月26日 星期六 18时52分01秒
File Name :code/bc/#77/1001.cpp
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
const LL MOD =1E9+7;
const int N=1E3+9;
string s;
int cnt[30]; //start from 1
LL ny[N];
LL fac[30];

bool cmp( int a,int b)
{
    return a>b;
}


LL ksm(LL a,LL b)
{
    LL res=1LL;
    while (b>0)
    {
	if (b%2==1) res = (res*a)%MOD;
	b = b>>1;
	a = (a*a)%MOD;
    }
    return res;
}

void getny()
{
    ms(ny,0);
    for ( int i = 1 ; i <= 1004 ;  i++)
	ny[i] = ksm(LL(i),MOD-2);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
//	getny();
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>s;
	    ms(cnt,0);
	    int len = s.length();
	    for ( int i = 0 ; i < len;  i++)
	    {
		int tmp = s[i]-'a'+1;
		cnt[tmp]++;
	    }

	    int odd = 0 ;
	    int even = 0 ;
	    for ( int i = 1 ; i <= 26 ; i++)
	    {
		if (cnt[i]==0) continue;
		if (cnt[i]%2==0) even++;
		else odd++;
	    }
	    if (len%2==1&&odd>1)
	    {
		printf("0\n");
		continue;
	    }
	    if (len%2==0&&odd>0)
	    {
		printf("0\n");
		continue;
	    }

	    sort(cnt+1,cnt+27,cmp);

	    int p;
	    for ( int i = 1 ; i <= 26 ; i++)
	    {
		if (cnt[i]<=1)
		{
		    p = i-1;
		    break;
		}
		cnt[i] = cnt[i] / 2;
	    }
//	    cout<<"p:"<<p<<endl;
	    int hl = len/2;
	    LL ans = 1LL;
	    for ( LL i = 1 ; i <= hl ; i++) ans = (ans * i)%MOD;
//	    cout<<"ans1:"<<ans<<endl;
	    
	    for ( int i = 1 ; i <= p ; i++)
	    {
		fac[i] = 1LL;
		for ( LL j = 2 ; j <= LL(cnt[i]) ; j++)
		{
		    fac[i] = (fac[i] * j)%MOD;
		}
	    }
	    for ( int i = 1 ; i <= p ; i++)
	    {
		LL tmpny = ksm(fac[i],MOD-2);
		ans = (ans * tmpny)%MOD;
	    }
	    ans = ans % MOD;
	    printf("%I64d\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
