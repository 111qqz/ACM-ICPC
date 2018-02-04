/* ***********************************************
Author :111qqz
Created Time :Mon 05 Sep 2016 12:56:34 AM CST
File Name :code/cf/problem/339D.cpp
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
const int N=1<<18;
int tree[N<<2];
int n,m;
void PushUp(int rt,int state)
{
    if (state==-1)
	tree[rt] = tree[rt<<1]|tree[rt<<1|1];
    else tree[rt] = tree[rt<<1]^tree[rt<<1|1];
}
void build(int l,int r,int rt,int state)
{
    if (l==r)
    {
	scanf("%d",&tree[rt]);
	return ;
    }
    int m = (l+r)>>1;
    build(lson,-state);
    build(rson,-state);
    PushUp(rt,state);
}
void update( int p,int sc,int l,int r,int rt,int state)
{
    if (l==r)
    {
	tree[rt] = sc;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,sc,lson,-state);
    else update(p,sc,rson,-state);
    PushUp(rt,state);
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int state;
	cin>>n>>m;
	if (n%2==0) state = 1; //n是树的高度，最后的操作是异或还是或和树的高度的奇偶性有关。
	else state = -1;
	n = 1<<n;
	build(1,n,1,state);
	while (m--)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    update(x,y,1,n,1,state);
	    printf("%d\n",tree[1]);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
