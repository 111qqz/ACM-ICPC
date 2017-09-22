/*************************************************************************
	> File Name: code/cf/#323/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月04日 星期日 00时24分37秒
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
const int N=76;
int ans[5000];
int n;
int a,b;
bool x[N],y[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   ms(x,false);
   ms(y,false);
   int cnt = 0 ;
   for ( int i = 0 ; i < n*n ; i++)
    {
	scanf("%d %d",&a,&b);
	if (!x[a]&&!y[b])
	{
	    cnt++;
	    ans[cnt] = i+1;
	    x[a] = true;
	    y[b] = true;
	}
    }
   for ( int i = 1 ; i < cnt ; i++)
       printf("%d ",ans[i]);
 //  cout<<"cnt:"<<cnt<<endl;
   printf("%d\n",ans[cnt]);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
