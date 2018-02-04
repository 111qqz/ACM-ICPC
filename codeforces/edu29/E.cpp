/* ***********************************************
Author :111qqz
Created Time :2017年09月25日 星期一 02时57分03秒
File Name :E.cpp
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
struct Node
{
    int l,r;
    int id;
}a[N];
int n;
int ans;
vector<int>ret;
bool cmp( Node x, Node y)
{
    if (x.l==y.l) return x.r>y.r;
    return x.l<y.l;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i =  1 ; i <= n ; i++) 
	{
	    scanf("%d %d",&a[i].l,&a[i].r);
	    a[i].id = i;
	}
	sort(a+1,a+n+1,cmp);
	ans = 0 ;
	int mxR=-1;
	int lsR=-1;
	for ( int i = 1 ; i <= n ; i++)
	{
	    //puts("miao");
	    if (i>=3) lsR=a[i-2].r;
	    if (a[i].r<=mxR)
	    {
		ans++;
		ret.push_back(a[i].id);
	    }
	    else if (a[i].l>=mxR+1) //先考虑最easy的2个情况.
	    {
		mxR=max(mxR,a[i].r);
	    }else if (lsR!=-1&&a[i].l<=lsR+1&&a[i].r)
	    {
		ans++;
		ret.push_back(a[i-1].id);
	    }

	    mxR = max(mxR,a[i].r);
	}
	if (ans==0) ans=-1;
	else ans = ret[0];
	printf("%d\n",ans);


	    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
