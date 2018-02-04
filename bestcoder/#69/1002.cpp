/* ***********************************************
Author :111qqz
Created Time :2016年01月23日 星期六 18时58分10秒
File Name :code/bc/#69/1002.cpp
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
int n;
string str;
LL a,b;
bool good1(string x)
{
    int len = x.length();
    if (x[10]==x[9]&&x[9]==x[8]&&x[8]==x[7]&&x[7]==x[6]&&x[6]==x[10]) return true;
    return false;
}
bool good2(string x)
{
    int p = 0 ;
    for ( int i =  6 ; i <=9  ;i++)
    {
	if (x[i+1]-x[i]==-1) p++;
    }
    if (p==4) return true;
    p =  0;
    for ( int i = 6 ; i <= 9 ; i++)
    {
	if (x[i+1]-x[i]==1) p++;
    }
    if (p==4) return true;

    return false;
}

bool runnian (int ye)
{
    if (ye%400==0) return true;
    if (ye%4==0&&ye%100!=0) return true;
    return false;
}
bool good3( string x)
{
    int year;
    string s_year;
    int mon;
    string s_mon;
    int day;
    string s_day;
    char ye[12],mo[10],da[10];

    s_year = x.substr(3,4);
  //  cout<<"s_year:"<<s_year<<endl;
    sscanf(s_year.c_str(),"%d",&year);
    s_mon  = x.substr(7,2);
    sscanf(s_mon.c_str(),"%d",&mon);
    s_day = x.substr(9,2);
    sscanf(s_day.c_str(),"%d",&day);
//    cout<<"year:"<<year<<" month:"<<mon<<" day:"<<day<<endl;
    if (year<1980||year>2016) return false;
      if (mon<1||mon>12) return false;
    set<int>bigmon;
    bigmon.insert(1);  
    bigmon.insert(3);
       bigmon.insert(5);
   bigmon.insert(7);  
      bigmon.insert(8);
   bigmon.insert(10);
   bigmon.insert(12);
   bool run = runnian(year);
   if (bigmon.count(mon))
   {
       if (day<1||day>31) return false;
   }
   else
    {
	if (mon==2)
  	{
	    if (run)
	    {
		if (day<1||day>29) return false;
	    }
	    else
	    {
		if (day<1||day>28) return false;
	    }
	}
	else
	{
	    if (day<1||day>30) return false;
	}
    }
   return true;

}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    cin>>a>>b;
	    LL ans = 0 ;
	    for ( int i = 0 ; i < n ; i++)
	    {
		cin>>str;
		if (good1(str)||good2(str)||good3(str))
		    ans +=a;
		else ans+=b;
//		cout<<"ans:"<<ans<<endl;
	    }
	    cout<<ans<<endl;

	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
