/* ***********************************************
Author :111qqz
Created Time :2016年08月11日 星期四 01时29分02秒
File Name :code/poj/3080.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=70;
int nxt[N];
string dna[15];
int n ;
void getnxt( string a)
{
    int i = 0 ;
    int j = -1;
    int n = a.length();
    nxt[0] = -1;
    while (i<n)
	if (j==-1||a[i]==a[j]) nxt[++i]=++j;
	else j = nxt[j];
}
bool kmp(string a,string b)
{
    int m = a.length();
    int n = b.length();
    getnxt(a);
    int i = 0;
    int j = 0;
    while (i<n)
    {
	if (j==-1||a[j]==b[i]) i++,j++;
	else j=nxt[j];
	if (j==m) return true;
    }
    return false;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while (T--)
	{
	    cin>>n;
	    for ( int i = 1 ; i <= n ; i++) cin>>dna[i];
	    string ans="";
	    int len = dna[1].length();
	    //cout<<"len:"<<len<<endl;
	    for ( int i = 0 ; i < len ; i++)
		for ( int j = 1 ; i+j-1 < len ;j++)
		{
		    bool match = true;
		    string tmp = dna[1].substr(i,j);
		   // cout<<"tmp:"<<tmp<<endl;
		
		    for ( int k = 2 ; k <= n; k++)
			if (!kmp(tmp,dna[k]))
			{
			    match = false;
			    break;
			}
		    if (match)
		    {
	//		cout<<"ccc"<<endl;
			if (tmp.length()>ans.length())
			    ans = tmp;
			else if (tmp.length()==ans.length()&&tmp<ans)
			    ans = tmp;
		    }
		}
		    if (ans.length()<3)
			cout<<"no significant commonalities"<<endl;
		    else
		        cout<<ans<<endl;
    
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
