/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 15时50分36秒
File Name :code/bc/#64/1001.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E3+7;
char st[N];
int len;
int sum;

bool ok ()
{
    if (sum%3==0) return true;
    char lst = st[len-1];
    if (lst=='0'||lst=='2'||lst=='4'||lst=='5'||lst=='6'||lst=='8') return true;
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	while (scanf("%s",st)!=EOF)
	{
	    len = strlen(st);
	     sum = 0 ;
	    for ( int i = 0 ; i < len ; i++)
	    {
		char tmp = st[i]-'0';
		sum = sum + tmp;
	    }
	    if (ok())
	    {
		puts("YES");
	    }
	    else
	    {
		puts("NO");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
