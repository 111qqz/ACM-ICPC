/* ***********************************************
Author :111qqz
Created Time :Sat 17 Sep 2016 09:56:12 PM CST
File Name :code/cf/#372/C.cpp
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
LL n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ios::sync_with_stdio(false);
	cin>>n;
	LL cur = 2;
	LL  need;
	LL ans;
	for ( LL i = 1 ; i <= n ; i++)
	{
		if (i==1) cout<<2<<endl;
		else
		{

			need = i*(i+1)*(i+1);
			ans	= need - cur;
			cout<<ans+1<<endl;
			cur = (i+1);
		}
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
