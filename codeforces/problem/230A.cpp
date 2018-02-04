/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 21时32分43秒
File Name :code/cf/problem/230A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E3+7;
int n;
pair<int,int>pi[N];
int s;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>s>>n;
	for ( int i = 0 ; i< n ; i++) cin>>pi[i].fst>>pi[i].sec;
	sort(pi,pi+n);
	int cur = s;
	bool die = false;
	for ( int i = 0 ; i < n ;i++)
	{
	    if (pi[i].fst>=s)
	    {
		die = true;
		break;
	    }
	    else
	    {
		s += pi[i].sec;
	    }
	}
	if (die)
	    puts("NO");
	else puts("YES");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
