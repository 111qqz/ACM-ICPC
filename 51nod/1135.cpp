/* ***********************************************
Author :111qqz
Created Time :2016年05月14日 星期六 11时39分54秒
File Name :code/51nod/1135.cpp
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
#include <bitset>
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
const int N=1E6+7;
int p[N],pri[N];
bitset<N> prime;
int k,cnt;
int P;
void isprime()
{
    prime.set();
    for ( int i = 2 ; i < N ; i++)
    {
	if (prime[i])
	{
	    p[k++] = i ;
	    for ( int j = i+i ; j < N ; j+=i)
		prime[j] = false;
	}
    }
}

void divide(int n)
{
    cnt = 0 ;
    int t = (int)sqrt(1.0*n);
    for ( int i = 0 ; p[i]<= t ; i++)
    {
	if (n%p[i]==0)
	{
	    pri[cnt++] = p[i];
	    while (n%p[i]==0) n/=p[i];
	}
    }
    if (n>1)
    {
	pri[cnt++] = n;
    }
}

LL ksm(LL a,LL b,LL mod)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b%2==1)
	{
	    res = (res * a)%mod;

	}
	b = b / 2;
	a = (a*a)%mod;
    }
    return res;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	isprime();
	while (scanf("%d",&P)!=EOF)
	{
	    if (P==2)
	    {
		puts("1");
		continue;
	    }
	    divide(P-1);
	    for ( int g = 2 ; g < P ; g++)
	    {
		bool flag = true;
		for ( int i = 0 ; i < cnt ; i++)
		{
		    int t = (P-1)/pri[i];
		    if (ksm(g,t,P)==1)
		    {
			flag = false;
			break;
		    }
		}
		if (flag)
		{
		    int ans = g;
		    printf("%d\n",ans);
		    break;
		}
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
