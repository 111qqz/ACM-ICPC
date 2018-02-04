/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 17时09分06秒
File Name :code/cf/#331/A.cpp
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
pi p[10];
int n ;
void solve(int  k)
{
    if (k==1)
    {
	puts("-1");
	return ;
    }
    if (k==2)
    {
	int dx = p[2].fst-p[1].fst;
	int dy = abs(p[2].sec-p[1].sec);
	if (dx==0||dy==0)
	{
	    puts("-1");
	    return ;
	}
	else
	{
	    cout<<dx*dy<<endl;
	}

    }
    if (k==3)
    {
	int dx = p[3].fst-p[1].fst;
	int dy = abs(p[2].sec-p[1].sec);
	if (dy==0) dy = abs(p[3].sec-p[1].sec);

	cout<<dx*dy<<endl;
    }
    if (k==4)
    {
	int dx = p[4].fst-p[1].fst;
	int dy = p[4].sec-p[1].sec;
	cout<<dx*dy<<endl;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	for ( int i = 1 ;i <= n ; i++)
	{
	    cin>>p[i].fst>>p[i].sec;
	}
	sort(p+1,p+n+1);
	solve (n);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
