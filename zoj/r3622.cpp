/*************************************************************************
	> File Name: code/zoj/r3622.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月19日 星期一 12时41分37秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
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
LL m,n,s[10];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif


   int ans;
   double p = 1;
 //  for ( int i = 1 ; i <= 20 ; i ++)
 //   {
//	cout<<(1.0/p)<<endl;
//	p = p * 2;
//    }
   

   while (scanf("%lld %lld",&m,&n)!=EOF)
    {
	ans =  0;
	int cnt  = 0;
	s[1] = 1;
	s[2] = 125;
	s[3] = 2;
	s[4] = 25;
	s[5] = 5; 
	while (1)
	{
	    bool ok;
	    for ( int i = 1 ; i <= 5 ; i++)
	    {
		cnt++;
		if (s[i]>=m&&s[i]<=n)
		{
		    ans++;
//		    cout<<"s[i]:"<<s[i]<<endl;
		}
	//	cout<<"cnt:"<<cnt<<endl;

		s[i] = s[i] * 10;
		if (cnt>=100) break;
	    }
	    if (cnt>=100) break;
	}
	printf("%d\n",ans);
	


    }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
