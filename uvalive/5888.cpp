/* ***********************************************
Author :111qqz
Created Time :2016年08月19日 星期五 23时30分34秒
File Name :code/uvalive/5888.cpp
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
int opt[N];
LL val[N];
int n;
string s;
void read(int i,string cmd)
{
  //  cout<<"i:"<<i<<" cmd:"<<cmd<<endl;
    if (cmd=="NUM")
    {
	opt[i] = 0;
	scanf("%lld",&val[i]);
    }
    if (cmd=="POP") opt[i] = 1;
    if (cmd=="INV") opt[i] = 2;
    if (cmd=="DUP") opt[i] = 3;
    if (cmd=="SWP") opt[i] = 4;
    if (cmd=="ADD") opt[i] = 5;
    if (cmd=="SUB") opt[i] = 6;
    if (cmd=="MUL") opt[i] = 7;
    if (cmd=="DIV") opt[i] = 8;
    if (cmd=="MOD") opt[i] = 9;
}
bool ok( LL x)
{
    stack<LL>stk;
    stk.push(x); 
    for ( int i = 1 ; i <= n ; i++)
    {
//	cout<<"i:"<<i<<" opt[i]:"<<opt[i]<<endl;
	if (opt[i]==0) stk.push(val[i]);
	else if (stk.empty()) return false;
	else if (opt[i]==1) stk.pop();
	else if(opt[i]==2) {LL tmp = stk.top();stk.pop();stk.push(-tmp);}
	else if (opt[i]==3){LL tmp = stk.top();stk.push(tmp);}
	else if(int(stk.size())<2) return false;
	else if (opt[i]==4){LL x = stk.top();stk.pop();LL y = stk.top();stk.pop();stk.push(x);stk.push(y);}
	else if (opt[i]==5){LL x = stk.top();stk.pop();LL y = stk.top();stk.pop();stk.push(x+y);}
	else if(opt[i]==6) {LL x = stk.top();stk.pop();LL y = stk.top();stk.pop();stk.push(y-x);}
	else if (opt[i]==7){LL x = stk.top();stk.pop();LL y = stk.top();stk.pop();stk.push(x*y);}
	else if(stk.top()==0LL) return false;
	else if(opt[i]==8){LL x = stk.top();stk.pop();LL y = stk.top();stk.pop();stk.push(y/x);}
	else if(opt[i]==9){LL x = stk.top();stk.pop();LL y = stk.top();stk.pop();stk.push(y%x);}
	if (!stk.empty()&&(stk.top()>1LL*1E9||stk.top()<-1LL*1E9)) return false;
    }
    int siz = stk.size();
    if (siz==0||siz>1) return false;
    printf("%lld\n",stk.top());
    return true;
    
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	while (1)
	{
	    n = 0 ;
	    while (cin>>s&&s!="END"&&s!="QUIT") read(++n,s);
	    if (s=="QUIT") break;
	    int q;
	    scanf("%d",&q);
	    while (q--)
	    {
		LL x;
		scanf("%lld",&x);
		if (!ok(x)) puts("ERROR");
	    }
	    printf("\n");
	}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
