/* ***********************************************
Author :111qqz
Created Time :2016年05月10日 星期二 19时31分31秒
File Name :code/bzoj/1664.cpp
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
const int N=1E4+7;
int n;
struct node
{
    int l,r;
    bool operator < (node b)const
    {
	return r<b.r;
    }
}a[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++) scanf("%d %d",&a[i].l,&a[i].r),a[i].r+=a[i].l;
	sort(a+1,a+n+1);


	int ans =  1;
	int lst = a[1].r;
	for (int i = 2 ; i <= n ; i++)
	{
	    if (a[i].l>=lst)
	    {
		ans++;
		lst = a[i].r;
	    }
	
	}

	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
