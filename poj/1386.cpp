/* ***********************************************
Author :111qqz
Created Time :2016年08月27日 星期六 00时25分50秒
File Name :code/poj/1386.cpp
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
const int N=26;
int in[N];
int out[N];
int f[N];
int root ( int x)
{
    if (x!=f[x]) f[x] = root(f[x]);
    return f[x];
}
void merge( int x,int y)
{
    int rx = root(x);
    int ry = root(y);
    if (rx!=ry)
	f[rx] = ry;
}
void init()
{
    for ( int i = 0 ; i < N ;  i++) f[i] =  i;
    ms(in,0);
    ms(out,0);
}
int n ;
set<int>se;
bool Euler()
{
    int a,b;
    a=b=0;
    set<int>::iterator it;
    for ( it = se.begin() ;it!=se.end() ; it++)
    {
	int i = *it;
	if (in[i]==out[i]+1)a++;
	else if (out[i]==in[i]+1) b++;
	else if (out[i]!=in[i]) return false;
    }
    if (a+b==0||(a==1&&b==1)) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    init();
	    scanf("%d",&n);
	    se.clear();
	    for ( int i = 0 ; i < n ; i++)
	    {
		char st[1005];
		scanf("%s",st);
		int len = strlen(st);
		int u = st[0]-'a';
		int v = st[len-1]-'a';
		merge(u,v);
		out[u]++;
		in[v]++;
		se.insert(v);
		se.insert(u);
	    }
	    int cnt = 0 ;
	    bool die = false;
	    for (set<int>::iterator it = se.begin() ; it!=se.end() ; it++)
	    {
		if (f[*it]==*it) cnt++;
		if (cnt>1)
		{
		    die = true;
		    break;
		}
	    }
	    if (!Euler()) die = true;
	    if (die)
	    {
		puts("The door cannot be opened.");
	    }
	    else
	    {
		puts("Ordering is possible.");
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
