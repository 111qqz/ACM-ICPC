/* ***********************************************
Author :111qqz
Created Time :2016年05月24日 星期二 20时03分37秒
File Name :code/poj/1932.cpp
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
const int N=105;

vector< int > edge[N];
int a[N];
bool conc[N][N];
int in[N]; //统计入队次数，大于n次表明有环。
bool inq[N];
int n;
int d[N];
void floyd() //传递闭包
{
    for ( int k = 1 ; k <= n ; k++)
	for ( int i = 1 ; i <= n ; i++)
	    for ( int j = 1 ; j <= n ; j++)
		if (conc[i][k]&&conc[k][j]) conc[i][j] = true;
}
bool spfa(int s)  //spfa求最长路。
{
    ms(in,0);
    ms(d,0);//因为小于等于0就死，所以初始是0，这样更新的时候一定是正值才更新。
    ms(inq,false);
    queue<int>q;
    q.push(s);
    inq[s] = true;
    d[s] =  100;
    in[s]++;

    while (!q.empty())
    {
	int u = q.front();
	q.pop();
	inq[u]=false;

	int siz = edge[u].size();
	if (in[u]>n) break; //有环
	for ( int i = 0 ; i < siz ; i++)
	{
	    int v = edge[u][i];
	//    cout<<"v:"<<v<<" d[u]:"<<d[u]<<" a[v]:"<<a[v]<<endl;
	    if (d[v]<d[u]+a[v])
	    {
		d[v] = d[u] + a[v];
		if (inq[v]) continue;
		inq[v] = true;
		q.push(v);
		in[v]++;
	    }
	}
    }
  //  cout<<"d[n]:"<<d[n]<<endl;
    if (d[n]>0) return true; //不会存在中间有非正最后为正的情况，因为初始值为0，中间为0或者负不会更新。
                             // d[n]也只有0和大于0两种可能。
    
    floyd();

    for ( int i = 1 ; i <= n ; i++)   //如果有正环并且环上的某点可以联通1和n那么也有解。只要跑足够次就可以把eng变得足够大
	if (in[i]>n&&conc[1][i]&&conc[i][n]) return true;

    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    ms(conc,false);
	    if (n==-1) break;
	    for ( int i = 0 ; i <= n ; i++) edge[i].clear();
	    ms(conc,false);
	    for ( int i = 1 ; i <=  n ; i++)
	    {
		scanf("%d",&a[i]);
		int num;
		scanf("%d",&num);
		while (num--)
		{
		    int x;
		    scanf("%d",&x);
		    edge[i].push_back(x);
		    conc[i][x] = true;
		}
	    }

	    if (spfa(1))
		puts("winnable");
	    else puts("hopeless");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
