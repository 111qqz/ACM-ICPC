/*************************************************************************
	> File Name: code/hust/20151025/BB.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年10月27日 星期二 14时34分16秒
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
#define sec second
#define fir first
using namespace std;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;

const int N=4E3+7;
int n;
LL mx,cura,curb;
pair<LL,LL> a[N];
multiset<LL> se;
multiset<LL> ::iterator it;
int main()
{
  #ifndef  ONLINE_JUDGE 
   freopen("in.txt","r",stdin);
  #endif

   scanf("%d",&n);
   for ( int i = 0 ; i < n ; i++)
    {
	scanf("%lld %lld",&a[i].fir,&a[i].sec);
	if (a[i].fir>a[i].sec) swap(a[i].fir,a[i].sec);
    }
   sort(a,a+n);
   mx = -1;
   for ( int i = n -1 ; i >= 0 ; i--)
   {
       se.insert(a[i].sec);
       it =se.begin();
       for ( int j = i ; j < n ; j++)
	{
	    LL tmp =a[i].fir*(*it)*(n-j);
	    if (tmp>mx)
	    {
		mx = tmp;
		cura = a[i].fir;
		curb = *it;
	    }
	    it++;
	}
   }
   printf("%lld\n%lld %lld\n",mx,curb,cura);
  
   
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
