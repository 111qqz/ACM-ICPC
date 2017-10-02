/* ***********************************************
Author :111qqz
Created Time :2017年10月02日 星期一 12时45分57秒
File Name :F.cpp
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
#define PB push_back
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
int ww,hh,w,h;
int main(){
    scanf("%d%d%d%d",&ww,&hh,&w,&h);
    if(ww<hh) swap(ww,hh);
    if(w<h) swap(w,h);
    if(ww<w || hh<h){
	printf("-1\n");
	return 0;
    }
    int sum1=0,sum2=0,W=ww,H=hh;
    while(ww>w){
	ww=(ww+1)/2;
	sum1++;
    }
    while(hh>h){
	hh=(hh+1)/2;
	sum1++;
    }
    while(W>h){
	W=(W+1)/2;
	sum2++;
    }
    while(H<w){
	H=(H+1)/2;
	sum2++;
    }
    printf("%d\n",min(sum1,sum2));
    return 0;
}

