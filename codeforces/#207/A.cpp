/* ***********************************************
Author :111qqz
Created Time :2015年12月23日 星期三 19时47分44秒
File Name :code/cf/#207/A.cpp
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
const int N=105;
int x,y;
int n;
int c[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	int total = 0 ;
	for ( int i = 1 ; i<=n ; i++) cin>>c[i],total+=c[i];
	cin>>x>>y;
	int sum = 0 ;
	bool flag = false;
	for ( int i = 1 ; i <= n ; i++)
	{
	    sum+=c[i];
	    if (sum>=x&&sum<=y&&(total-sum)>=x&&(total-sum)<=y)
	    {
		flag = true;
		cout<<i+1<<endl;
		break;
	    }
	}
	if (!flag)
	{
	    puts("0");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
