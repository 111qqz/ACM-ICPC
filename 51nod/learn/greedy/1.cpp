/*************************************************************************
	> File Name: code/51nod/learn/greedy/1.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月30日 星期三 16时17分45秒
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
string str;
int len;
int cnt[30];
int main()
{
//  #ifndef  ONLINE_JUDGE 
//   freopen("in.txt","r",stdin);
//  #endif
    ms(cnt,0);
    cin>>str;
    len = str.length();
    for ( int i = 0 ; i < len ; i++)
    {
	int tmp;
	if (str[i]>='A'&&str[i]<='Z')
	{
	    tmp = str[i]-'A';
	}
	else
	{
	    tmp = str[i] - 'a';
	}
	cnt[tmp]++;
    }
    sort(cnt,cnt+26);
    int ans = 0 ;
    for ( int i = 0 ; i < 26  ; i++)
    {
	ans = ans + (i+1)*cnt[i];
    }
    printf("%d\n",ans);

   
// #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
	return 0;
}
