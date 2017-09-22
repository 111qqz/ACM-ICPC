/* ***********************************************
Author :111qqz
Created Time :2016年01月19日 星期二 19时47分47秒
File Name :code/cf/problem/614A.cpp
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
LL l,r,k;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>l>>r>>k;
	LL cur = 1;
	bool out = false;
	while (cur<=r)
	{
	 //   cout<<"cur:"<<cur<<endl;
	    if (cur>=l) cout<<cur<<" ",out = true;
	    if (cur>1E18/k) break;
	    cur*=k;
	}
	if (!out)
	{
	    puts("-1");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
