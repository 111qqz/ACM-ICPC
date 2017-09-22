/* ***********************************************
Author :111qqz
Created Time :2015年12月24日 星期四 00时32分33秒
File Name :code/cf/#336/B.cpp
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
const int N=3E5+7;
int la,lb;
char a[N],b[N];
int sum0[N],sum1[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	ms(sum0,0);
	ms(sum1,0);
	scanf("%s",a);
	scanf("%s",b);
	la = strlen(a);
	lb = strlen(b);
	int sum = 0 ;
	if (la==1)
	{
	    for ( int i = 0 ;  i < lb ; i++)
	    {
		if (b[i]!=a[0]) sum++;
	    }
	    cout<<sum<<endl;
	    return 0;

	}
	
	for ( int i = 0 ; i < lb ; i++)
	{
	    if (b[i]=='0')
	    {
		sum0[i+1] = sum0[i]+1;
		sum1[i+1] = sum1[i];
	    }
	    else
	    {
		sum1[i+1] = sum1[i] +1;
		sum0[i+1] = sum0[i];
	    }
	}
//	for ( int i = 1 ; i <= lb ; i++)
//	    cout<<sum0[i]<<" "<<sum1[i]<<endl;
	LL ans =  0;
	for (int i= 0 ;  i < la ; i++)
	{
	    if (a[i]=='0')
	    {
		ans+=LL(sum1[lb-la+i+1]-sum1[i]);
	    }
	    else
	    {
		ans+=LL(sum0[lb-la+i+1]-sum0[i]);
	    }
//	    cout<<ans<<endl;
	}

	cout<<ans<<endl;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
