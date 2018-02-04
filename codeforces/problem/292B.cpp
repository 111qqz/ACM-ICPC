/* ***********************************************
Author :111qqz
Created Time :2016年03月19日 星期六 12时50分19秒
File Name :code/cf/problem/292B.cpp
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
int n,m;
int in[N];
int out = 0 ;
bool cmp ( int x,int y)
{
    return x>y;
}

void solve (int x,int y,int z)
{
    if (x==2&&y==n-2&&z==0)
    {
	puts("bus topology");
	return;
    }
    if (x==0&&y==n&&z==0)
    {
	puts("ring topology");
	return;
    }
    if (x==n-1&&y==0&&z==1&&out==n-1)
    {
	puts("star topology");
	return;
    }
    puts("unknown topology");

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	ms(in,0);
	cin>>n>>m;
	for ( int i = 1 ; i <= m ; i++)
	{
	    int u,v;
	    cin>>u>>v;
	    in[u]++;
	    in[v]++;
	}
	sort(in+1,in+n+1,cmp);
	int cnt1,cnt2,cnt;
	cnt1=cnt2=cnt=0;

	for ( int i = 1 ; i <= n ; i++)
	{
	    if (in[i]>2)
	    {
		cnt++;
		out = in[i];
	    }
	    if (in[i]==2) cnt2++;
	    if (in[i]==1) cnt1++;
	    
	    if (in[i]==0) break;
	}
	solve (cnt1,cnt2,cnt);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
