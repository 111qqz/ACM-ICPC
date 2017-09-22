/*************************************************************************
	> File Name: code/0919/r1006.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月19日 星期六 18时03分35秒
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
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E6+7;
int ans;
char str[N];
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);  
  #endif

    int T;
    cin>>T;
    int cas = 0 ;
    while (T--)
    {
	cas++;
	scanf("%s",str);
	int len = strlen(str);
	int cnt  = 0;
	int ans = 0 ;
	bool hasc = false;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (str[i]!='c'&&str[i]!='f')
	    {
		ans =  -1;
		break;
	    }
	}
	if (ans==-1)
	{
	     printf("Case #%d: %d\n",cas,-1);
	}
	for ( int i = len - 1 ; i>= 0 ; i--)
	{
	    if (str[i]=='c')
	    {
		hasc=true;
		break;
	    }
	    cnt++;
	}
	if (!hasc)
	{
	    printf("Case #%d: %d\n",cas,(len+1)/2);
	    continue;
	}
    
	int fst;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (str[i]!='c')
	    {
		cnt++;
	    }
	    else
	    {
		fst  = i;
		break;
	    }
	}
	if (cnt<2)
	{
	    printf("Case #%d: %d\n",cas,-1);
	 //   cout<<"aahhh"<<endl;
	    continue;
	}

	int p = fst;
//	cout<<"fst:"<<fst<<endl;
	for ( int i = fst+1 ; i < len ; i ++)
	{
	    
	    if (str[i]=='c')
	    {
		int tmp =i-p;
		if (tmp<3)
		{
//		    cout<<"i:"<<i<<" p:"<<p<<endl;
		    ans = -1;
//		    cout<<"ah33hhh"<<endl;
		    break;
		}
		p =  i;
	    }
	}
	if (ans==-1)
	{
	    
	    printf("Case #%d: %d\n",cas,-1);
	  //  cout<<"why"<<endl;
	    continue;
	}
	ans = 0 ;
	for ( int i = 0 ; i < len ; i++)
	{
	    if (str[i]=='c')
	    {
		ans++;
	    }
	}
	printf("Case #%d: %d\n",cas,ans);


	
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
