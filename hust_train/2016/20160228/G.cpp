/* ***********************************************
Author :111qqz
Created Time :2016年02月28日 星期日 22时16分01秒
File Name :code/hust/20160628/G.cpp
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
string sa,sb;
int a[30],b[30];
int la,lb;
LL ans = 0;
int main()
{
	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
  #endif
	cin>>sa>>sb;
	la = sa.length();
	for ( int i = 0 ; i < la ; i++) a[i] = sa[la-i-1]-'0';
	lb = sb.length();
	for ( int i = 0 ; i < lb ; i++) b[i] = sb[lb-i-1]-'0';

	for ( int i = 0 ; i < lb-1 ; i++)
	{
	    if (b[i]==9) continue;
	    if (b[i+1]-1>=a[i+1])
	    {
	//	cout<<"i:::"<<i<<endl;
		int tmp = b[i+1]-1;
	//	cout<<"tmp:"<<tmp<<endl;
		if (b[i+2]-1>=b[i+1]) tmp = 9 ;
		if (i+1==lb-1&&tmp==0) tmp=1;
	//	cout<<"tmp2:"<<tmp<<endl;
		if (b[i]*b[i+1]<9*tmp)
		{
		    b[i] =  9;
	//	    cout<<"i:"<<i<<endl;
		    b[i+1]--;
		}
	    }

	}
	LL ans = 0 ;
	for ( int i = lb-1 ; i >= 0 ; i--)
	{
	    ans = ans*10+b[i];
	}

	LL ans2 = 0;
	for ( int i = 1 ; i <= lb-1 ; i++)
	{
	    ans2 = ans2*10+1;    
	}
	ans2*=9;
	if (la==lb) ans2=0;
	ans = max(ans,ans2);
	cout<<ans<<endl;


	
	


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

