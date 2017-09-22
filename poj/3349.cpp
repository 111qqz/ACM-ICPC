/* ***********************************************
Author :111qqz
Created Time :2016年11月29日 星期二 19时29分11秒
File Name :code/poj/3349.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
const int N=1e5+7;
const int inf = 0x3f3f3f3f;
int n;
int a[N][6];
const int prime = 19997; //素数
vector<int>block[prime];
void Hash( int val,int x)
{
    val%=prime;
    block[val].push_back(x);
}
bool ok ( int x,int y) //两个雪花的id
{
    for ( int i = 0 ;i < 6 ; i++)
    {
	if (a[x][0]==a[y][i])
	{
	    for ( int j = 1 ; j < 6; j++)
		if (a[x][j]!=a[y][(i+j)%6]) break;
		else if (j==5) return true;

	    for ( int j =1 ; j < 6 ; j++)
		if (a[x][6-j]!=a[y][(i+j)%6]) break;
		else if (j==5) return true;
	}
    }
    return false;
}
bool check()
{
    for ( int i = 0 ; i < prime ; i++)
    {
	int siz = block[i].size();
	for ( int j = 0 ; j < siz;  j++)
	{
	    for ( int k = j+1 ; k < siz;  k++)
	    {
		int x = block[i][j];
		int y = block[i][k];
		if (ok(x,y)) return true;
	    }
	}
    }
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	scanf("%d",&n);
	for ( int i = 1; i <= n ; i++) 
	{
	    int sum = 0;
	    for ( int j = 0 ; j < 6 ; j++) scanf("%d",&a[i][j]),sum += a[i][j];
	    Hash(sum,i);
	}
	if (check())
	    puts("Twin snowflakes found.");
	else puts("No two snowflakes are alike.");

    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
