/* ***********************************************
Author :111qqz
Created Time :2017年10月25日 星期三 12时20分25秒
File Name :B.cpp
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
int n;
string st;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif

	cin>>n;
	cin>>st;
	set<char>se;
	int ans =  0;
	for ( int i = 0 ; i < n ; i++)
	{
	    if (st[i]>='a'&&st[i]<='z')
	    {
		se.insert(st[i]);
		ans = max(ans,int(se.size()));
	    }
	    else
	    {
		se.clear();
	    }
	}
	cout<<ans<<endl;
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
