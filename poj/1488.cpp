/*************************************************************************
	> File Name: poj/1488.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月28日 星期一 17时35分06秒
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
bool flag ;
char ch;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif
   flag  = 1;
   while ((ch=getchar())!=EOF)
    {
	    if(ch == '"') 
	    {
		printf("%s", flag ? "``" : "''"); 
		flag = !flag; 
	    }
	    else printf("%c", ch);
    }

 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
