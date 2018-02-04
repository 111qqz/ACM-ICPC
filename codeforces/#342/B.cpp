/* ***********************************************
Author :111qqz
Created Time :2016年02月07日 星期日 17时31分33秒
File Name :code/cf/#342/B.cpp
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
string ori,tar;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>ori>>tar;
	int p = ori.find(tar);
	int ans = 0 ;
	int lst = 0;
	while (p!=-1)
	{
	    ans++;
	    ori[p]='#';
	    lst = p + tar.length()-1;
	    ori[lst]='#';
	    
	    p = ori.find(tar,lst);
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
