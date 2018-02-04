/*************************************************************************
	> File Name: code/cf/#313/E.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月17日 星期一 09时35分46秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=1E5+7;
const int MOD=1E9+7;
int n,m,k,r,c;
ll a[N],ta[M + M];
pii p[N];
LL pow_mod(ll a,ll n,ll p){
    ll res = 1;
    while(n){
        if(n & 1){
           res = (res * a)%p;
        }
        n = n>>1;
        a = ( a * a ) % p;
    }
    return res;
}
LL Lucas(LL a,LL b,LL p)
{
    LL res = 1;
    while(a && b){
        LL aa = a % p,bb = b % p;
        if(aa < bb) return 0;
        res = (((res * ta[aa]) % p ) * pow_mod(ta[bb] * ta[aa - bb] % p,p - 2,p)) % p;
        a = a/p;b = b/p;
    }
    return res;
}
void init()
{
    ta[0] = 1;
    for(int i = 1;i<M + M;i++)
    {
        ta[i] = (ta[i-1] * i) % MOD;
    }
}
int main()
{
    init();
    while(~scanf("%d %d",&n,&m)!=EOF)
    {
        
        for ( int i = 0 ;i < k ; i++)
	{
	    scanf("%d %d",&r,&c);
            r--;
	    c--;
            p[i].first = r;
	    p[i].second = c;
        }
        p[k].first = n-1;
	p[k].second = m-1;k++;
        sort(p,p+k);
        FI(k){
            a[i] = Lucas(p[i].first + p[i].second,p[i].second,MOD);
            FJ(i){
                if(p[j].second <= p[i].second){
                    a[i] -= ( a[j] * Lucas(p[i].first - p[j].first + p[i].second - p[j].second,p[i].first - p[j].first,MOD)) % MOD;
                    a[i] = (a[i] + MOD)%MOD;
                }
            }

        }
        cout<<a[k-1]<<endl;
    }
    return 0;
}

