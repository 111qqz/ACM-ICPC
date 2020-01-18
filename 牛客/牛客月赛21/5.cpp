#include <bits/stdc++.h>
using namespace std;
const int N = 101;
char st[N][N][N];
int d[N][N][N];
int n;
int sx,sy,sz,tx,ty,tz;

int dirx[6]={1,-1,0,0,0,0};
int diry[6]={0,0,-1,1,0,0};
int dirz[6]={0,0,0,0,1,-1};
 
bool ok(int x,int y,int z)
{
    if (z>=0&&z<n&&x>=0&&x<n&&y>=0&&y<n&&d[z][x][y]==-1&&st[z][x][y]!='*')
          return true;
    return false;
}
 
void bfs()
{
    memset(d,-1,sizeof(d));
    queue<int>x;
    queue<int>y;
    queue<int>z;
    x.push(sx);
    y.push(sy);
    z.push(sz);
    d[sz][sx][sy]=0;
    while (!x.empty()&&!y.empty()&&!z.empty())
    {
          int prex = x.front();x.pop();
          int prey = y.front();y.pop();
          int prez = z.front();z.pop();
          for ( int  i = 0 ; i < 6 ; i++ )
          {
                int newx = prex+dirx[i];
                int newy = prey+diry[i];
                int newz = prez+dirz[i];
                bool flag = ok(newx,newy,newz);
                if (flag)
                {
                    d[newz][newx][newy]=d[prez][prex][prey]+1;
                    x.push(newx);
                    y.push(newy);
                    z.push(newz);
                }
          }
 
    }
}
int main()
{
    cin>>n;
          for ( int i = 0 ; i < n ; i++)
          {
                for ( int j = 0 ; j < n; j++)
                    scanf("%s",st[i][j]);
          }
          sx = 0;
          sy = 0;
          sz = 0;
          tx = n-1;
          ty = n-1;
          tz = n-1;
          bfs();
          int ans = (d[tz][tx][ty]==-1)?-1:(d[tz][tx][ty]+1);
          cout<<ans<<endl;

    return 0;
}
 