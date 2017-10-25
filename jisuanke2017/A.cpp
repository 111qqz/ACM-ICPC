#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 150
#define M 30000
#define INF 0x3f3f3f3f

int n,m,cost,tot;
int L;
struct State
{
   int n,d,c;
   bool operator < (const struct State a)const
   {
      if(a.d == d) return a.c < c;
      return a.d < d;
   }
};
struct edge
{
   int u,v,w,c,next;
};
typedef struct State State;
typedef struct edge edge;
int head[N];
int d[N];
edge e[M];


void add(int u , int v , int w , int c)
{
   e[tot].u = u; e[tot].v = v; e[tot].w = w; e[tot].c = c;
   e[tot].next = head[u]; head[u] = tot++;
}

bool inq[N];
void Dij()
{
    
    memset(inq,false,sizeof(inq));
   priority_queue<State>q;
   State sta;
   int res = INF ;
   memset(d,0x3f,sizeof(d));
   while(!q.empty()) q.pop();
   sta.d = 0;
   sta.n = 1;
   sta.c = 0;
   q.push(sta);
   while(!q.empty())
   {
      State x,y;
      int u,v,w,d,c;

      x = q.top(); q.pop();
      u = x.n; d = x.d;
      cout<<"u:"<<u<<endl;
      if(u == n)
      {
         res = x.d;
         break;
      }

      for(int k=head[u]; k!=-1; k=e[k].next)
      {
         v = e[k].v; w = e[k].w; c = e[k].c;
	 if (inq[v]) continue;
         if(x.c + c <= cost) //在花费允许的范围内可以去到这个点
         {
            y.n = v;  y.d = d + w;  y.c = x.c + c;
            q.push(y);
	    inq[v] = true;
         }
      }
   }
   if(res == INF) printf("-1\n");
   else           printf("%d\n",res);
}
int m1,m2;
int main()

{
    freopen("./in.txt","r",stdin);
   int T;
   cin>>T;
   while (T--)
   {
       scanf("%d %d %d %d",&n,&m1,&m2,&cost);
       tot = 0 ;
      
	memset(head,-1,sizeof(head));
	Dij();
    }
   return 0;
}
