/* ***********************************************
Author :111qqz
Created Time :2016年08月25日 星期四 21时03分18秒
File Name :code/uvalive/6858.cpp
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
int X,Y;
int n;
bool check( int a)
{
    if (a==2) return true;                                          
    if (X%a==0&&(Y-2)%a==0) return true;
    if (Y%a==0&&(X-2)%a==0) return true;
    if (X%a==1&&Y%a==1) return true;

    return false;
}
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif
    while (~scanf("%d%d",&X,&Y))
    {   scanf("%d",&n);
	while (n--)
	{
	    int x;
	    scanf("%d",&x);
	    if (check(x))
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}
    }

#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
