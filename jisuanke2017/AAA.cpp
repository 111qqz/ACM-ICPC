/*两个约束条件求最短路，用优先队列*/  
#include<stdio.h>  
#include<string.h>  
#include<queue>  
using namespace std;  
#define N  110  
struct node {  
int u,v,w,f,next;  
}bian[N*N*4];  
int head[N],yong,money;  
void init() {  
memset(head,-1,sizeof(head));  
yong=0;  
}  
struct nodee{  
  int len,w,v;  
  friend bool operator<(nodee a,nodee b) {  
      if(a.len==b.len)//在路程相同时，优先选择花费金钱最少的  
        return a.w>b.w;  
      return  a.len>b.len;  
  }  
};  
void add(int u,int v,int w,int f) {  
bian[yong].u=u;  
bian[yong].v=v;  
bian[yong].w=w;  
bian[yong].f=f;  
bian[yong].next=head[u];  
head[u]=yong++;  
}  
int min_len(int s,int t) {  
 priority_queue<nodee>q;  
  int visit[N],i;  
  memset(visit,0,sizeof(visit));  
  nodee cur,next;  
  cur.len=0;  
  cur.w=0;  
  cur.v=s;  
  q.push(cur);  
  while(!q.empty()) {  
    cur=q.top();  
    visit[cur.v]=1;  
    q.pop();  
    if(cur.v==t)  
        return cur.len;  
    for(i=head[cur.v];i!=-1;i=bian[i].next) {  
          int v=bian[i].v;  
            next.len=cur.len+bian[i].w;  
            next.w=cur.w+bian[i].f;  
            next.v=v;  
            if(next.w<=money)  
                q.push(next);  
    }  
  }  
  return  -1;  
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
       while (m1--)
       {
	   int a,b;
	    scanf("%d %d",&a,&b);
	    add(a,b,0,1);
	    add(b,a,0,1);
	}
       while (m2--)
	{
	    int u,v,c;
	    scanf("%d %d %d",&u,&v,&c);
	    add(u,v,c,c);
	    add(v,u,c,c);
	}
	memset(head,-1,sizeof(head));
	min_len(1,n);
    }
   return 0;
}

