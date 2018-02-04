/* ***********************************************
Author :111qqz
Created Time :2015年12月11日 星期五 15时08分27秒
File Name :code/cf/problem/82A.cpp
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
int n;
string nam[10];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	nam[1] = "Sheldon";
	nam[2] = "Leonard";
	nam[3] = "Penny";
	nam[4] = "Rajesh";
	nam[5] = "Howard";
	int cur;
	int p ;
	while (scanf("%d",&n)!=EOF)
	{
	    cur = 2;
	    for ( int i = 1 ; i <= n ; i++)
	    {
		cur = (1<<i);
	//	cout<<"cur:"<<cur<<endl;
		cur--;
		if (cur*5>=n)
		{
		    p = i ;
		    break;
		}
	    }
	//    cout<<"p:"<<p<<endl;
	    n -= ((1<<(p-1))-1)*5;
	  //  cout<<"n:"<<n<<endl;
	int id = n + (1<<(p-1))-1;
	id = id/(1<<(p-1));
	cout<<nam[id]<<endl;
    }



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
