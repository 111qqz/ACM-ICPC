/* ***********************************************
Author :111qqz
Created Time :Fri 23 Sep 2016 05:32:22 PM CST
File Name :code/cf/problem//380C.cpp
************************************************ */
#include <bits/stdc++.h>
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
const int N=1E6+7;
struct node
{
    int left,right,sum;
    node (){}
    node  ( int x,int y,int z): left(x),right(y),sum(z){};
}tree[N<<2];
char st[N];
int n;
void PushUp( int rt)
{
    int add = min(tree[rt<<1].left,tree[rt<<1|1].right);
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum + add;
    tree[rt].left = tree[rt<<1].left + tree[rt<<1|1].left - add;
    tree[rt].right = tree[rt<<1].right + tree[rt<<1|1].right - add;
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	char ch = st[l-1];
	if (ch=='(') tree[rt].left = 1;
	else tree[rt].right = 1;
	return;
    }

    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
node query( int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    node res,res1,res2;
    res = res1 = res2 = node(0,0,0); //初始为0.。。合并的时候和node(0,0,0)不会改变结果。。这样就不用分情况讨论区间了。。。大概。。（？
    if (L<=m) res1 = query(L,R,lson);
    if (R>=m+1) res2 = query(L,R,rson);
    int add = min(res1.left,res2.right);
    res.sum = res1.sum + res2.sum + add;
    res.left = res1.left + res2.left - add;
    res.right = res1.right + res2.right -add;
    return res;
}
int m;
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif


    scanf("%s",st);
    n = strlen(st);
    ms(tree,0);
    build(1,n,1);
    scanf("%d",&m);
    while (m--)
    {
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",query(x,y,1,n,1).sum*2);
    }

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
