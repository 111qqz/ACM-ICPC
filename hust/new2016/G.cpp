/* ***********************************************
Author :111qqz
Created Time :2016年03月06日 星期日 12时59分11秒
File Name :code/hust/new2016/G.cpp
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
const int N=1E6+15;
bool np[N];
int prime[N];
int cnt_prime=0;
int n;
void getprime()
{
    ms(np,false);


    for ( int i = 2 ; i < N ; i++)
    {
	if (!np[i])
	{
	    prime[++cnt_prime] = i;
	    for ( int j = i+i ; j <  N; j+=i)
	    {
		np[j] = true;
	    }
	}
    }
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	getprime();

//	for ( int i = 1 ; i <= 100 ; i++) cout<<prime[i]<<endl;
	while (~scanf("%d",&n))
	{
	    if (n==0) break;
	    //check
	    bool ok = false;
	    int x,y;
	    for ( int i = 2 ; prime[i]<n ;  i++)  //奇素数，排除掉2。
	    {
		if (!np[n-prime[i]])
		{
		    ok = true;
		    printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
		    break;
		}
	    }
	    if (!ok)
	    {
		puts("No answer");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
