/* ***********************************************
Author :111qqz
Created Time :2016年03月24日 星期四 12时24分42秒
File Name :code/cf/#120/C.cpp
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
string s;
int cntp=0,cnti=0;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	getchar();
	getline(cin,s);
//	cout<<"s:"<<s<<endl;
	s = s + " ";
	int p = s.find(' ');
	string ans="";
//	cout<<p<<endl;
	bool preint = false;
	int left = 0 ;
	int right = 0 ;
	while (p!=-1)
	{

//	    cout<<"s:"<<s<<" s.len:"<<s.length()<<endl;
	    string tmp = s.substr(0,p);
	   // cout<<"tmp:"<<tmp<<endl;
	    if (tmp=="") break; 
	    if (tmp=="pair")
	    {
		preint = false;
	        s.erase(0,p+1);
		if (s.empty()&&cntp==1)
		{
		    puts("Error occurred");
		}
		cntp++;
		ans = ans + tmp;
		ans = ans + "<";
		left++;
	    }
	    else
	    {
	        s.erase(0,p+1);
		cnti++;
		ans = ans + tmp;
		if (s.empty()&&cnti==1&&cntp==0)
		{
		    puts("int");
		    return 0;
		}
		if (preint)
		{
		    ans = ans +">,";
		    right++;
		}
		else
		{
		    ans = ans + ",";
		}
		preint = true;
	    }
	    if (!s.empty()&&cntp<cnti)
	    {
//		cout<<"s:"<<s<<" cntp:"<<cntp<<" cnti:"<<cnti<<" s.len:"<<s.length()<<endl;
		puts("Error occurred");
		return 0;
	    }
//	    cout<<"ans:"<<ans<<"preint:"<<preint<<endl;

	    p = s.find(' ');
	}
//	cout<<"cntp:"<<cntp<<" cnti:"<<cnti<<endl;
	if (cntp!=cnti-1)
	{
	    puts("Error occurred");
	    return  0 ;
	}
	int len = ans.length();
	if (ans[len-1]==',')
	{
	    ans.erase(len-1,1);
	}
	while (right<left)
	{
	    ans = ans +">";
	    right++;
	}
	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
