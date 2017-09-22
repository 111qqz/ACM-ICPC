/* ***********************************************
Author :111qqz
Created Time :2016年03月19日 星期六 00时21分02秒
File Name :code/cf/croc2016/A.cpp
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
string a,b,c,d;
int kind (string a,string b)
{
    if (a=="AB") return 1;
    if (a=="BC") return 1;
    if (a=="CA") return 1;
    if (b=="AC") return 1;
    if  (b=="BA") return 1;
    if (b=="CB") return 1;

    return 2;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>a>>b>>c>>d;
	int p = kind(a,b);
	int q = kind(c,d);
	if (p==q)
	{
	    puts("YES");
	}
	else
	{
	    puts("NO");
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
