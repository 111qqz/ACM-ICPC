#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
const int inf = 8E8;
const int N=3E2+7;
int T,l,x1,yy1,x2,y2;
int d[N][N];
bool ok(int xxx,int yyy)
{
    if (xxx>=0&&xxx<=l-1&&yyy>=0&&yyy<=l-1&&d[xxx][yyy]==-1)
        return true;
    return false;
}

void bfs()
{
    memset(d,-1,sizeof(d));
    d[x1][yy1]=0;
    queue<int> x;
    queue<int> y;
    x.push(x1);
    y.push(yy1);
    while (!x.empty()&&!y.empty())
    {
        int xx=x.front();
        int yy=y.front();
        x.pop();
        y.pop();
        if (xx==x2&&yy==y2) break;
        int nextx[10]={-1,-2,-2,-1,1,2,2,1};
        int nexty[10]={2,1,-1,-2,-2,-1,1,2};
        for ( int i = 0 ; i < 8 ; i++ )
        {
             int tmpx=xx+nextx[i];
             int tmpy=yy+nexty[i];
             if (ok(tmpx,tmpy))
             {
                 d[tmpx][tmpy]=d[xx][yy]+1;
                 x.push(tmpx);
                 y.push(tmpy);
             }
        }

    }
}
int main()
{
    cin>>T;
    while (T--)
    {
        cin>>l;
        cin>>x1>>yy1;
        cin>>x2>>y2;
        bfs();
        cout<<d[x2][y2]<<endl;


    }


	return 0;
}
