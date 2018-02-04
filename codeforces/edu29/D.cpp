/* ***********************************************
Author :111qqz
Created Time :2017年09月25日 星期一 05时19分52秒
File Name :D.cpp
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
#define PB push_back
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
int n,q,m;
int a[N];
int b[105];
struct Node
{
    int opt,x,y;
}qu[N];
/* 思路：
 * 对于所有操作进行完，b[i]位置上的数是多少，
 * 因为所有的数只是位置改变，大小没有改变
 * 我们想要还原，到最后的b[i]位置，应该对应的是初始序列中的哪个位置。
 * 如果当前位置是pos,那么在进行上一个反转操作之前的位置就是(L+R)-pos,
 * 进行上一个移位操作的位置就是pos-1(注意边界）
 */
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n>>q>>m;
	for ( int i = 1;  i <= n ; i++) scanf("%d",&a[i]);
	for ( int i = 1 ; i <= q ; i++) scanf("%d%d%d",&qu[i].opt,&qu[i].x,&qu[i].y);
	for ( int i = 1 ; i <= m ; i++) scanf("%d",&b[i]);
	

	for ( int i = q ; i >= 1 ; i--)
	{
	    int opt = qu[i].opt;
	    int L = qu[i].x;
	    int R = qu[i].y;
	    if (opt==1)
	    {
		for ( int j = 1 ; j <= m ; j++)
		{
		    if (b[j]>=L&&b[j]<=R)
		    {
			if (b[j]-1>=L)
			b[j] = b[j]-1;
			else b[j] = R;
		    }
		}
	    }
	    else
	    {
		for ( int j = 1 ; j <= m  ;j++)
		{
		    if (b[j]>=L&&b[j]<=R)
		    {
			b[j] = R+L-b[j];
		    }
		}
	    }
	}
	    for ( int i = 1 ; i <= m ; i++)
		printf("%d ",a[b[i]]);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
