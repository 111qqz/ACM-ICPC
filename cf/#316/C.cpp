/*************************************************************************
	> File Name: code/cf/#316/C.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月14日 星期五 00时54分50秒
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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=3E5+7;
int n,m;
char st[N];

int judge(char a,char b)
{
    if (a>='a'&&a<='z'&&b>='a'&&b<='z') return 0;
    if (a=='.'&&b=='.') return 0;
    if (a>='a'&&a<='z'&&b=='.') return 1;
    if (a=='.'&&b>='a'&&b<='z') return -1;
}
int main()
{
    cin>>n>>m;
    getchar();
    st[0]=' ';
    for ( int i = 1 ; i <= n ; i++)
    {
	scanf("%c",&st[i]);
    }
    int cnt = 0;
    for ( int i = 1 ;i <= n - 1 ; i++)
    {
	if (st[i]=='.'&&st[i+1]=='.')
	{
	    cnt++;
	}
    }
   // cout<<"cnt :"<<cnt<<endl;
    int x;
    char ch;
    for ( int i = 1 ; i <= m ; i++)
    {
	scanf("%d",&x);
	getchar();
	scanf("%c",&ch);
	int flag =judge(st[x],ch);
	st[x] = ch;
	if (flag==0)
	{
	    cout<<cnt<<endl;
	    continue;
	}
	if (flag==1)
	{
	    if (st[x-1]=='.') cnt++;
	    if (st[x+1]=='.') cnt++;
	    cout<<cnt<<endl;
	    continue;
	}
	if (flag==-1)
	{
	    if (st[x-1]=='.') cnt--;
	    if (st[x+1]=='.') cnt--;
	    cout<<cnt<<endl;
	    continue;
	}

    }
  
	return 0;
}
