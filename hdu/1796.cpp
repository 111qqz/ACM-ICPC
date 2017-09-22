/* ***********************************************
Author :111qqz
Created Time :2016年02月29日 星期一 19时09分31秒
File Name :code/hdu/1796.cpp
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
int n,m;
int a[15];
int b[15];

LL gcd ( LL a,LL b)
{
    if (b>a) return gcd(b,a);
    if (a%b==0) return b;
    return gcd(b,a%b);
}

LL lcm( LL a,LL b)
{
    LL res;
    res = a*b;
    res = res/gcd(a,b);
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%d %d",&m,&n))  //m,n和题目中的意思相反，实在看着别扭
	{
	    int cnt = 0 ;
	    bool zero = false;
	    for ( int i = 0 ; i < n ; i++)
	    {
		scanf("%d",&b[i]);
		if (b[i])
		{
		    a[cnt++] = b[i];
		}
		else
		{
		    zero = true;
		}
	    }

	    if (cnt==0)   //只有一个元素且是0...0不能做除数啊。。。这题好蠢
	    {
		puts("0");
		continue;  
	    }


	    
	    n = cnt;

	    LL ans = 0LL ; 
	    for ( int msk = 1 ; msk  < (1<<n) ; msk++)
	    {
		    int bits = 0 ;
		    LL LCM;
		    for ( int i = 0 ; i < n ; i++)
		    {
			
			if (msk&(1<<i))
			{
			    bits++;
			    if (bits==1)
			    {
				LCM = a[i];
			    }
			    else
			    {
				LCM = lcm(LCM,LL(a[i]));
			    }
			}
		    }

		    //cout<<"LCM:"<<LCM<<endl;
		    if (bits%2==1)
		    {
			ans +=LL((m-1)/LCM);
		    }
		    else
		    {
			ans -=LL((m-1)/LCM);
		    }

	    }
	    printf("%lld\n",ans);
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
