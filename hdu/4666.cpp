/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 01时00分52秒
File Name :code/hdu/4666.cpp
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
const int N=6E4+7;
int n;
int k;
int x[6];
int p[16][N];


bool cmp()
void solve1()
{
    set<int>se;
    set<int>::iterator it;
    set<int>::reverse_iterator rit;
    for ( int i = 1 ; i <= n ; i++)
    {
	int opt;
	scanf("%d",&opt);
	if (opt==0)
	{
	    scanf("%d",&p[1][i]);
	    se.insert(p[1][i]);
	}
	else
	{
	    int id;
	    scanf("%d",&id);
	    se.erase(find(p[1][id]));
	}
	if (se.size()<=1) puts("0");
	else
	{
	    it = se.begin();
	    rit =se.rbegin();
	    
	    int ans = *rit-*it;
	    printf("%d\n",ans);
	}
	
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d%d",&n,&k))
	{
	    if (k==1) solve1();
	    if (k==2) solve2();
	    if (k==3) solve3();
	    if (k==4) solve4();
	    if (k==5) solve5();
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
