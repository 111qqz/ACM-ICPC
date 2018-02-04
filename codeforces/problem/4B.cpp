/* ***********************************************
Author :111qqz
Created Time :Sun 02 Oct 2016 07:58:54 PM CST
File Name :code/cf/problem/4B.cpp
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
const int N=35;
int n,total;
int ans[N];
pi t[N];
int mx,mn;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>total;
	mx = mn = 0 ;
	for ( int i = 1; i <= n ; i++)
	{
	    cin>>t[i].fst>>t[i].sec;
	    mn += t[i].fst;
	    mx += t[i].sec;
	    ans[i] = t[i].fst;
	}
	if (total<mn||total>mx)
	{
	    puts("NO");
	    return 0;
	}
	puts("YES");
	int need = total - mn;
	for ( int i = 1 ; i <= n ; i++)
	{
	    if (need>0)
	    {
		int cur = min(need,t[i].sec-t[i].fst);
		need -=cur;
		ans[i]+=cur;
	    }
	}

	for ( int i = 1 ; i <= n ; i++) printf("%d ",ans[i]);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
