/* ***********************************************
Author :111qqz
Created Time :Mon 05 Sep 2016 03:40:20 PM CST
File Name :code/cf/problem/61E.cpp
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
int a[N];
int A[N];
int H[N];
int n;
int m;
int tree1[N<<2],tree2[N<<2];
pair<LL,LL>ans[N];
void PushUp(int rt,int *tree)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}
void update(int p,int l,int r,int rt,int *tree)
{
    if (l==r)
    {
	tree[rt]++;
	return;
    }
    int m = (l+r)>>1;
    if (p<=m) update(p,lson,tree);
    else update(p,rson,tree);
    PushUp(rt,tree);
}
int query(int L,int R,int l,int r,int rt,int *tree)
{
//    cout<<"L:"<<L<<" R:"<<R<<" l:"<<l<<" r:"<<r<<" rt:"<<rt<<endl;
    if (L>R) return 0; 
    if (L<=l&&r<=R) return tree[rt];
    int m = (l+r)>>1;
    int ret = 0 ;
    if (L<=m)
    {
	int res = query(L,R,lson,tree);
	ret+=res;
    }
    if (R>=m+1)
    {
	int res =  query(L,R,rson,tree);
	ret +=res;
    }
    return ret;
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
	for ( int i = 0 ; i < n ; i++)
	{
	    scanf("%d",&a[i]);
	    H[i] = a[i];
	}
	sort(H,H+m);
	m = unique(H,H+m)-H;
	int mx = 0 ;
	for ( int i = 0 ; i < n ; i++) A[i] = Hash(a[i])+1,mx = max(mx,A[i]);
    
//	for ( int i = 0 ; i < n ; i++) cout<<"A[i]:"<<A[i]<<endl;
	ms(tree1,0);
	ms(tree2,0);
	for ( int i = n-1 ; i >=0 ; i--)
	{
	    LL tmp = LL(query(1,A[i]-1,1,mx,1,tree1));
//	    cout<<"tmp:"<<tmp<<endl;
	    ans[i].fst = tmp;
	    update(A[i],1,mx,1,tree1);
	}
//	for ( int i = 0 ; i < n ; i++) cout<<ans[i].fst<<" ";
	
	for ( int i =  0 ; i < n ; i++)
	{
	    LL tmp = LL(query(A[i]+1,mx,1,mx,1,tree2));
	    ans[i].sec = tmp;
	    update(A[i],1,mx,1,tree2);
	}
//	for ( int i = 0 ; i < n ; i++) cout<<ans[i].sec<<" ";

	LL res = 0LL;
	for ( int i = 0 ; i < n ; i++) res = res + ans[i].fst*ans[i].sec;
	cout<<res<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
