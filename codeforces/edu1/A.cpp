/* ***********************************************
Author :111qqz
Created Time :2015年12月03日 星期四 16时46分46秒
File Name :code/cf/edu/A.cpp
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
LL n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	scanf("%d",&T);
	while (T--)
	{
	    LL sum = 0 ;
	    cin>>n;
	    LL k = LL(floor(log(n)/log(2)));
	   // cout<<"k:"<<k<<endl;
	    k =(1<<(k+1))-1;
	 //   cout<<"kk:"<<k<<endl;
	    sum = sum-2*k;
	  //  cout<<"sum:"<<sum<<endl;
	    s`um = sum + (n+1)*n/2;
	    cout<<sum<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
