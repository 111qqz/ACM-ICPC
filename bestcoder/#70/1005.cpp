/* ***********************************************
Author :111qqz
Created Time :2016年01月30日 星期六 20时12分50秒
File Name :code/bc/#70/1005.cpp
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

const int N=3E3+7;

int w[35][N];
int lx[35],ly[N];
int linky[N];
int visx[35],visy[N];
int slack[N];
int nx,ny;
int n,m;

bool find(int x)
{
    visx[x]=1;
    for(int y=1;y<=ny;y++)
    {
        if(visy[y]) continue;
        int t=lx[x]+ly[y]-w[x][y];
        if(t==0)
        {
            visy[y]=1;
            if(linky[y] ==-1 || find(linky[y]))
            {
                linky[y]=x;
                return true;//找到增广路
            }
        }
        else if(slack[y] > t)
            slack[y]=t;
    }
    return false;
}

int KM()
{
    ms(linky,-1);
    ms(ly,0);
    for(int i=1;i<=nx;i++)
    {
        lx[i]=-inf;
        for(int j=1;j<=ny;j++)
            if(w[i][j] >lx[i])
                lx[i]=w[i][j];
    }
    for(int x=1;x<=nx;x++)
    {
        for(int i=1;i<=ny;i++)
            slack[i]=inf;
        while(1)
        {
	    ms(visx,0);
	    ms(visy,0);
            if(find(x)) break;
            int d=inf;
            for(int i=1;i<=ny;i++)
                if(!visy[i] && d>slack[i])
                    d=slack[i];
            for(int i=1;i<=nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(int i=1;i<=ny;i++)
                if(visy[i])
                    ly[i]+=d;
                else
                    slack[i]-=d;
        }
    }
    int ans=0;
    for(int i=1;i<=ny;i++)
        if(linky[i] >-1)
            ans+=w[linky[i]][i];
    return -ans;
}

void init()
{
    scanf("%d%d",&m,&n);
    nx=n;
    ny=n*m;
    int cost;
    for(int i=1;i<=n;i++)
    {
        int cnt=1;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&cost);
            for(int k=1;k<=n;k++)
            {
                w[i][cnt++]=-cost*k;
            }
        }
    }
}

int main()
{
  //  freopen("code/in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        init();
        
	printf("%d\n",KM());
	
    }
    return 0;
}
