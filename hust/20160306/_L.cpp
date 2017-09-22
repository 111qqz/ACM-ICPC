/* ***********************************************
Author :111qqz
Created Time :2016年03月06日 星期日 15时00分14秒
File Name :code/hust/20160306/_L.cpp
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
LL sum[6];

int BitCount4(unsigned int n) 
{ 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ; 
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ; 
    n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ; 
    n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ; 

    return n ; 
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("code/in.txt","r",stdin);
  #endif
    while(1){

	int counte = 0,a,b,cccc;
	ms(sum,0);
	int ccnt= 0 ;
	cin >> a >> b >> cccc;
	for ( int i = a ; i <= b ; i++)
	{
	    int cur = i;
	    int cnt = 0 ;
	    while(cur!=1)
	    {
		cnt ++;
		cur = BitCount4(cur);
	    }
	    sum[cnt]++;
	    
	    if (cnt==cccc)
	    {
		//cout<<"i:"<<i<<"   cnt:"<<cnt<<" "<<"sum[cnt]:"<<sum[cnt]<<endl;
		counte ++;
	    }
	  //  cout<<"ccnt:"<<ccnt<<endl;
	}
	cout << counte << endl;

    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
