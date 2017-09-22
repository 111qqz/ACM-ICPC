/* ***********************************************
Author :111qqz
Created Time :2016年03月18日 星期五 10时38分25秒
File Name :code/zoj/3494.cpp
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
const LL MOD = 1E9+7;
const int N=205;
map<int,string>mp;
set<string>se;
string l,r;
int digit[N];

struct bign
{
    int a[N];
    int len;
    biginit()
    {
	len = 1;
	ms(a,0);
    }
}
void pre()
{
    mp[0]="0000";
    mp[1]="0001";
    mp[2]="0010";
    mp[3]="0011";
    mp[4]="0100";
    mp[5]="0101";
    mp[6]="0110";
    mp[7]="0111";
    mp[8]="1000";
    mp[9]="1001";
}

int* st2dig(string n)
{
    int res[205];
    int len = n.length();
    for ( int i =  0 ; i < len ; i++)
    {
	res[len-i] = n[i]-'0';
    }
    return res;
}

bign sub(bign p)
{
    p.a[1]--;
    for ( int i = 1 ; i <= p.len -1 ; i++)
    {
	if (p.a[i]<0)
	{
	    p.a[i] ==10;
	    p.a[i+1]--;
	}
    }

    while (p.a[len]==0) p.len--;
}
LL solve (string n)
{
    int len = n.length();

    for ( int i =  0 ; i< len ; i++)
    {
	digit[len-i] = n[i]-'0';
    }
    //check
    for ( int i = len ;  i>= 1  ; i--)
    {
	cout<<digit[i];
    }
    return 0;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	ios::sync_with_stdio(false);
	pre();
	int T;
	cin>>T;
	while (T--)
	{
	    se.clear();
	    cin>>n;
	    string ban;
	    for ( int i = 0 ; i < n ; i++) 
	    {
		cin>>ban;
		se.insert(ban);
	    }

	    cin>>l>>r;
	    LL ans = solve(r) - solve(l);
	    ans %=mod;
	    ans +=mod;
	    ans %=mod;
	    cout<<ans<<endl;

	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
