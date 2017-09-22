/* ***********************************************
Author :111qqz
Created Time :2016年01月19日 星期二 20时10分31秒
File Name :code/cf/problem/614B.cpp
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
const int N=1E5+7;
int n;
string a[N];
string ugly;
int num ;
int b[6]={1,10,100,1000,10000,100000};
bool is_pretty(string st)
{
    int cnt = 0 ;
    int len = st.length();
    for ( int i = 0 ; i < len ; i++)
    {
	if (st[i]!='1'&&st[i]!='0') return false;
	if (st[i]=='1') cnt++;
	if (cnt>=2) return false;
    }
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n;
	ugly ="1";
	for ( int i = 0 ;i < n ; i++) cin>>a[i];
	for ( int i = 0 ; i < n ; i++)
	{
	    if (a[i]=="0") 
	    {
		puts("0");
		return 0;
	    }
	    if (!is_pretty(a[i]))
	    {
		ugly = a[i];
		continue;
	    }
	    num+=a[i].length()-1;
	}
	cout<<ugly;
	for ( int i = 1 ; i <= num ; i++) printf("%d",0);
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
