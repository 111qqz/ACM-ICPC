/*************************************************************************
    > File Name: zoj/3633.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年10月22日 星期四 18时26分27秒
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
const int N=5E5+7;
int n,m;
int a[N],ans[N];
int l,r;
set<int>se;



int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   while (scanf("%d",&n)!=EOF)
   {
    

       for ( int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);

       scanf("%d",&m);

       for ( int i = 0 ; i < m ; i++)
       {
	   bool ok = true;
	   scanf("%d %d",&l,&r);
	   se.clear();

	   for ( int j = r ; j >= l ; j--)
	    {
//		cout<<"j:"<<j<<" a[j]:"<<a[j]<<endl;
		if (!se.count(a[j]))
		{
		    se.insert(a[j]);
		}
		else
		{
		    ok = false;
		    printf("%d\n",a[j]);
		    break;
		}
		
	    }
	   if (ok) puts("OK");
       }
	puts("");

       
   }
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
