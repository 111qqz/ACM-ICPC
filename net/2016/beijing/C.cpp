/* ***********************************************
Author :111qqz
Created Time :Sat 24 Sep 2016 12:08:14 PM CST
File Name :code/net/2016/beijing/C.cpp
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
const int N=505;
string st;
string s1,s2;
map< pair <string,string >, int >mp;
bool low( char ch)
{
    return ch >='a'&&ch<='z';
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (getline(cin,st))
	{
	    st = st + " ";
	    while (st!="####")
	    {
		int pos = st.find(" ");
		s1 = st.substr(0,pos);
		st.erase(0,pos+1);
		while (!low(st[0])) st.erase(0,1);
		pos = st.find(" ");
		s2 = st.substr(0,pos);
		st.erase(pos+1);
		mp[make_pair(s1,s2)]++;
	    }


	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
