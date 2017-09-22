/* ***********************************************
Author :111qqz
Created Time :2016年02月19日 星期五 20时07分54秒
File Name :code/cf/gym/100571.cpp
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
const LL MOD = 1E9+7;
LL f[N],x[N];
LL cha[N];
LL p[N];
int n,q;
LL a,b;

void getf()
{
    f[0]=a;
    for ( int i = 3 ; i <= n+5 ; i++)
    {
	f[i]= ((a*f[i-2])%MOD + (b*f[i-1])%MOD)%MOD;
    }
    for ( int i = 1 ; i <= n ; i++) cout<<"f[i]:"<<f[i]<<endl;
    
    for ( int i = 1; i <= n+5 ; i++)
	cha[i]=(f[i]-f[i-1]+MOD)%MOD;

    for ( int i = 1 ; i <= n ; i++) cout<<"cha[i]:"<<cha[i]<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n>>q;
	cin>>f[1]>>f[2];
	cin>>a>>b;
	for ( int i = 1 ; i <= n ; i++) cin>>x[i];
	getf();
	ms(p,0);
	for ( int i = 1; i <= q ; i++)
	{
	    LL l,r;
	    cin>>l>>r;
	    p[l] = (p[l] + f[1])%MOD;
	    p[r+1] = (p[r+1]-f[r-l+2]+MOD)%MOD;
	for ( int i = 1 ; i <= n ; i++) cout<<p[i]<<" ";
	cout<<endl;
	}
	for ( int i = 2 ; i <= n ; i++)
	{
	    p[i] = (p[i] + p[i-1])%MOD;
	}

//	for ( int i = 1 ; i <= n ; i++) cout<<"p[i]:"<<p[i]<<endl;
	
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    cout<<(p[i]+x[i]+cha[i])%MOD<<" ";
	}
	cout<<(p[n]+x[n])%MOD<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

