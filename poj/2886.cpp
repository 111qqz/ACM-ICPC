/* ***********************************************
Author :111qqz
Created Time :Wed 21 Sep 2016 09:19:11 PM CST
File Name :code/poj/2886.cpp
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
const int N=5E5+7;
int tree[N<<2];
int n,k;
char nam[N][11];
int val[N];
int s[40] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,500001};   
int b[40] = {1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200};  
void PushUp( int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt] = 1;
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int update( int p,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]--;
	return l;
    }
    int m = (l+r)>>1;
    int ret;
    if (p<=tree[rt<<1]) ret = update(p,lson);
    else ret = update(p-tree[rt<<1],rson);
    PushUp(rt);
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (~scanf("%d%d",&n,&k))
	{
	    ms(tree,0);
	    for ( int i = 1 ;i <= n ; i++) scanf("%s%d",nam[i],&val[i]);
	    build(1,n,1);
	    int id = upper_bound(s,s+40,n)-s-1; 
	    int m = s[id];
	    int ans = b[id];
	    int num = n; //剩余人数
	    int pos;
	    for ( int i = 0 ; i < m ; i++)
	    {
		num--;
		pos = update(k,1,n,1);
		if (num==0) break;
		if (val[pos]>=0) k = (k-1-1+val[pos])%num+1; //先-1变成0based，最后+1变回1_based.
		else k = ((k-1+val[pos])%num+num)%num+1;
	    }
	    printf("%s %d\n",nam[pos],ans);
	}
    return 0;
}
