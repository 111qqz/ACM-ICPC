/* ***********************************************
Author :111qqz
Created Time :Tue 13 Sep 2016 04:33:55 PM CST
File Name :code/cf/problem/501D.cpp
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
int n ;
int tree[N<<2];
int fac[N];
int A[N],B[N];
int ans[N];
void PushUp(int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update(int p,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]++;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,lson);
    else update(p,rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m)
    {
	int res = query(L,R,lson);
	ret +=res;
    }
    if (R>=m+1)
    {
	int res = query(L,R,rson);
	ret +=res;
    }
    return ret;
}
void Contor(int A[])//https://en.wikipedia.org/wiki/Factorial_number_system 
{
    ms(tree,0);
    for ( int i = 0 ; i < n ; i++)
    {
	int x;
	scanf("%d",&x);
	x++;
	A[n-i-1] = x-query(1,x,1,n,1)-1; //A[i]位置是factorial_number_system所表示的高精度，整个A数组表示contor展开的答案（也就是字典序第几大），具体参考上面的链接。
	update(x,1,n,1);
    }
}
void print(int *a,int n)
{
    for ( int i =  0; i <  n ; i++ ) printf("%d ",a[i]);
    printf("\n");
}
void build( int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]  = 1; //第二棵线段树。。。表示的是空位置的个数。。。初始每个节点都为空，所以都为1.
	return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int update2( int x,int l,int r,int rt)
{
    if (l==r)
    {
	tree[rt]--;
	return l;
    }
    int m = (l+r)/2;
    int ret ; //又犯了。。。递归多层只由最后一层返回结果的错误2333，
    if (x<=tree[rt<<1]) ret = update2(x,lson);
    else ret =update2(x-tree[rt<<1],rson);
    PushUp(rt);
    return ret;
}

void ni_Contor()
{
    build(1,n,1);
    A[0] = 0 ;
    for ( int i = n -1 ; i>= 0 ; i--)
    {
	int x  =update2(A[i]+1,1,n,1)-1;
	printf("%d%c",x,i==0?'\n':' ');
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	Contor(A); //读入排列p并且将其康托展开，然后按照factorial_number_system存入A数组。
	Contor(B);
//	print(A,n);
//	print(B,n);
	int tmp = 0 ;
	for ( int i = 1 ; i < n ; i++) //
	{
	    A[i]+=B[i]+tmp;   //这部分就是在factorial_number_system下求A和B两个数的和%n!...只不过是每一步分别算了。。。
	    tmp = A[i]/(i+1);
	    A[i]-=tmp*(i+1);  //处理了高精度的进位和%运算。
	}
//	print(A,n);
	ni_Contor();

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
