/* ***********************************************
Author :111qqz
Created Time :2016年05月07日 星期六 23时01分11秒
File Name :code/cf/#351/A.cpp
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
int n;
bool v[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(v,false);
	cin>>n;
	for ( int i = 0 ; i < n ; i++)
	{
	    int x;
	    cin>>x;
	    v[x] = true;
	}

	int cnt = 0;
	int ans = 0;
	for ( int i = 1 ; i <= 90 ; i++)
	{
	    ans++;
	    if (v[i])
	    {
		cnt = 0;
	    }
	    else
	    {
		cnt++;
	    }
	    if (cnt==15) break;

	}

	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
