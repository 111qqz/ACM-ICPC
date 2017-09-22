/*************************************************************************
	> File Name: code/zoj/3629.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月24日 星期六 20时07分02秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
                 
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
LL a,b;
void pre()
{
    int sum =  1;
    for ( int i =1; i <= 300 ; i++)
    {
	int res = 0 ;
	for ( int j = 1 ; j <= i ; j++)
	    res = res + i/j;
	if (res%2==0)
	{
	    sum++;
	    cout<<"i:"<<i<<endl;
	}

    }

    printf(" sum: %d\n",sum);

}

LL cal( LL n) //计算0到n有多少个数满足
{
    if(n==0) return 1;
    if (n<0) return 0;

    LL res = 0 ;
    LL sn = sqrt(n);
    LL k = sn/2 + 1; //k为等差数列的项数，第k项为4k-3
    
     res = (2*k-1)*k;
     if (sn%2==0)
    {
	res = res -(4*k-3);
	res = res+n-(2*k-2)*(2*k-2)+1;
    }

  //  cout<<"k:"<<k<<" n:"<<n<<" res:"<<res<<endl;
    return res;
     
}
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   //pre();
   while (scanf("%lld %lld",&a,&b)!=EOF)
    {
	printf("%lld\n",cal(b)-cal(a-1));
    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
