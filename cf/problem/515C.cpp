/* ***********************************************
Author :111qqz
Created Time :2015年12月14日 星期一 15时05分08秒
File Name :code/cf/problem/515C.cpp
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

int n ;
char st[30];
int cnt;
int a[3000];

bool cmp( int a,int b)
{
    return a>b;
}
void solve(char ch)
{
    if (ch=='0'||ch=='1') return;
    if (ch=='2'||ch=='3'||ch=='5'||ch=='7')
    {
	cnt++;
	a[cnt] = ch-'0';
    }
    if (ch=='4')
    {
	cnt++;
	a[cnt] = 3;
	cnt++;
	a[cnt] = 2;
	cnt++;
	a[cnt] = 2;
    }
    if (ch=='6')
    {
	cnt++;
	a[cnt] = 5;
	cnt++;
	a[cnt] = 3;
    }
    if (ch=='8')
    {
	cnt++;
	a[cnt] = 7;
	cnt++;
	a[cnt] = 2;
	cnt++;
	a[cnt] = 2;
	cnt++;
	a[cnt] = 2;
    }
    if (ch=='9')
    {
	cnt++;
	a[cnt] = 7;
	cnt++;
	a[cnt] = 2;
	cnt++;
	a[cnt] = 3;
	cnt++;
	a[cnt] = 3;
    }
    sort(a+1,a+cnt+1,cmp);
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	cin>>st;
	cnt = 0 ;
	for ( int i = 0 ; i < n ;i++)
	{
	    solve(st[i]);
	}
	for ( int i = 1 ; i <= cnt ;i++)
	    cout<<a[i];
	cout<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
