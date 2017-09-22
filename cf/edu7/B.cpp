/* ***********************************************
Author :111qqz
Created Time :2016年02月10日 星期三 22时56分25秒
File Name :code/cf/edu7/B.cpp
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
string st;
int h,m;
int a;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>st;
	cin>>a;
	string sh = st.substr(0,2);
	string sm = st.substr(3,2);
	sscanf(sh.c_str(),"%d",&h);
	sscanf(sm.c_str(),"%d",&m);

//	cout<<"h:"<<h<<endl;
//	cout<<"m:"<<m<<endl;

	h +=a/60;
	a %=60;
	m += a;
	h +=m/60;
	m %=60;
	h %=24;

//	cout<<"h:"<<h<<" m:"<<m<<endl;
	if (h<10)
	{
	    cout<<"0"<<h;
	}
	else cout<<h;
	cout<<":";
	if (m<10)
	{
	    cout<<"0"<<m<<endl;
	}
	else cout<<m<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
