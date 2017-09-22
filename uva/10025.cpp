/* ***********************************************
Author :111qqz
Created Time :2016年01月28日 星期四 13时58分24秒
File Name :code/uva/10025.cpp
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
int k;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	cin>>T;
	while (T--)
	{
	    scanf("%d",&k);
	    if (k<0) k = -k;
	

	    int sum = 0  ;
	    int p = int(sqrt(2*k));

//	    cout<<"p:"<<p<<endl;
	    for ( int i = p ; ;i++)
	    {
		sum = (1+i)*i/2;
		
	    
		if (sum>=k&&(sum-k)%2==0&&sum>0)
		{
		    cout<<i<<endl;
		    break;
		}
	    }
	    if (T)
	    {
		puts("");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
