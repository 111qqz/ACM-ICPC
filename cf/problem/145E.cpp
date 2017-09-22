/* ***********************************************
Author :111qqz
Created Time :Tue 27 Sep 2016 09:14:22 AM CST
File Name :code/cf/problem/145E.cpp
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
const int N = 1E6+7;
int n,m;
char st[N];
struct node
{
    int c7,c4,c47,c74;
    bool flip;
    void out()
    {
	printf("c4:%d c7: %d c47 :%d c74 : %d\n",c4,c7,c47,c74);
    }
}tree[N<<2];
void PushUp( int rt)
{
    tree[rt].c4 = tree[rt<<1].c4 + tree[rt<<1|1].c4;
    tree[rt].c7 = tree[rt<<1].c7 + tree[rt<<1|1].c7;
    tree[rt].c47 = max(tree[rt<<1].c4 + tree[rt<<1|1].c47 , tree[rt<<1].c47 + tree[rt<<1|1].c7);
    tree[rt].c74 = max(tree[rt<<1].c7 + tree[rt<<1|1].c74, tree[rt<<1].c74 + tree[rt<<1|1].c4);
}
void build( int l,int r ,int rt)
{
    if (l==r)
    {
	if (st[l-1]=='4') tree[rt].c4 = 1;
	else tree[rt].c7 = 1;
	tree[rt].c47 = tree[rt].c74 = 1;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void Flip( int rt)
{
    tree[rt].flip^=1;
    swap(tree[rt].c4,tree[rt].c7);
    swap(tree[rt].c47,tree[rt].c74);
}
void PushDown( int rt)
{
    if (tree[rt].flip)
    {
	Flip(rt<<1);
	Flip(rt<<1|1);
	tree[rt].flip = 0 ;
    }
}
void update(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R)
    {
	Flip(rt);
	return;
    }
    PushDown(rt);
    int m = (l+r)>>1;
    if (L<=m) update(L,R,lson);
    if (R>=m+1)  update(L,R,rson);
    PushUp(rt);
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    scanf("%s",st);
    build(1,n,1);
    while (m--)
    {
	char opt[10];
	scanf("%s",opt);
	//  cout<<"opt:"<<opt<<endl;
	if (opt[0]=='c')
	{
	    printf("%d\n",tree[1].c47);
	}
	else
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    update(x,y,1,n,1);
	}
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
