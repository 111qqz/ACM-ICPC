/*************************************************************************
	> File Name: code/uva/1368.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月17日 星期四 18时00分37秒
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
const int N=1E3+7;
string st[N];
int cnt [30];
int n,len;
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
    int T;
    cin>>T;
    while (T--)
    {
	string ans;
	int num = 0 ;

	scanf("%d %d",&n,&len);
	for ( int i = 0 ; i < n ; i++)
	{
	    cin>>st[i];
	}
	ms(cnt,0);


	char tmp;
	for ( int i = 0 ; i < len ; i++)
	{
	    ms(cnt,0);
	    int mx =  0;
	    for ( int j = 0 ; j < n ; j++)
	    {
		cnt[st[j][i]-'A']++;
	    }
	    for ( int z = 0 ; z < 26 ; z++)
	    {
		if (cnt[z]>mx)
		{
		    mx = cnt[z];
		    tmp = char (z+'A');
		}
	    }
	    ans = ans + tmp;
	}


	cout<<ans<<endl;
	for ( int i = 0 ; i < len ;i++)
	{
	    for ( int j = 0 ; j < n ; j++)
	    {
		if (ans[i]!=st[j][i])
		{
		    num++;
		}
	    }
	}
	cout<<num<<endl;
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
