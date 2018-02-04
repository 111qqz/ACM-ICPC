/* ***********************************************
Author :111qqz
Created Time :2016年01月08日 星期五 21时55分15秒
File Name :code/cf/#338/A.cpp
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
int n,m;
set<int>se;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>m;
	for ( int i = 0 ; i < n ; i++)
	{
	    
	    int x;
	    cin>>x;
	    while (x--)
	    {
		int y;
		scanf("%d",&y);
		se.insert(y);	
	    }
	}
	if (se.size()==m)
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
