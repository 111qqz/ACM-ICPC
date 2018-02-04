#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
#define N 1005
#define M 100000
using namespace std;
int n,m,C,D,K;
int edges[N][N];
int d[N];
void SPFA(int s) 
{
    for(int i=1;i<=n;i++)
 {
        d[i] = 0x3f3f3f3f;
    }
 int queue[N*N] = {0};
 bool visit[N] = {false};
    int front = 0, rear = 1;
 //int path[N];
    queue[front] = s;
 visit[s] = true; 
 d[s] = 0;
    while(front<rear)
 {   
        int u = queue[front];
        visit[u] = false;
        for(int i=1; i<=n; i++)
  {
            if (d[i]>d[u]+ edges[u][i])
   {
                d[i]= d[u]+edges[u][i];
                //path[i] = u;
                if( !visit[i] )
    {
                    visit[i] = true;
                    queue[rear++] = i;
                }
            }
  }
  front++;
    }
}

int main()
{

    freopen("code/in.txt","r",stdin);
    while (~scanf("%d %d %d %d %d",&n,&m,&C,&D,&K))
    {
	memset(edges,0x3f,sizeof(edges));
	for ( int i = 0 ; i < m ; i++)
	{
	    int u,v,w;
	    scanf("%d %d %d",&u,&v,&w);
	    if (u==v) continue;
	    if (w<edges[u][v]) edges[u][v] = w;
	}
	SPFA(C);
	if (d[D]>K)
	{
	    puts("Sorry");
	}
	else 
	{
	    printf("%d\n",d[D]);
	}


    }
}
