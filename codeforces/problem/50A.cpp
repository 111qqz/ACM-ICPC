/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 17时21分11秒
File Name :code/cf/problem/50A.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
int n,m;

int solve ( int x,int y)
{
                                                                    
    if (x%2==0)
    {
	return   x/2 * y;
    }
    if (y%2==0)
    {
	return y/2 * x;
    }
    return x*(y/2) + x/2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	cin>>m>>n;
	cout<<solve(m,n)<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
