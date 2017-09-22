/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 16时46分38秒
File Name :code/uva/107.cpp
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
const double eps = 1E-12;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
int a,b;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (scanf("%d %d",&a,&b)!=EOF)
	{
	    if (a==0&&b==0) break;
	    int n ,h;
	    int ans1,ans2=0;
	    //b为1是特殊数据，除数为0了。。。。
	    if (b==1)
	    {
		h = ceil(log(a)/log(2));
		cout<<h<<" "<<2*a-1<<endl;
		continue;
	    }
	    
	    for ( int i = 1 ;  ;i++)
	    {
		if (fabs(log(a)*log(i)-log(b)*log(i+1))<eps)
		{
		    n = i;
		    break;
		}
	    }
	     h = (ceil)(log(b)/log(n));   //应该向上取整。。。可以看做一般规律。。换地公式求对数的时候。。想想为什么。
	  //  cout<<"h:"<<h<<endl;
	     ans1 = (int)((1-b)/(1-n));
	     ans2=0;
	    int curh = 1;
	    for ( int i = 0 ; i <= h ;i++)
	    {
	//	cout<<"curh:"<<curh<<" b:"<<b<<endl;
		ans2+=curh*b;
		curh*=(n+1);
		b/=n;
	    }
	   // cout<<ans1<<" "<<ans2<<endl;
	    printf("%d %d\n",ans1,ans2);

	    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
