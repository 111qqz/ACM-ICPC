/* ***********************************************
Author :111qqz
Created Time :2016年05月25日 星期三 00时25分51秒
File Name :code/poj/2949.cpp
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
#include <stack>
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
const int N=1E5+7;
char st[1005];
int f[900];
bool ins[900];//是否在栈中
double dis[900];
int in[900]; //进栈次数，用来判断环。
double maxedge; // d[i]>n*maxegde 可以认定必然有环。 这剪枝真的有效果。。？

struct edge
{
    int v,nxt;
    double w;
}edge[N];
int n;
int tot;
int cnt;//点的个数。
int head[N];

void addedge(int u,int v,double w)
{
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}

bool spfa(double ave,int n)
{

    ms(in,0);
    ms(ins,false);
    ms(dis,0);
    stack<int>S;
    for ( int i = 1 ; i <= n ; i++) S.push(i),ins[i] = true;
//    cout<<"whhhhh?"<<endl; 
    while (!S.empty())
    {
	int u = S.top();
//	cout<<"u:"<<u<<endl;
	S.pop();
	ins[u]=false;

	for ( int i = head[u] ; i!=-1 ; i = edge[i].nxt)
	{
//	    cout<<"end of for?"<<endl;
	    int v = edge[i].v;
	    if (dis[v]<dis[u]+(edge[i].w-ave))
	    {
		dis[v] = dis[u] +  (edge[i].w-ave);
		if (dis[v]>maxedge*n) return true;
		if (ins[v]) continue;
		ins[v] = true;
		S.push(v);
		in[v]++;
		if (in[v]>n)
		{
		    return true; //有环。
		}
	    }
	}
    }

  //  cout<<"end of spfa:"<<endl;

    return false;

}

void bin()
{
    double l = 0,r=1000,best=-1,mid;
    while (l+0.001<=r)
    {
//	cout<<"sadasd"<<endl;
	mid = (l+r)/2;
	if (spfa(mid,cnt))
	{
	    best = mid;
	    l = mid;
	}
	else r = mid;
    }
    if (best!=-1) printf("%.2lf\n",best);
    else puts("No solution.");
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	while (scanf("%d",&n)!=EOF)
	{
	    if (n==0) break;
	    ms(f,0);
	    ms(head,-1); //总是忘记这个初始化....
	    cnt = 0;
	    tot = 0 ;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		scanf("%s",st);
		int len =  strlen(st);
		if (len>maxedge)
		{
		    maxedge = len;
		}

		int x = (st[0]-'a')*26 + st[1]-'a';
		int y = (st[len-2]-'a')*26 + st[len-1]-'a';
		if (f[x]==0) f[x] = ++cnt;
		if (f[y]==0) f[y] = ++cnt;

		int u = f[x];
		int v = f[y];

		addedge(u,v,double(len));
	    }
	    

	   bin();
	//    cout<<"asdasd"<<endl;
	}

    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
