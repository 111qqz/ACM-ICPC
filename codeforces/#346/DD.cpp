/* ***********************************************
Author :111qqz
Created Time :2016年03月31日 星期四 02时07分16秒
File Name :code/cf/#346/DD.cpp
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
const int N=1E3+7;
int n;
int mxa,mxb,mia,mib;
struct node
{
    int x,y;
}p[N];

bool ok ( int x,int y)
{
    if (x<mxa&&x>mia&&y<mxb&&y>mib) return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	mxa = -inf;
	mxb = -inf;
	mia = inf;
	mib = inf;
	for ( int i = 1; i <= n+1 ; i++)
	{
	    cin>>p[i].x>>p[i].y;
	    mxa = max(mxa,p[i].x);
	    mxb = max(mxb,p[i].y);
	    mia = min(mia,p[i].x);
	    mib = min(mib,p[i].y);
	}
	cout<<"mxa:"<<mxa<<" mxb:"<<mxb<<" mia:"<<mia<<" mib:"<<mib<<endl;
	int ans = 0 ;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (ok(p[i].x,p[i].y))
		ans++;
	}

	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
