/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 04时29分07秒
File Name :code/uva/621.cpp
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
string st;

char solve(string x)
{
    int len = x.length();
    if (x=="1"||x=="4"||x=="78") return '+';
    if (x[len-2]=='3'&&x[len-1]=='5'&&len>=3) return '-';
    if (x[0]=='9'&&x[len-1]=='4'&&len>=3) return '*';
    if (x[0]=='1'&&x[1]=='9'&&x[2]=='0'&&len>=4) return '?';   //判断长度是默认了s为非空。。

    return '+';
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>st;
	    cout<<solve(st)<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
