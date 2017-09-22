/* ***********************************************
Author :111qqz
Created Time :2016年03月09日 星期三 18时39分06秒
File Name :code/class/algorithm/radix.cpp
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
const int N=1E2+7;
const int base = 10;

int n ;
int a[N];
int max_bit( int num)
{
    int res = 0 ;
    while (num)
    {
	num/=10;
	res++;
    }
    return res;
}


int MAX( int a[], int n)
{
    int mx = -inf;
    for ( int i = 0 ; i< n;  i++)
    {
	mx = max(a[i],mx);
    }
    return mx;
}
void radix_sort( int a[],int n)
{
    int b[N];

    int c[N];
    int radix = 1;
    int t;
    int d = max_bit(MAX(a,n));

  //  cout<<"d:"<<d<<endl;
    for ( int i = 0 ; i < d ; i++,radix*=10)
    {
	for ( int j = 0 ; j <= 10 ; j ++) c[j]  = 0;

	for ( int j = 0 ; j < n ; j++)
	{
	    t = a[j]/radix % 10;
	    c[t]++;
	}
	for ( int j = 1 ; j < 10 ; j++)
	    c[j] += c[j-1];

	for ( int j = n-1 ; j >= 0 ; j--)
	{
	    t = a[j] /radix % 10;
	    b[c[t]-1] = a[j];
	    c[t]--;
	}

	for ( int j = 0 ; j < n ; j++)
	    a[j] = b[j];
    }
    

}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 0 ; i <  n ; i++) cin>>a[i];

	for ( int i = 0 ; i < n;  i++) cout<<a[i]<<" ";

	cout<<endl;
	radix_sort(a,n);
	for ( int i = 0 ; i < n ; i++) cout<<a[i]<<" ";

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
