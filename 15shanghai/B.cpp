/* ***********************************************
Author :111qqz
Created Time :Sun 16 Oct 2016 02:35:43 PM CST
File Name :code/15shanghai/B.cpp
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

int k;
LL n;
int t,cas;
int odd;
LL pow2[105];
int ans[105];

void init(){
    pow2[0]=1LL;
    for(int i=1;i<=60;i++){
	pow2[i]=(pow2[i-1]<<1); 
    }
}

void solve(){
    printf("Case #%d:\n",cas);
    memset(ans,0,sizeof(ans));
    int flag=0;
    odd=0;
    if(n==1&&k==1){
	printf("1 +\n");return;
    }
    if(n%2==0){
	odd=1;n--;
    }
    for(int i=k-1;i>=0;i--){
	if(n>=pow2[i]){
	    n-=pow2[i];
	    ans[i]=1;
	    ans[i]^=flag;
	    continue;
	}
	if(n<pow2[i]){
	    n=(pow2[i]-n);
	    ans[i]=1;
	    ans[i]^=flag;
	    flag^=1;
	    continue;
	}
    }
        for(int i=0;i<=k-2;i++){
		if(ans[i]==1) printf("%lld +\n",pow2[i]);
		else printf("%lld -\n",pow2[i]);
        }
    if(odd==1){
	if(ans[k-1]==1)	printf("%lld +\n",pow2[k-1]+1);
	else printf("%lld -\n",pow2[k-1]+1);
    }
    else{
	if(ans[k-1]==1) printf("%lld +\n",pow2[k-1]);
	else printf("%lld -\n",pow2[k-1]);
    }
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
    init();
    scanf("%d",&t);
    cas=0;
    while(t--){
	cas++;
	scanf("%lld%d",&n,&k);
	solve();
    }

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
