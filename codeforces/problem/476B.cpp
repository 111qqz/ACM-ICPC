/* ***********************************************
Author :111qqz
Created Time :2016年02月02日 星期二 03时32分39秒
File Name :code/cf/problem/476B.cpp
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
string s1,s2;
int len;
int c[20][20];
void pre()
{
    ms(c,0);
    c[1][1] = 1;
    c[1][2] = 1;
    c[2][1] = 1;
    c[2][2] = 2;
    c[2][3] = 1;
    for ( int i =3 ; i  <=15 ; i++)
	for ( int j = 0 ; j <= i ; j++)
	    c[i][j+1] = c[i-1][j+1]+c[i-1][j];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	pre();

	cin>>s1>>s2;
	len = s1.length();
	int a=0,b=0;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (s2[i]=='?') a++;
	    if (s1[i]=='+') b++;
		else b--;
	    if (s2[i]=='+') b--;
		else if (s2[i]=='-') b++;
	}
//	cout<<"a:"<<a<<endl;
//	cout<<"b:"<<b<<endl;
	if (a==0)
	{
	    if (b==0) puts("1");
	    else puts("0");
	}
	else
	{
	    double ans = c[a][(a-b)/2+1]*1.0;
	    for ( int i = 1 ; i <= a ; i ++) ans *=0.5;
	    printf("%.11lf\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
