/* ***********************************************
Author :111qqz
Created Time :2017年10月09日 星期一 17时13分12秒
File Name :I_brute.cpp
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
#define PB push_back
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
void solve( int x)
{
    int digit[20];
    int cnt = 0 ;
    while (x)
    {
	digit[++cnt] = x%10;
	x/=10;
    }
    for ( int i = 1 ; i <= cnt/2 ; i++) swap(digit[i],digit[cnt-i+1]);
    for ( int i = 1 ; i <= cnt ; i++) printf("%d",digit[i]);
    puts("");
    int sum3 = 0;
    for ( int i = 1 ; i <= cnt ; i++)
    {
	int sum2 = 0;
	for ( int j = 1 ; j <= i ; j++) //i个数相加
	{
	    int sum = 0 ;
	    for ( int k = j ; k <= i ; k++)
	    {
		sum = sum + digit[k];
	    }
	    sum2 = sum2 + sum*sum ;
	}
	cout<<"sum2:"<<sum2<<endl;
    }
}


int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("./in.txt","r",stdin);
  #endif
	int n;
	while (~scanf("%d",&n))
	{
	    solve(n);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
