/* ***********************************************
Author :111qqz
Created Time :2016年03月03日 星期四 14时20分14秒
File Name :code/poj/3087.cpp
************************************************ */

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
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
map<string,int>d;
string st1,st2,tar;
int n;
bool flag;
string add(string a,string b)
{
    string res="";
    int len = a.length();
    for ( int i = 0 ; i < len ; i++ )
    {
	  res+=b[i];
	  res+=a[i];
    }
    return res;
}
void bfs()
{
    queue<string>q;
    string str=add(st1,st2);
    q.push(str);
    d[str]=1;
    while (!q.empty())
    {
	  string pst = q.front();
	  q.pop();
	  if (pst==tar)
	  {
		flag = true;
		return;
	  }
	  string s1=pst.substr(0,n);
	  string s2=pst.substr(n,n);
	  string tmps = add(s1,s2);
	  if (d[tmps]>0) 
	  {
		flag = false;
		return;
	  }
	  d[tmps]=d[pst]+1;
	  q.push(tmps);
    }
}
int main()
{
    int T;
    int cas = 0;
    cin>>T;

    while (T--)
    {
	  d.clear();
	  cas++;
	  cin>>n;
	  cin>>st1>>st2>>tar;
	  bfs();
	  if (flag)
	  {
		cout<<cas<<" "<<d[tar]<<endl;
	  }
	  else
	  {
		cout<<cas<<" "<<-1<<endl;
	  }
    }
  
	return 0;
}
