/*************************************************************************
	> File Name: code/uva/r10340.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月17日 星期四 18时24分19秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+6;
char a[N],b[N];
int lena,lenb;

int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif
    while (scanf("%s %s",a,b)!=EOF)
    {
	int lena = strlen(a);
	int lenb = strlen(b);
	
	int p = 0 ;
	for ( int i = 0 ; i < lenb ; i++)
	{
	    if (a[p]==b[i])
	    {
		p++;
	    }
	    if (p==lena)
	    {
		break;
	    }
	}
	if (p==lena)
	{
	    puts("Yes");
	}
	else
	{
	    puts("No");
	}
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
