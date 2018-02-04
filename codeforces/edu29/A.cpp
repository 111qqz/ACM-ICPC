/* ***********************************************
Author :111qqz
Created Time :2017年09月24日 星期日 13时51分06秒
File Name :A.cpp
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
#define PB push_back
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
bool check( int x)
{
    vector<int>val;
    while (x)
    {
	int tmp = x%10;
	val.push_back(tmp);
	x/=10;
    }
    int siz = val.size();
    if (siz==1) return true;
    for ( int i = 0 ; i < siz/2 ; i++)
    {
	if (val[i]!=val[siz-1-i]) return false;
    }
    return true;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("./in.txt","r",stdin);
  #endif
	int x;
	cin>>x;
	while(x%10==0)
	{
	    x/=10;
	}
	if (check(x)) puts("YES");
	else puts("NO");


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
