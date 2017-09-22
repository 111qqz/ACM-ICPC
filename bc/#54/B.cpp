/*************************************************************************
	> File Name: code/bc/#54/B.cpp
	> Author: 111qqz
	> Email: rkz2013@126.com 
	> Created Time: 2015年09月05日 星期六 18时55分43秒
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
const int N=1E2+7;
int n;
bool ok;
LL ans;
int a[N];
int cnt;
int p[654321];
map<int,int>mp;
map<int,int>::iterator it,it2;
void solve(int n){
    for ( int i = 2 ; i<= n ; i++){
	
	while (n%i==0){
//	    cout<<i<<endl;
	    if (mp[i]!=0){
		mp[i]++;
	    }
	    else{
		mp[i] = 1;
	    }
	    n = n / i;
	}
	
    }
}
int main()
{
  #ifndef  ONLINE_JUDGE 
//    freopen("in.txt","r",stdin); 
  #endif
    int T;
    cin>>T;
    while (T--){
	ans = 0 ;
	mp.clear();
	ok = false;
	scanf("%d",&n);
	for ( int i = 0 ; i< n ; i++){
	    scanf("%d",&a[i]);
	    solve(a[i]);
	}

    
    for (it=mp.begin();it!=mp.end();it++){
	if (it->second!=1){
	    int tmp = it->first;
	    ok = true;
	    ans = tmp*tmp;
	    
	    break;
	}
    }
    bool quit=false;
    for (it=mp.begin() ;it!=mp.end();it++){
	if (quit) break;
	for (it2 =it++; it2!=mp.end();it2++){
	    int tmp1 = it->first;
	    int tmp2 = it2->second;
	    if (tmp1*tmp2<ans||ans == 0)
	    {
		cout<<"tmp1:"<<tmp1<<endl;
		cout<<"tmp2:"<<tmp2<<endl;
		ans = tmp1*tmp2;
		cout<<"yeah2"<<endl;
		quit = true;
		ok = true;
		break;
	    }
	}
    }

    
    if (!ok)
    {
	puts("-1");
    }
    else
    {
	cout<<ans<<endl;
    }
    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
