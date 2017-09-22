/* ***********************************************
Author :111qqz
Created Time :2016年08月10日 星期三 23时46分47秒
File Name :code/poj/2185.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=1E4+7;
char s[80][N];
int n,m;
int nxt[N];
void getrownxt(int row,int n)
{
    int i = 0 ;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||s[row][i]==s[row][j]) nxt[++i]=++j;
	else j = nxt[j];
}
void getcolnxt(int col,int n)
{
    int i = 0 ;
    int j = -1;
    nxt[0] = -1;
    while (i<n)
	if (j==-1||s[i][col]==s[j][col]) nxt[++i]=++j;
	else j = nxt[j];
}
int gcd( int a,int b)
{
    if (a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;  //蒟蒻的自我修养
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n>>m;
	for ( int i = 0 ; i < n ; i++) scanf("%s",s[i]);

	int L = 1;
	for ( int i =  0 ; i < n ; i++)
	{
	    getrownxt(i,m);
	    L = lcm(L,m-nxt[m]);
	}
	int R = 1;
	for ( int i = 0 ; i < m ; i++)
	{
	    getcolnxt(i,n);
	    R = lcm(R,n-nxt[n]);
	}
	
	cout<<"L:"<<L<<" R:"<<R<<endl;
	L = min(L,m);
	R = min(R,n);
	printf("%d\n",L*R);
	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
