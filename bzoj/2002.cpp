/* ***********************************************
Author :111qqz
Created Time :2016年02月21日 星期日 02时29分39秒
File Name :code/bzoj/2002.cpp
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
const int N=2E5+7;
int n,m;
int siz = 450; //sqrt(2E5)
int a[N];
int pos[N];
int cnt[N];
int nxt[N];
int end[N];


void go( int x)
{
    int ans = 0  ;
    while (1)
    {
	if (x>=n)
	{
	    printf("%d\n",ans);
	    break;
	}
	ans +=cnt[x];
	x = nxt[x];
//	cout<<"nxt[x]:"<<nxt[x]<<endl;
    }
}
void update ( int i,int j)
{
    if (j>=n)
    {
	cnt[i]=1;
	nxt[i]=n;
	end[i]=i;
    }
    else
    {
	if (pos[i]==pos[j])
	{
	    cnt[i] = cnt[j] + 1;
	    nxt[i] = nxt[j];
	    end[i]=end[j];
	}
	else
	{
	    cnt[i] = 1;
	    nxt[i] = j;
	    end[i] = end[j];
	}
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 0 ; i < n ;i++)
	{
	    scanf("%d",&a[i]);
	    pos[i] = i/siz;
	}

	for ( int i = n - 1 ; i >= 0 ; i--) update(i,i+a[i]);

	scanf("%d",&m);
	while (m--)
	{
	    int opt;
	    scanf("%d",&opt);
	    if (opt==1)
	    {
		int x;
		scanf("%d",&x);
		go(x);
	    }
	    else
	    {
		int x,y;
		scanf("%d %d",&x,&y);
		a[x]=y;
		update(x,x+a[x]);
		int p = pos[x]*siz;
		for ( int i = x-1  ; i >= p ; i--) update(i,i+a[i]);
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
