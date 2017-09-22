/* ***********************************************
Author :111qqz
Created Time :2016年04月03日 星期日 21时33分17秒
File Name :code/bzoj/r1619.cpp
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
#include <assert.h>
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
const int dx8[8]={1,1,1,0,0,-1,-1,-1};
const int dy8[8]={-1,0,1,1,-1,-1,0,1};
const int inf = 0x3f3f3f3f;
const int N=705;
int n,m;
bool vis[N][N];
int he[N][N];

struct node
{
    int x,y;
    int val;

    bool operator < (node b)const
    {
	return val>b.val;
    }
}h[N*N];

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void dfs ( int x,int y)
{
 //   cout<<"x:"<<x<<" y:"<<y<<endl;
 //   assert((x>=1)&&x<N);
 //   assert(y>=1&&y<N);
    vis[x][y] = true;


    for ( int i = 0 ; i < 8 ; i++)
    {
	int nx = x + dx8[i];
	int ny = y + dy8[i];
		
	if (nx<1||ny<1||nx>n||ny>m) continue;
//	assert(nx>=1&&nx<N);
//	assert(ny>=1&&ny<N);
//	cout<<"nx:"<<nx<<" ny:"<<ny<<endl;
	if (he[x][y]<he[nx][ny]) continue;
	if (vis[nx][ny]) continue;
	dfs(nx,ny);
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

//	ios::sync_with_stdio(false);
	//n = read();
	//m = read();
	cin>>n>>m;
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= m ; j++)
	    {	
		   // he[i][j] = read();
		    cin>>he[i][j];
		    cnt++;
		    h[cnt].x = i;
		    h[cnt].y = j;
		    h[cnt].val = he[i][j];
	//	    assert(cnt<10000);
	    }

	sort(h+1,h+cnt+1);
	ms(vis,false);

	int ans = 0 ;
	for ( int i = 1 ; i <= cnt ; i++)
	{
	    int x = h[i].x;
	    int y = h[i].y;
	    assert(x>=1&&x<N);
	    assert(y>=1&&y<N);
	    if (!vis[x][y])
	    {
		dfs(x,y);
		ans++;
//		cout<<endl;
	    }
	    
	}

	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
