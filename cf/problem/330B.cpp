/* ***********************************************
Author :111qqz
Created Time :2016年03月19日 星期六 10时39分40秒
File Name :code/cf/problem/330B.cpp
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
int cnt[N];
int n,m;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ms(cnt,0);
	cin>>n>>m;
	for ( int i = 1 ; i <= m ; i++) //因为m<n/2...一条m限制两个点不能相连。。最多限制2*m<n个。。。
	{				//所以至少有一个点不受任何限制。。把其他的所有点连到这个点上即可。
	    int u,v;                    //此时得到一个 star graph.
	    cin>>u>>v;
	    cnt[v]++;
	    cnt[u]++;
	}

	int p;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (cnt[i] == 0)
	    {
		p = i ;
		break;
	    }
	}

	cout<<n-1<<endl;
	for ( int i = 1; i <= n ; i++)
	{
	    if (i==p) continue;
	    cout<<p<<" "<<i<<endl;
	}

	
 

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
