/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 15时16分50秒
File Name :code/cf/problem/510C.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=105;
int n;
char st[N][N];
int p[30];
int offset[30];
bool conc[30][30];
int in[N];
int ans[N];
struct node
{
    int x;
    node(int xx)
    {
	x=xx;
    }
    bool operator <(const node a)const{
	return x>a.x;
    }
};
bool getconc( int x,int y)
{
    int lx = strlen(st[x]);
    int ly = strlen(st[y]);
    int len = min(lx,ly);
    for ( int i =  0; i < len ; i++)
    {
	if (st[x][i]!=st[y][i])
	{
	    conc[st[x][i]-'a'][st[y][i]-'a'] = true;
	    return true;
	}
    }
    if (lx>ly) return false;
    return true;
}
bool pre()
{
    ms(conc,false);
    ms(in,0);
    scanf("%d",&n);
    for ( int i = 0 ;i  < n ; i++) scanf("%s",st[i]);

    bool ok = true;
    for ( int i = 0 ; i < n-1 ; i++)
    {
	ok = getconc(i,i+1);
	if (!ok) break;
    }
    if (ok) return true;
    return false;
}

bool topo()
{
    priority_queue<node>q;
    for ( int i = 0 ; i < 26 ; i++)
	if (in[i]==0)  q.push(i);
    
    int cnt = 0 ;

    while (!q.empty())
    {
	node v = q.top();q.pop();
	cnt++;
	ans[cnt]=v.x;
	for ( int i = 0 ; i < 26 ; i++)
	{
	    if (!conc[v.x][i]) continue;
	    in[i]--;
	    if (in[i]==0) q.push(i);
	}
    }
    if (cnt<26) return false;
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	if (pre())
	{
	    for ( int i = 0 ; i < 26 ; i++)
		for ( int j = 0 ; j < 26 ; j++)
		    if (conc[i][j]) in[j]++;
	    if (topo())
	    {
		for (int i = 1 ; i <= 26 ; i++)
		    printf("%c",char(ans[i]+'a'));
		puts("");
	    }
	    else
	    {
		puts("Impossible");
	    }
	}
	else
	{
	    puts("Impossible");
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
