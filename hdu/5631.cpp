/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 21时11分19秒
File Name :code/hdu/5631.cpp
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
const int N=105;
int n;
int f[N];
bool ban[N];
pi edge[N];


void init()
{
    ms(f,0);
    for ( int i = 0 ; i < N ; i++) f[i] =  i;
}

int root ( int x)
{
    if (f[x]!=x)
	f[x]=root(f[x]);
    return f[x];
}

int Union( int x,int y)
{
    int rootx = root(x);
    int rooty = root(y);
  //  cout<<"rootx:"<<rootx<<" rooty:"<<rooty<<endl;
    if (rootx!=rooty)
    {
	f[rootx]=rooty;
	
	return 1;
    }
    return 0;
}

int solve()       //用并查集判断图连通性。如果是联通图，那么一定会合并(union)n-1次（得到一棵生成树）	   
    //每次合并相当于添加了一条边，而且是不会使得图出现环的边。
{
    init();  //对于每一种情况，都要初始化一次。

    int cnt_merge = 0;
    
    for ( int i = 0 ; i <= n ; i++)
    {
	if (!ban[i])
	{
	    cnt_merge+=Union(edge[i].fst,edge[i].sec);
	}
    }
    return cnt_merge==n-1;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	int T;
	cin>>T;          
	while (T--)
	{
	  //  init();
	    cin>>n;
	    for ( int i = 0 ; i <= n ; i++) cin>>edge[i].fst>>edge[i].sec;

	    ms(ban,false);

	    int ans = 0  ;
	    for ( int i = 0 ; i <= n ; i++)
	    {
		ban[i] = true;
		ans +=solve();
		for ( int j = i+1 ; j <= n ; j++)
		{
		    ban[j] = true;
		    ans +=solve();
		    ban[j] = false; //回溯
		//    cout<<"ans:"<<ans<<endl;
		}
		ban[i] = false ;//回溯
		
	    }
	    cout<<ans<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
