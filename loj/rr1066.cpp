#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=13;
int sx,sy;
int n;
char maze[N][N];
int d[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int ans;
int seek[N][N];
int cnt;
bool v[N][N];

void bfs(int xx,int yy,char goal)
{
    memset(v,false,sizeof(v));
    queue<int>x;
    queue<int>y;
    v[xx][yy]= true;
    maze[xx][yy]='.';
    x.push(xx);
    y.push(yy);
    while (!x.empty())
    {

	int px = x.front();x.pop();
	int py = y.front();y.pop();
//	cout<<"px:"<<px<<" py:"<<py<<endl;
	if (maze[px][py]==char(64+cnt))
	{
	    ans = d[px][py];
	    return;
	}
	for ( int i = 0 ; i< 4 ; i++ )
	{
	    int nx = px + dx[i];
	    int ny = py + dy[i];
	    if (nx>=0&&nx<n&&ny>=0&&ny<n&&!v[nx][ny]&&(maze[nx][ny]=='.'||maze[nx][ny]==goal))
	    {
		
		d[nx][ny] =  d[px][py]  + 1;
		if (maze[nx][ny]!='.')
		{
	//	    cout<<maze[nx][ny]<<" "<<seek[nx][ny]<<endl;
		    bfs(nx,ny,char(goal+1));
		    return;
		}
		
		v[nx][ny] = true;
		x.push(nx);
		y.push(ny);

	    }
	}
    }
}
int main()
{
    int T;
    cin>>T;
    int cas = 0 ;
    while ( T-- )
    {
	cas++;
	ans = -1;
	scanf("%d",&n);
	for ( int i = 0 ; i  < n ; i++ )
	{
	    scanf("%s",maze[i]);
	}
	 cnt = 0 ;// 统计食物的数量
	for ( int i = 0 ; i < n ; i++ )
	{
	    for ( int j = 0 ; j < n ; j ++)
	    {
		if (maze[i][j]=='A')
		{
		     sx = i ;
		     sy = j;
		}
		if (maze[i][j]!='#'&&maze[i][j]!='.')
		{
		    cnt++;
		 }
	    }
	}
	memset(d,-1,sizeof(d));
	d[sx][sy]  = 0;
	bfs(sx,sy,'B');
//	for ( int i = 0 ; i < n ; i++ )
//	{
//	    for ( int j = 0 ; j < n ; j++ )
//	    {
//		cout<<d[i][j]<<" ";
//	    }
//	    cout<<endl;
//	}
	printf("Case %d: ",cas); 
	if (ans==-1)
	{
	    printf("Impossible\n");
	}
	else
	{
	    printf("%d\n",ans);
	}
    }
  
	return 0;
} 
