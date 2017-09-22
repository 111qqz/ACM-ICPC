/*************************************************************************
	> File Name: code/cf/#317/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年08月23日 星期日 00时30分51秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
struct Q
{
    int val;
    int num;
    int id;
}b[N],s[N],ans[N];
int id[N];
int id2[N];
int n,ss;

bool cmp(Q a,Q b)
{
    if (a.val<b.val)
	return true;
    return false;
}
bool cmp2(Q a,Q b)
{
    if (a.val>b.val) return true;
    return false;
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin); 
  #endif
    cin>>n>>ss;
    int x,y;
    char order;
    ms(b,0);
    ms(s,0);
    ms(id,0);
    ms(id2,0);
    int cntA=0,cntB= 0 ;
    for ( int i  = 0  ; i < n ; i++){
	cin>>order>>x>>y;
	if (order=='B'){
	    if (id[x]==0)
	    {
		cntA++;
		id[x] = cntA;
	    }
	    b[id[x]].num = b[id[x]].num + y;
	    b[id[x]].val = x;
	    b[id[x]].id = id[x];
	}
	else
	{
	    if (id2[x]==0)
	    {
		cntB++;
		id2[x] = cntB;
	    }
	    s[id2[x]].num = s[id2[x]].num+y;
	    s[id2[x]].val = x;
	    s[id2[x]].id = id2[x];
	}
    }
    sort(s+1,s+cntB+1,cmp);
    sort(b+1,b+cntA+1,cmp2);
    cntA = min(cntA,ss);
    cntB = min(cntB,ss);
    ms(ans,0);
    for ( int i = 1 ; i <= cntB ; i++){
	ans [i].val = s[i].val;
	ans[i].num = s[i].num;
    }
    sort(ans+1,ans+cntB+1,cmp2);
    for ( int i = 1; i <= cntB ; i++){
	cout<<"S "<<ans[i].val<<" "<<ans[i].num<<endl;
    }
    ms(ans,0);
    for ( int i =  1 ; i <= cntA ; i++){
	ans[i].val = b[i].val;
	ans[i].num = b[i].num;
    }
    sort(ans+1,ans+cntA+1,cmp2);
    for ( int i = 1 ; i <= cntA ; i++){
	cout<<"B "<<ans[i].val<<" "<<ans[i].num<<endl;
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
