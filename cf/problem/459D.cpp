/* ***********************************************
Author :111qqz
Created Time :Mon 05 Sep 2016 02:06:05 PM CST
File Name :code/cf/problem/459D.cpp
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
const int N=1E6+7;
map<int,int>mp;
int n ;
int a[N],b[N];
int tmp[N];
int tree[N<<2];//tree[i]表示的是以i节点为根节点的子树所代表的区间中数的个数。
void PushUp( int rt)
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
    int ret = 0;
    if (L<=m)
    {
	int res  = query(L,R,lson);
	ret +=res;
    }
    if (R>=m+1)
    {
	int res = query(L,R,rson);
	ret +=res;
    }
    return ret;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	mp.clear();
	int mx = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    int x;
	    scanf("%d",&x);
	    tmp[i] = x;
	    if (!mp[x]) mp[x] = 2;  //mp表示的是出现的次数。。。是从0开始，但是线段树下标从1开始，因此整体+1,也就是第一次出现的时候设为2.
	    else mp[x]++;
	    a[i] = mp[x];
	    mx = max(mx,a[i]);
	}
	mp.clear();
	for ( int i = n ;  i >= 1;  i--)
	{
	    int x = tmp[i];
	    if (!mp[x]) mp[x] = 2;
	    else mp[x]++;
	    b[i] = mp[x];
	}
	ms(tree,0);
	LL ans = 0 ;
	for ( int i = n ; i >=1 ; i--)
	{
	    ans = ans + LL(query(1,a[i]-1,1,mx,1));//查询在在a[i]之前插入的（下标比i大）且比a[i]小（因此查询区间是1..a[i]-1)的数的个数。
	    update(b[i],1,mx,1); //在b[i]位置插入一个数。
	}
	cout<<ans<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
