/* ***********************************************
Author: SnowyJune
Created Time :2017年10月08日 星期日 14时03分17秒
File Name :G.cpp
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
#define lson(x) (x<<1)
#define rson(x) ((x<<1)|1) 
#define ms(a,x) memset(a,x,sizeof(a))
#define prev ___prev
typedef long long LL;
#define pi pair < int ,int >
#define MP make_pair
#define pin(x) (2*x-1)
#define pout(x) (2*x)
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;
const double DINF = 1e40;
const double eps = 1e-6;
const int maxn = 510;
const int maxm = 5e4+10;
int si[205],bi[205];
int nume,n,m,lmt,src,sink;
int g[maxn];
int dblcmp(double d)
{
    return d<-eps?-1:d>eps;
}
struct Edge{
	int v,f,nxt;
	double w;
	Edge(){};
	Edge(int a,int b,double c,int d){
		v = a;
		f = b;
		w = c;
		nxt = d;
	}
}e[maxm];

void addedge(int u,int v,int c,double w){
	++nume;
	e[nume] = Edge(v,c,w,g[u]);
	g[u] = nume;
	++nume;
	e[nume] = Edge(u,0,-w,g[v]);
	g[v] = nume;
}

queue<int> que;
bool inQue[maxn];
double dist[maxn];
int prev[maxn],pree[maxn];

bool findPath(){
	while(!que.empty())que.pop();
	que.push(src);
	for(int i = 0; i < maxn; i++)dist[i] = DINF;
	memset(inQue,0,sizeof(inQue));
	inQue[src] = true;
	dist[src] = 0;
	while(!que.empty()){
		int u = que.front();
		que.pop();
		for(int i = g[u];i;i = e[i].nxt){
			if(e[i].f > 0 && dist[u] + e[i].w +eps< dist[e[i].v]){
				dist[e[i].v] = dist[u] + e[i].w;
				prev[e[i].v] = u;
				pree[e[i].v] = i;
				if(!inQue[e[i].v]){
					inQue[e[i].v] = true;
					que.push(e[i].v);
				}
	//			printf("Relax: %d -> %d: Ei = %d, distv = %.6f\n",u,e[i].v,i,dist[e[i].v]);
			}
		}
		inQue[u] = false;
	}
	if (dblcmp(dist[sink]-DINF)<0)
	//if(dist[sink] < DINF-eps)return true;
	else return false;
}

void printgraph(){
	for(int i = 0; i <= 2*n+1; i++){
		printf("G[%d] = %d\n",i,g[i]);
	}
	for(int i = 1; i <= nume; i++){
		printf("E[%d] = (V = %d, Flow = %d, Cost = %.6f, Gi = %d)\n",i,e[i].v,e[i].f,e[i].w,e[i].nxt);
	}
}
double augment(){
	int u = sink;
	int delta = INF;
	//printf("DIST.SINK = %.6f\n",dist[sink]);
//	printgraph();
	while(u != src){
	//	printf("U = %d, Pree = %d, Prev = %d\n", u,pree[u],prev[u]);
		if(e[pree[u]].f < delta) delta = e[pree[u]].f;
		u = prev[u];
	}
	u = sink;
	while(u!=src){
		e[pree[u]].f -= delta;
		e[pree[u]^1].f += delta;
		u = prev[u];
	}
	return dist[sink] * delta;
}
// -ln(1-p) = sum(ji*(-ln(i-pi))) min.
double mincostflow(){
	double cur = 0, ans = 0;
	while(findPath()){
	//	puts("NYAN");
		cur += augment();
	//	printf("****************");
	//	printf("cur = %.6f\n",cur);
	//	printf("******************");
		if(cur > ans) ans = cur;
	}
	return ans;
}

double solve(){
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	memset(e,0,sizeof(e));
	src = 0;
	sink = 2*n+1;
	nume = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&si[i],&bi[i]);
		addedge(src,pin(i),si[i],0);
		addedge(pout(i),sink,bi[i],0);
	}
	int ui,vi,ci;
	double p;
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d%lf",&ui,&vi,&ci,&p);
		addedge(pin(ui),pout(vi),1,0);
		addedge(pin(ui),pout(vi),ci,-log(1.0-p));
	}
//	printgraph();
	return 1.0-exp(-mincostflow());
}
int main(){
#ifdef SNOWYJUNE 
	freopen("input","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		printf("%.2f\n",solve());
	}
#ifdef SNOWYJUNE
	fclose(stdin);
#endif
    return 0;
}
