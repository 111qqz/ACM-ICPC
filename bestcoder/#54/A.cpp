/*************************************************************************
	> File Name: code/bc/#54/A.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月05日 星期六 18时56分22秒
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
#include <cstdlib>
#include <sstream>
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
const int N=1E2+7;
struct Q
{
    string nam;
    int yea;
}q[N];
int n;
int str2num(string s)
{
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}
bool cmp(Q a,Q b)
{
    if (a.yea>b.yea) return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
  int T;
  cin>>T;
  while (T--)
    {
	int p;
	scanf("%d",&n);
	getchar();
	for ( int i = 0 ; i < n ; i++){
	    string tmp;
	    int len = tmp.length();
	    getline(cin,tmp);
//	    cout<<"tmp:"<<tmp<<endl;
	    p = tmp.rfind(' ',len-1);
//	    cout<<"p:"<<p<<endl;
	    q[i].nam=tmp.substr(0,p);
	    string ye=tmp.substr(p+1);
//	    cout<<"ye:"<<ye<<endl;
	    q[i].yea=str2num(ye);
	}
	sort(q,q+n,cmp);
//	for ( int i = 0 ; i < n ; i++){
//	    cout<<q[i].nam<<"   ";
//
//	    cout<<q[i].yea<<endl;
//	}
	for ( int i = 0 ; i < n ; i++){
	    cout<<q[i].nam<<endl;
	}
    }
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
