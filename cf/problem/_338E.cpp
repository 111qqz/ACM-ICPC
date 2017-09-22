/* ***********************************************
Author :111qqz
Created Time :Thu 15 Sep 2016 04:35:05 PM CST
File Name :code/cf/problem/_338E.cpp
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
const int N=1005;
int n,len,h;
int a[N],b[N];

int cal(int *s,int *b,int h,int index)
{
    if (index==len+1) return 1;
    for ( int i = 1 ; i <= len ; i++)
    {
	if (s[index]+b[i]>=h)
	{
	    int mem = b[i];
	    b[i] = 0 ;
	    int res = cal(s,b,h,index+1);
	    b[i] = mem;
	    if (res>0) return 1;
	}
    }
    return 0;
}
int getAns(int *a,int *b,int h)
{
    int res = 0 ;
    int tmp[N];
    for ( int i = 1 ; i <= n-len+1 ; i++)
    {
	memcpy(tmp+1,a+i,len*4);
	//for ( int i = 1; i  <= 2*len ; i++) cout<<"tmp[i]:"<<tmp[i]<<" ";
	//cout<<endl;
	res+=cal(tmp,b,h,1);
	cout<<i<<" "<<"res:"<<res<<endl;
    }
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>len>>h;
	for ( int i = 1; i <=len ; i++) cin>>b[i];
	for ( int i = 1; i <= n  ; i++) cin>>a[i];
	cout<<getAns(a,b,h)<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
} 
