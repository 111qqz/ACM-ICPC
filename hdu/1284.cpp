/* ***********************************************
Author :111qqz
Created Time :2016年02月27日 星期六 16时10分40秒
File Name :code/hdu/1284.cpp
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
const int N=4E4+7;
int tmp[N],a[N];
int n;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif


	    n = 32767;
	    ms(a,0);
	    ms(tmp,0);
	    for ( int i = 0 ; i <= n ; i++)
	    {
		a[i] = 1;
	    }


	    for ( int i = 2 ; i <= 3 ; i++)
	    {
		for ( int j = 0 ; j <= n ; j++)
		{
		    for ( int k = 0 ; k+j <= n ; k+=i)
		    {
			tmp[k+j] += a[j];
		//	cout<<"aa"<<endl;
		    }
		}
		
		for ( int j = 0  ;  j <= n ; j++)
		{
		    a[j] = tmp[j];
		    tmp[j]  = 0;
		}
		
	    }


	    while (~scanf("%d",&n))
	    {
		printf("%d\n",a[n]);
	    }
    

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
