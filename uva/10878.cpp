/* ***********************************************
Author :111qqz
Created Time :2016年01月25日 星期一 09时40分29秒
File Name :code/uva/10878.cpp
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
string mat[50]={"| o   .  o|","| oo  . o |","| oo o.  o|","| oo  .o  |","| oo  .o o|","| oo  .oo |","| oo  .ooo|",
"| oo o.   |",};
string matc[50]={"| o   .  o|",
    "|  o  .   |",
	"| ooo .  o|",
	"| ooo .o o|",
	"| oo o.  o|",
	"| oo  . oo|",
	"| oo o. oo|",
	"|  o  .   |",
	"| oo  . o |",
	"| ooo . o |",
	"| oo o.ooo|",
	"| ooo .ooo|",
	"| oo o.oo |",
	"|  o  .   |",
	"| oo  .oo |",
	"| oo o.ooo|",
	"| oooo.   |",
	"|  o  .   |",
	"| oo o. o |",
	"| ooo .o o|",
	"| oo o.o o|",
	"| ooo .   |",
	"| ooo . oo|",
	"|  o  .   |",
	"| oo o.ooo|",
	"| ooo .oo |",
	"| oo  .o o|",
	"| ooo . o |",
	"|  o  .   |",
	"| ooo .o  |",
	"| oo o.   |",
	"| oo  .o o|",
	"|  o  .   |",
	"| oo o.o  |",
	"| oo  .  o|",
	"| oooo. o |",
	"| oooo.  o|",
	"|  o  .   |",
	"| oo  .o  |",
	"| oo o.ooo|",
	"| oo  .ooo|",
	"|  o o.oo |",
	"|    o. o |"};
map<string,char>mp;
string ori="A quick brown fox jumps over the lazy dog.";
int len;
string tar;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	len = ori.length();
	//cout<<"len:"<<len<<endl;
	mp.clear();
	for ( int i = 0 ; i < len ; i ++)
	{
	    mp[matc[i]]=ori[i];
	}

	while (getline(cin,tar))
	{
	    int p = tar.find('|');
	    if (p==-1) continue;
	    printf("%c",mp[tar]);
	}


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
