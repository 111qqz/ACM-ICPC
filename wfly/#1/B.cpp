/* ***********************************************
Author :111qqz
Created Time :2016年11月19日 星期六 19时14分45秒
File Name :code/wfly/#1/B.cpp
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
int cnt[30];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	string st;
	cin>>st;
	int len = st.length();
	if (len==1)
	{
	    printf("%c%c",st[0],st[0]);
	    return 0;
	}
	ms(cnt,0);
	for ( int i = 0 ; i < len ; i++)
	{
	    cnt[st[i]-'a'+1]++;
	}
	int odd = 0 ;
	int p;
	for  ( int i =1 ; i <= 26 ; i++)
	{
	    if (cnt[i]%2==1)
	    {
		odd++;
		p = i;
	    }
	}
	if (len%2==1)
	{
	    if (odd==1)
	    {
		//cout<<"miao"<<endl;
		for ( int i = 0 ; i < len ; i++)
		{
		    if (p==st[i]-'a'+1&&st[i]!=st[len-i-1])
		    {
			vector<char>ans;
			int q = len-i-1;
			for ( int j = 0 ; j < q ; j++) ans.push_back(st[j]);
			ans.push_back(char(p+'a'-1));
			for ( int j = q ; j < len ; j++) ans.push_back(st[j]);
			int siz = ans.size();
			bool die = false;
			for ( int i = 0 ; i < siz ; i++)
			{
			    if (ans[i]!=ans[siz-1-i])
			    {
				die = true;
				break;
			    }
			}
			if (!die)
			{
			    for ( int i = 0 ; i < siz; i ++) printf("%c",ans[i]);
			    return 0;
			}
		    }
		    if (p==st[i]-'a'+1&&i==len/2)
		    {
			for ( int j = 0 ; j <= len/2 ;j++) printf("%c",st[j]);
			printf("%c",st[len/2]);
			for ( int j = len/2+1 ; j < len ; j++) printf("%c",st[j]);
			printf("\n");
			return 0;
		    }
		
		}
	    }
	}
	else
	{
	    bool ok = false;
	    bool die = false;
	    if (odd==0)
	    {
		for ( int i = 0 ; i < len ; i++)
		{
		    if (st[i]!=st[len-1-i])
		    {
			die = true;
			break;
		    }
		}
		if (!die)
		{
		    for ( int i = 0 ; i < len/2 ; i ++) printf("%c",st[i]);
		    printf("a");
		    for ( int i = len/2 ; i< len ; i++) printf("%c",st[i]);
		    printf("\n");
		    return 0;
		}
	    }
	    if (odd==2)
	    {
		int p=-1,q=-1;
		for ( int i= 0 ; i < len; i++)
		{

		    if (cnt[st[i]-'a'+1]%2==1)
		    {
			if (p==-1)
			{
			    p = i;
			}
			else
			{
			    q = i;
			    break;
			}
		    }
		}
		cout<<"p:"<<p<<"q:"<<q<<endl;
		if (p==len/2||p==len/2+1)
		{
		    int qq = len - q;
		    for ( int i = 0 ; i < qq; i ++) printf("%c",st[i]);
		    printf("%c",st[q]);
		    for ( int i = qq ; i < len ; i++) printf("%c",st[i]);
		    printf("\n");
		    return 0;
		}
		if (q==len/2||q==len/2+1)
		{
		    int pp = len-p;
		    for ( int i = 0 ; i < pp ; i++) printf("%c",st[i]);
		    printf("%c",st[p]);
		    for ( int i = pp ; i < len ; i++) printf("%c",st[i]);
		    printf("\n");
		    return 0;
		}

	    }

	}
	puts("NA");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
