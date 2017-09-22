/* ***********************************************
Author :111qqz
Created Time :Wed 21 Sep 2016 04:00:39 PM CST
File Name :code/hdu/2521.cpp
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
const int N=5005;
int num[N];
int factor( int n)
{
    if (n==1) return 1;
    int res = 2 ;
    int mx = n;
    for ( int i = 2 ; i < mx ; i++)
	if (n%i==0)
	    res = n/i==i?(res+1):(res+2),mx=n/i;
    return res;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	for ( int i = 1 ; i <= 5000 ; i++) num[i] = factor(i);
//	for ( int i = 1 ; i <= 200 ; i++) cout<<i<<" "<<num[i]<<endl;
	int T;
	cin>>T;
	while (T--)
	{
	    int a,b;
	    scanf("%d%d",&a,&b);
	    int ans;
	    int mx = -1;
	    for ( int i = a; i <= b ;  i++)
	    {
		if (num[i]>mx)
		{
		    mx = num[i] ;
		    ans = i;
		//    cout<<"i:"<<i<<" mx:"<<mx<<endl;
		}
	    }
	    printf("%d\n",ans);
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
