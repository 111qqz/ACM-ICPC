/* ***********************************************
Author :111qqz
Created Time :2016年01月31日 星期日 22时02分47秒
File Name :code/cf/#341/C.cpp
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
#include <iomanip>
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
int n ;
int p;
int l[N],r[N];
double len[N];
double cnt[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	cin>>n>>p;
	ms(cnt,0);
	ms(len,0);
	for ( int i = 0 ;i  < n ; i++)
	{
	    scanf("%d %d",&l[i],&r[i]);
	    len[i] = r[i]-l[i]+1;
	}

	for ( int i = 0 ;i  < n ; i++)
	{
	   cnt[i] = r[i]/p - (l[i]-1)/p;
	}
	double sum = 0 ;
//	for ( int i = 0 ;i < n ; i++) cout<<cnt[i]<<endl;
	for ( int i = 0 ; i < n ; i++)
	{
	    int j = (i+1)%n;
	    sum +=1- ((len[i]-cnt[i])/len[i]*1.0)*((len[j]-cnt[j])/len[j]*1.0);
	}
	cout<<fixed<<setprecision(6)<<sum*2000<<endl;
	//printf("%.8lf\n",sum*2000);

	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
