/* ***********************************************
Author :111qqz
Created Time :Sat 17 Sep 2016 10:16:18 PM CST
File Name :code/cf/#372/B.cpp
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
string s;
set<char>se;
bool vis[30];
int len;
char ans[50005];
void print(int l,int r)
{
    
    for ( int i = 0 ; i < l ; i++)
    {
	if (s[i]=='?')
	    ans[i]='A';
	else ans[i]=s[i];
    }
    for ( int i = l ; i <= r ; i++)
    {
	if (s[i]!='?')
	ans[i] = s[i];
	else for ( int j = 1 ; j <= 26 ; j++)
		    if (!vis[j])
		    {
			//printf("%c",char(j+64));
			ans[i] = char(j+64);
			vis[j] = true;
			break;
		    }
//	cout<<"i:"<<i<<" ans[i]:"<<ans[i]<<" ans:"<<ans<<endl;
	
    }
  //  cout<<"sadasd"<<endl;
    for ( int  i = r+1 ; i < len ; i++)
    {
	if (s[i]=='?')
	    ans[i]='A';
	else ans[i] = s[i];
    }
    cout<<ans<<endl;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>s;
	 len = s.length();
	int cnt = 0;
	if (len<26)
	{
	    puts("-1");
	    return 0;
	}
	ms(vis,false);
	
	for ( int i = 0 ; i < 26 ; i++)
	{
	    char ch = s[i];
	    if (ch=='?')
	    {
		cnt++;
		continue;
	    }
	    se.insert(ch);
	    vis[ch-'A'+1] = true;

	}
//	cout<<s<<endl;
	if (se.size()+cnt==26)
	{
//	    cout<<"aaaa"<<endl;
	    print(0,25);
	    return 0;
	}
	for ( int i = 26 ; i < len ; i++)
	{
	    char ch = s[i-26];
	    if (ch=='?')
	    {
		cnt--;
	    }
	    else
	    {

		    if (vis[ch-'A'+1])
		    se.erase(ch);
		    vis[ch-'A'+1] = false;
	    }

	
	    ch = s[i];
	    if (ch=='?')
	    {
		cnt++;
	    }
	    else
	    {

	    se.insert(ch);
	    vis[ch-'A'+1] = true;
	    }

	    if (se.size()+cnt==26)
	    {
		print(i-25,i);
		return 0;
	    }
	}
	puts("-1");

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
