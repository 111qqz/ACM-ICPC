/*************************************************************************
    > File Name: code/2015summer/0714/M.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com
    > Created tim: 2015年07月14日 星期二 11时37分51秒
 ************************************************************************/
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
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E2+5;
int m,n,k;
char mymap[N][N];
int tx,ty,sx,sy;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
int tim[N][N];
bool ok(int xxx,int yyy)
{
    bool flag1=true;
    bool flag2=true;
    if (mymap[xxx][yyy]=='*') flag1=false;
    if (tim[xxx][yyy]!=-1) flag2=false;
    if (xxx>=0&&xxx<m&&yyy>=0&&yyy<n&&flag1&&flag2)
        return true;
    return false;
}
void bfs()
{

    memset(tim,-1,sizeof(tim));
    queue<int>x;
    queue<int>y;
    x.push(sx);
    y.push(sy);
    tim[sx][sy]=0;
    while (!x.empty()&&!y.empty())
    {

      int xx=x.front();
      int yy=y.front();
      x.pop();
      y.pop();
      if (xx==tx&&yy==ty) {break;}
      for ( int i = 0 ; i < 4 ; i++ )
      {
        int tmpx = xx+dirx[i];
        int tmpy = yy+diry[i];
        if (ok(tmpx,tmpy))
        {
            if (mymap[tmpx][tmpy]=='|')
            {
              if (tim[xx][yy]%2==0)
              {
                if (i== 0&&ok(tmpx,tmpy+1))
                {
                    tim[xx][yy]++;
                }
                if (i==1)
                {
                    tim[tmpx+1][tmpy]=tim[xx][yy]+1;
                    x.push(tmpx+1);
                     y.push(tmpy);
                }
                if (i==2&&ok(tmpx,tmpy-1))
                {
                    tim[xx][yy]++;
                }
                if (i==3)
                {
                    tim[tmpx-1][tmpy]=tim[xx][yy]+1;
                    x.push(tmpx-1);
                    y.push(tmpy);
                }

              }
              else
              {
                 if (i==0)
                {
                     tim[tmpx][tmpy+1]=tim[xx][yy]+1;
                    x.push(tmpx);
                    y.push(tmpy+1);
                }
                if (i==1&&ok(tmpx+1,tmpy))
                {
                    tim[xx][yy]++;
                }
                if (i==2)
                {
                     tim[tmpx][tmpy-1]=tim[xx][yy]+1;
                    x.push(tmpx);
                    y.push(tmpy-1);
                }
                if (i==3&&ok(tmpx-1,tmpy))
                {
                    tim[xx][yy]++;
                    vis[xx][yy]=false;
                }
              }
            }
            if (mymap[tmpx][tmpy]=='-')
            {
              if (tim[xx][yy]%2==0)
              {
                if (i==0)
                {
                    tim[tmpx][tmpy+1]=tim[xx][yy]+1;
                    x.push(tmpx);
                    y.push(tmpy+1);
                    vis[tmpx][tmpy+1]=true;

                }
                if ( i==1&&ok(tmpx+1,tmpy))
                {
                    tim[xx][yy]++;

                }
                if (i==2)
                {
                    tim[tmpx][tmpy-1]=tim[xx][yy]+1;
                    x.push(tmpx);
                    y.push(tmpy-1);
                    vis[tmpx][tmpy-1]=true;
                }
                if (i==3&&ok(tmpx-1,tmpy))
                {
                    tim[xx][yy]++;
                }
              }
              else
              {
                if  (i==0&&ok(tmpx,tmpy+1))
                {
                    tim[xx][yy]++;
                }
                if (i==1)
                {
                    tim[tmpx+1][tmpy]=tim[xx][yy]+1;
                    x.push(tmpx+1);
                    y.push(tmpy);
                }
                if (i==2&&ok(tmpx,tmpy-1))
                {
                    tim[xx][yy]++;
                }
                if (i==3)
                {
                    tim[tmpx-1][tmpy]=tim[xx][yy]+1;
                    x.push(tmpx-1);
                    y.push(tmpy);
                }

              }
            }
            if (mymap[tmpx][tmpy]=='.'||mymap[tmpx][tmpy]=='T')
            {
              tim[tmpx][tmpy]=tim[xx][yy]+1;
              x.push(tmpx);
              y.push(tmpy);
            }

        }

        }
  }

}
void init()
{
       getchar();
      for ( int i = 0 ; i < m ; i++ )
      {
        for ( int j = 0 ; j < n ; j++)
        {
              scanf("%c",&mymap[i][j]);
            if (mymap[i][j]=='T')
            {
              tx = i;
              ty = j;
            }
            if (mymap[i][j]=='S')
            {
              sx = i;
              sy = j;
            }

        }
        getchar();
      }
}
int main()
{
    while (scanf("%d %d",&m,&n)!=EOF)
    {
        init();
        bfs();
        cout<<tim[tx][ty]<<endl;

    }

    return 0;
}

