/* ***********************************************
Author :111qqz
Created Time :2016年01月24日 星期日 20时22分50秒
File Name :code/uva/10815.cpp
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
set<string>se;
set<string>::iterator it;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (getline(cin,str))
	{
//	    cout<<"str:"<<str<<endl;
	    int p =  0;
	    int len = str.length();
	    for ( int i = 0 ; i < len ; i++)
	    {
		str[i]=tolower(str[i]);
		if (str[i]<'a'||str[i]>'z')
		{
		    str[i]=' ';
		}
	    }
	    while (p!=-1)
	    {

		 p = str.find(' ');
		string tmp = str.substr(0,p);
		if (tmp!="") 
		se.insert(tmp);
		str.erase(0,p+1);
//		cout<<"str::"<<str<<endl;
//		cout<<"tmp:"<<tmp<<" len:"<<tmp.length() <<endl;
	    }

	}

	for ( it=se.begin() ;it!=se.end(); it++)
	{
	    cout<<*it<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
