/* ***********************************************
Author :111qqz
Created Time :2015年12月25日 星期五 19时24分11秒
File Name :code/bnu/2015/A.cpp
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
int t1,t2;
int ans;
int main()
{
//	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
//  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    ans = 0 ;
	    scanf("%d%d",&t1,&t2);
	    ans = max(t1,t2);
	    ans = ans *5;
	    ans = max(1000,ans);
	    ans = min(60000,ans);
	    printf("%d\n",ans);
	}

//  #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
    return 0;
}
