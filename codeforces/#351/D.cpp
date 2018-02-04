/* ***********************************************
Author :111qqz
Created Time :2016年05月08日 星期日 00时55分42秒
File Name :code/cf/#351/D.cpp
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
const int N=1E3+7;
int n,k,a,b,c,d;
int p[N];
int nxt[N];
int ans1[N],ans2[N];
bool conc[N][N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(conc,false);
	cin>>n>>k;
	cin>>a>>b>>c>>d;
	int cnt = 0 ;
	ms(p,0);
	for ( int i = 1 ; i <= n  ; i ++)
	{
	    if (i==a||i==b||i==c||i==d) continue;
	    p[++cnt] = i;
	}

	ms(nxt,-1);

	for ( int i = 1 ; i <= cnt-2 ; i++)
	{
	   // cout<<"p[i]:"<<p[i]<<endl;
	    nxt[p[i]] = p[i+1];
	}

	nxt[a]=c;
	nxt[c]=p[1];
	nxt[p[cnt]] = d;
	nxt[d] = b;
	
	bool die = false;
	int x = a;
	ans1[1] = x;
	for ( int i = 2 ; i <= n ; i++)
	{
	  //  cout<<"x:"<<x<<endl;
	    x = nxt[x];
	    ans1[i] = x;
	    if (x<=0) die = true;
	    cout<<"xx:"<<x<<endl;
	}

	for ( int i = 1 ; i <= n ; i++) cout<<ans1[i]<<" ";cout<<endl;
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    conc[ans1[i]][ans1[i+1]] = true;
	    conc[ans1[i+1]][ans1[i]] = true;
	}

	nxt[c] = a;
	nxt[a] = p[1];
	nxt[p[cnt]] = b;
	nxt[b] = d;
	
	x = c;
	ans2[1] = x;
	for ( int i = 2 ; i <= n ; i++)
	{
	    x = nxt[x];
	    ans2[i] = x;
//    cout<<"x:"<<x<<endl;
	}

//	for ( int i = 1 ; i <= n ; i++) cout<<ans2[i]<<" ";
	for ( int i = 1 ; i <= n-1 ; i++)
	{
	    conc[ans2[i]][ans2[i+1]] = true;
	    conc[ans2[i+1]][ans2[i]] = true;
	}

	int num = 0 ;
	for ( int i = 1 ; i <=n-1 ; i++)
	    for ( int j = i+1 ; j <= n ; j++)
		if (conc[i][j]) num++;
	if (die) num = k+1;
	if (num>k)
	{
	    puts("-1");
	}
	else
	{
	    for ( int i = 1 ; i <= n-1 ; i++) cout<<ans1[i]<<" ";
	    cout<<ans1[n]<<endl;
	    for ( int i = 1 ; i <= n-1 ; i++) cout<<ans2[i]<<" ";
	    cout<<ans2[n]<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
