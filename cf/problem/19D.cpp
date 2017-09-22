/* ***********************************************
Author :111qqz
Created Time :Sun 04 Sep 2016 07:19:05 PM CST
File Name :code/cf/problem/19D.cpp
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
const int N=2E5+7;
int n,m;
int tree[N<<2]; //记录线段树的信息，tree[i]表示的是以i节点为根节点的子树所代表的区间中的点的最大的y值。
set<int>se[N];//集合se[i]是横坐标为x的点的纵坐标的集合。
struct node   //线段树套平衡树，在x轴的方向上建一棵线段树，线段树的每个叶子节点是一个set。
{
    int x,y;
    char cmd[15];
    void input()
    {
	scanf("%s%d%d",cmd,&x,&y);
    }
}q[N];
int H[N];
void PushUp(int rt)
{
    tree[rt] = max(tree[rt<<1],tree[rt<<1|1]);
}
void update( int p,int l,int r,int rt)
{
    if (l==r)
    {
	if (se[l].size())
	    tree[rt] =*(--se[l].end()); //se.end()是指向最后一个元素之后的， *(--se[l].end())只是取了se[l]集合的最后一个元素而已
	else tree[rt] = -1;
	return ;
    }
    int m = (l+r)>>1;
    if (p<=m)
	update(p,lson);
    else update(p,rson);
    PushUp(rt);
}
int query(int L,int R,int val,int l,int r,int rt)//返回集合中存在大于val(y)的集合中标号最小的集合的标号（x)
{
    if (tree[rt]<=val||L>R) return -1;//由于题目要求严格大于，因此查询区间是从h+1到m，当h恰好等于m的时候，L>R，记得判断。
    if (l==r) return l;
    int m = (l+r)>>1;
    int ret = -1;
    if (L<=m)
	ret = query(L,R,val,lson);
    if (ret!=-1)
	return ret;
    if (R>=m+1)
	return query(L,R,val,rson);
}
int Hash( int x)
{
    return lower_bound(H,H+m,x)-H;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	m = n;
	for ( int i = 0 ; i < n ; i++) q[i].input(),H[i] = q[i].x;
	sort(H,H+m); // 离散化
	m = unique(H,H+m)-H;//离散化
	ms(tree,-1);//初始化最大值。
	for ( int i = 0 ; i <  n;  i++)
	{
	    int h = Hash(q[i].x)+1;//离散化
	    if (q[i].cmd[0]=='a')
		se[h].insert(q[i].y),update(h,1,m,1);
	    else if (q[i].cmd[0]=='r')
		se[h].erase(q[i].y),update(h,1,m,1);
	    else 
	    {
		int p = query(h+1,m,q[i].y,1,m,1);//x已经是升序了，从h+1开始的区间寻找可以保证x严格大于，此时只需要在[h+1,m]区间找一个严格大于y的点。
	        if (p==-1)
		    puts("-1");
		else printf("%d %d\n",H[p-1],*se[p].upper_bound(q[i].y)); //由于当x相同时要找y最小的那个，因此最后还要upper_bound找到第一个比q[i].y大的y。
		//下标问题。。只是因为H的下标是从0开始的。。set的下标是从1开始的。。。H下标从0开始离散化会看着舒服一点。。。
	    }
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
