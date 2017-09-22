/* ***********************************************
Author :111qqz
Created Time :2016年03月16日 星期三 15时09分45秒
File Name :code/cf/problem/55D.cpp
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
int digit[30];
int tmp[30];
LL dfs(int pos,LL sum,bool limit)
{
    if (pos==0)
    {
	if (ok()) return 1;
	return 0;
    }

    if (!limit)


}
LL solve (LL n)
{
    int len = 0 ;
    ms(digit,0);
    ms(tmp,0);
    while (n)
    {
	digit[++len] = n % 10;
	n/= 10;
    }
    return dfs(len,0,true);

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
	    cin>>l>>r;
	    LL ans = solve (r)-solve(l-1);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
