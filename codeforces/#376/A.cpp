/* ***********************************************
Author :111qqz
Created Time :Sun 16 Oct 2016 05:42:50 PM CST
File Name :code/cf/#376/A.cpp
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
string st;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>st;
	int len = st.length();
	int cur = 1;
	int ans = 0 ;
	for ( int i = 0 ; i < len ; i++)
	{
	    int a = st[i]-'a'+1;
	    int v = cur-a;
	    if (v<0) v+=26;
	    if (v<13)
	    {
		ans += v;
	    }
	    else
	    {
		ans += (26-v);
	    }
	    cur = a;
	}
	printf("%d\n",ans);

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
