/* ***********************************************
Author :111qqz
Created Time :2016年11月17日 星期四 09时31分16秒
File Name :code/poj/2442.cpp
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
#include <bitset>
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
const int N=1E4+7;
int n;
set<int>se[N];
bitset<1005>bse[N],tmp;
set<int>myset;
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    scanf("%d",&n);
    for ( int i =1 ; i <= n ; i++)
    {
	int c;
	scanf("%d",&c);
	myset.clear();
	while (c--)
	{
	    int x;
	    scanf("%d",&x);
	    bse[x].set(i);
	}
    }
    int q;
    scanf("%d",&q);
    while (q--)
    {
	int x,y;
	scanf("%d%d",&x,&y);
	tmp = bse[x]&bse[y];
	if (tmp.any()) puts("Yes");
	else puts("No");
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
