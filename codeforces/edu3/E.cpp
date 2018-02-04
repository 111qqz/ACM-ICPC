/* ***********************************************
Author :111qqz
Created Time :2015年12月20日 星期日 00时02分02秒
File Name :code/cf/edu3/E.cpp
************************************************ */

//本程序用到了并查集的基本操作，不会并查集的请自行学习或参考本代码学习
//getfa为查询祖先，merge为将集合合并，same是判断两个点是否处于同一集合
//getfa操作中使用了路径压缩即return fa[x] = getfa(fa[x])，这样可以减小并查集森林退化所带来的时间复杂度
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN_E 200005
#define MAXN_V 200005
using namespace std;
struct Edge{
    int fm,to,dist;
    int id;
}e[MAXN_E];
int fa[MAXN_V],n,m;
int ans[MAXN_V];
bool cmp(Edge a,Edge b){
    return a.dist < b.dist;
}
int getfa(int x){//getfa是在并查集森林中找到x的祖先
    if(fa[x]==x) return fa[x];
    else return fa[x] = getfa(fa[x]);
}
int same(int x,int y){
    return getfa(x)==getfa(y);
}
void merge(int x,int y){

    int fax=getfa(x),fay=getfa(y);
    fa[fax]=fay;
}

void init()
{
     for ( int i = 1 ; i <= n ; i++)
	 fa[i] = i;
}
int main(){

    freopen("code/in.txt","r",stdin);
    scanf("%d%d",&n,&m);//n为点数，m为边数
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=m;i++)
    scanf("%d%d%d",&e[i].fm,&e[i].to,&e[i].dist);//用边集数组存放边，方便排序和调用
    for ( int i = 1 ; i <= m ; i++) e[i].id = i;
    sort(e+1,e+m+1,cmp);//对边按边权进行升序排序
    for ( int t = 1 ; t <= m ; t++){
	int xx = e[t].fm;
	int yy = e[t].to;
	int rst = n ;
	//int ans = 0;
	init();
	merge(xx,yy);
	rst--;
	ans[e[t].id]+=e[t].dist;
	//rst表示目前的点共存在于多少个集合中，初始情况是每个点都在不同的集合中
	for(int i=1;i<=m && rst>1;i++)
	{
	    if (i==t) continue;
	    int x=e[i].fm,y=e[i].to;
	    if(same(x,y)) continue;//same函数是查询两个点是否在同一集合中
	    else
	    {
		merge(x,y);//merge函数用来将两个点合并到同一集合中
		rst--;//每次将两个不同集合中的点合并，都将使rst值减1
		ans[e[t].id]+=e[i].dist;//这条边是最小生成树中的边，将答案加上边权
	    }
	}
	//printf("%d\n",ans);
    }
    for ( int i = 1 ;i <= m ; i++)
	printf("%d\n",ans[i]);
    return 0 ;
}
