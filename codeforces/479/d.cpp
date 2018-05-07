/* ***********************************************
Author :111qqz
mail: hust.111qqz@gmail.com
Created Time :Sun 06 May 2018 05:51:49 PM EDT
File Name :a.cpp
************************************************ */

#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define ms(a,x) memset(a,x,sizeof(a))
typedef long long LL;

int n;
struct node
{
	int num2;
	int num3;
	LL val;
}p[105];

bool cmp( node a,node b)
{
	if (a.num3==b.num3) return a.num2<b.num2;
	return a.num3>b.num3;
}
int getF2(LL x)
{
	int res = 0 ;
	while (x%2==0)
	{
		x/=2;
		res++;
	}
	return res;
}
int getF3(LL x)
{
	int res = 0 ;
	while (x%3==0)
	{
		x/=3;
		res++;
	}
	return res;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	memset(p,0,sizeof(p));
	for ( int i = 1 ; i <= n ; i++)
	{
		LL x;
		cin>>x;
		p[i].val = x;
		p[i].num2 = getF2(x);
		p[i].num3 = getF3(x);
	}
	sort(p+1,p+n+1,cmp);
	for ( int i = 1 ; i <= n ; i++) printf("%lld%c",p[i].val,i==n?'\n':' ');

		

 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	
    return 0;
}
