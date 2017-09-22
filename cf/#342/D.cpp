/* ***********************************************
Author :111qqz
Created Time :2016年02月07日 星期日 18时28分39秒
File Name :code/cf/#342/D.cpp
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
#include <sstream>
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
bool vis[N];

void pre()
{
    ms(vis,false);
    for ( int i = 10 ; i <12000 ; i++)
    {
	int vala = i ;
	stringstream ss;
	ss<<vala;
	string tmp = ss.str();
	
	reverse(tmp.begin(),tmp.end());

	int valb;
	sscanf(tmp.c_str(),"%d",&valb);
//	cout<<i<<" "<<vala+valb<<endl;
	if (vala+valb<N) vis[vala+valb] = true;
	
    }

    for ( int i = 1 ; i <  N ; i++)
    {
	if (vis[i]) cout<<i<<endl;
    }
}
char ans[N],s[N];
int n;
int sum[N];

bool ok()
{
 //   cout<<"n:"<<n<<endl;
    for ( int i = 0 ; i < n/2 ;)
    {
	int l = i ;
	int r = n-1-i;
	if (sum[l]==sum[r]) i++;
	else if (sum[l]==sum[r]+1||sum[l]==sum[r]+11)
	{
	    sum[l]--;
	    sum[l+1]+=10;
	}
	else if (sum[l]==sum[r]+10)
	{
	    sum[r-1]--;
	    sum[r]+=10;

	}
	else return false;
    }

    if (n%2==1)
    {
	if (sum[n/2]%2==1) return false;
	if (sum[n/2]>18||sum[n/2]<0) return false;
	ans[n/2] = char(sum[n/2]/2 +'0');
//	cout<<"ASDHJKASD"<<endl;
    }
    for ( int i = 0 ; i < n/2 ; i++)
    {
	if (sum[i]<0||sum[i]>18) return false;
	ans[i] =(sum[i]+1)/2+'0';
	ans[n-1-i] =sum[i]/2+'0';
    }
    return ans[0]>'0';
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	//pre();
	//
	
	scanf("%s",s);
	n = strlen(s);
	for ( int i = 0 ; i < n ; i++) sum[i] = s[i] - '0';
	if (ok())
	{
	    cout<<ans<<endl;
//	    cout<<"aaa"<<endl;
	    return 0;
	}

	if (s[0]=='1'&&n>1)
	{
	    for ( int i = 0 ; i < n ; i++)
		sum[i] = s[i+1]-'0';
	    sum[0]+=10;
	    n--;
	    if (ok())
	    {
		cout<<ans<<endl;
		return 0;
	    }
	    else
		puts("0");
	}
	else puts("0");
	

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
