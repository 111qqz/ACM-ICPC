/* ***********************************************
Author :111qqz
Created Time :2016年01月26日 星期二 14时02分31秒
File Name :code/uva/755.cpp
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
string str;
map<char,char>mp;
map<string,int>ans;
map<string,int>::iterator it;
int n ;
void pre()
{
    mp.clear();
    for ( int i = 1 ; i <= 26 ; i++)
    {
	char ch = char(i+64);
	if (i<=3) mp[ch]='2';
	if (i>3&&i<=6) mp[ch]='3';
	if (i>6&&i<=9) mp[ch]='4';
	if (i>9&&i<=12) mp[ch]='5';
	if (i>12&&i<=15) mp[ch]='6';
	if (i>15&&i<=19) mp[ch]='7';
	if (i>19&&i<=22) mp[ch]='8';
	if (i>22&&i<=25)mp[ch]='9';
    }
}
void solve (string x)
{
    string res ="";
    int cnt = 0 ;
    int len = x.length();
    for ( int i = 0 ; i  < len ; i++)
    {
	
	if (x[i]>='0'&&x[i]<='9')
	{
	    res+=x[i];
	    cnt++;
	}
	else if (x[i]>='A'&&x[i]<='Z')
	{
	    res+=mp[x[i]];
//	    cout<<"wwwwaaa"<<endl;
	    cnt++;
	}
	else continue;
	if (cnt==3) res+='-';
//	cout<<"res:"<<res<<endl;
    }

    ans[res]++;

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	pre();
	int T;
	cin>>T;
	string space;
	getline(cin,space);
	
	while (T--)
	{
	    ans.clear();
	    scanf("%d",&n);
	    for ( int i = 0 ; i < n ; i++)
	    {
		cin>>str;
	//	cout<<"str:"<<str<<endl;
		solve(str);
	    }
	    
	    bool out = false;
	//    cout<<"ans.size():"<<ans.size()<<endl;
	    for (it=ans.begin() ;it!=ans.end() ;it++)
	    {
		if (it->second>1)
		{
		    cout<<it->fst<<" "<<it->second<<endl;
		    out = true;
		}
	    }
	    if (!out)
	    {
		puts("No duplicates.");
	    }
	    if (T)
	    {
		string space;
		getline(cin,space);
		printf("\n");
	    }

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
