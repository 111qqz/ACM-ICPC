/* ***********************************************
Author :111qqz
Created Time :2016年05月10日 星期二 21时44分07秒
File Name :code/bzoj/1688.cpp
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
int n;
int cnt[N];
vector <int>v[N];
struct node
{
    int num;
    int id;

    bool operator < (node b)const
    {
	return num<b.num;
    }
}a[N],cnt[N];

bool cmp(node a,node b)
{
    return a.num>b.num;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d %d %d",&n,&d,&k);
	int ans = 0 ;
	ms(cnt,0);
	for ( int i = 1 ; i  <= n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    a[i].num = x;
	    a[i].id = i ;
	    for ( int j = 1 ; j <= x ;j++)
	    {
		int y;
		scanf("%d",&y);
		v[u].push_back(y);
	    }
	}

	for ( int i = 1 ; i <= n ; i++)
	{
	    if (a[i].num==0)
	    {
		ans++;
		continue;
	    }
	    if (a[i].num>k) break;
	    for ( int j = 1 ; j <= int(v[a[i].id].size()) ; j++)
		cnt[v[a[i].id][j]].num++;

	}

	sort(cnt+1,cnt+D+1,cmp);
	set<int>se;
	for ( int i = 1 ; i <= D ; i++)
	{
	    ans += cnt[i].num;

	}




  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
