/* ***********************************************
Author :111qqz
Created Time :2016年01月20日 星期三 16时00分57秒
File Name :code/uva/401.cpp
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
string a,b;
char tmp[1000005];
map<char,char>mp;
void init()
{
    mp.clear();
    mp['A']='A';

    mp['E']='3';
    mp['3']='E';

    mp['H']='H';
    mp['I']='I';

    mp['J']='L';
    mp['L']='J';

    mp['M']='M';
    mp['O']='O';
    mp['0']='O';

    mp['S']='2';
    mp['2']='S';

    mp['T']='T';
    mp['U']='U';
    mp['V']='V';
    mp['W']='W';
    mp['X']='X';
    mp['Y']='Y';

    mp['Z']='5';
    mp['5']='Z';

    mp['1']='1';
    mp['8']='8';
}

void solve ( bool x,bool y)
{
    if (!x&&!y) puts(" -- is not a palindrome.");
    if (x&&y) puts(" -- is a mirrored palindrome.");
    if (x&&!y) puts(" -- is a regular palindrome.");
    if (!x&&y) puts(" -- is a mirrored string.");
}

bool pal(string x)
{
    int len = x.length();
    for ( int i = 0 ; i< len/2  ; i++)
    {
	if (x[i]!=x[len-1-i]) return false;
    }
    return true;
}
bool mirr(string x,string y)
{
    int len = x.length();
    for ( int i = 0 ; i < len/2 ;  i++)
    {
	if (x[i]!=y[len-1-i]) return false;
    }
    return true;
}
int main()
{

	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	init();
	while (scanf("%s",tmp)!=EOF)
	{
	    a = tmp;
	    bool ok1 = false;
	    bool ok2 = false;
	    b = a;
	    reverse(b.begin(),b.end());
	//    cout<<"rb:"<<b<<endl;
	    if (a==b) ok1= true;
	    ok1 = pal(b);
	    int len = b.length();
//	    cout<<"反转的b::"<<b<<endl;
	    int cnt = 0 ;
	    for ( int i = 0 ; i < len ; i++ )
	    {
		if (mp.count(b[i])==1)
		{
		    cnt++;
		    b[i] = mp[b[i]];
		}
	    }
	//    cout<<"mirrb:"<<b<<endl;
	    cout<<a;
	    if (a==b&&cnt==len) ok2=true;

	    
	    solve(ok1,ok2);
	    
	    cout<<endl;
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
