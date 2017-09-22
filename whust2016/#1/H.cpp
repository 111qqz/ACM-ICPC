/* ***********************************************
Author :111qqz
Created Time :2016年08月07日 星期日 15时18分53秒
File Name :code/whust/2016/#1/H.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <deque>
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
const int N=1E4+7;
int n;
int len;
string st;
int up[N],low[N];
int ans[N];
int s[N];
int plow[N],pup[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	
	cin>>n;
	cin>>st;
	ms(up,0);
	ms(low,0);
	ms(ans,0);
	n*=2;
	int cntup = 0;
	int cntlow = 0 ;
	for ( int i = 0 ; i <n ; i++)
	{
//	    cout<<st[i]<<endl;
	    if (st[i]>='a'&&st[i]<='z') low[st[i]-'a'+1]++;
	    else up[st[i]-'A'+1]++;
	    
	    if (st[i]>='a'&&st[i]<='z')
	    {
		cntlow++;
		plow[i] = cntlow;
	    }
	    else
	    {
		cntup++;
		pup[i] = cntup;
	    }

	}

//	for ( int i = 0 ; i < n ; i++) cout<<pup[i]<<" "<<plow[i]<<endl;
	for ( int i = 0 ; i <n ; i++) s[i] = st[i];
	for ( int i = 1 ; i <= 26 ; i++)
	    if (up[i]!=low[i])
	    {
//		cout<<i<<" "<<up[i]<<" "<<low[i]<<endl;
		puts("Impossible");
		return 0;
	    }


	int i = 0 ;
	int j = n-1;
	while (i<n&&j>=0)
	{
	    if (s[i]+32==s[j])
	    {
		ans[pup[i]]=plow[j];
	//	cout<<"s[i]:"<<s[i]<<" s[j]:"<<s[j]<<endl;
		i++;
		j--;
		continue;
	    }
	    if (s[j]+32==s[i])
	    {
		ans[pup[j]] = plow[i];
		i++;
		j--;
		continue;
	    }
	    if (i+1<n&&s[i]+32==s[i+1])
	    {
		ans[pup[i]] = plow[i+1];
		i+=2;
		continue;
	    }
	    if (i+1<n&&s[i+1]+32==s[i])
	    {
		ans[pup[i+1]]=plow[i];
		i+=2;
		continue;
	    }
	    if (j-1>=0&&s[j]+32==s[j-1])
	    {
		ans[pup[j]] = plow[j-1];
		j-=2;
		continue;
	    }
	    if (j-1>=0&&s[j-1]+32==s[j])
	    {
		ans[pup[j-1]] = plow[j];
		j-=2;
		continue;
	    }
	    puts("Impossible");
	    return 0;
	   // cout<<"i:"<<i<<" j:"<<j<<endl;

	}
	for ( int  i = 1 ; i <n/2 ; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n/2]);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

