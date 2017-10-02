/* ***********************************************
Author :111qqz
Created Time :2017年10月02日 星期一 13时02分02秒
File Name :K.cpp
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
struct node{
    int d,m,y,id;
    
    bool operator < (const  node &b)const
    {
	if (y==b.y)
	{
	    if (m==b.m)
	    {
		return d<b.d;
	    }
	    return m<b.m;
	}
	return y<b.y;
    }
    bool operator == (const node &b)const
    {
	return y==b.y && m==b.m && d==b.d;
    }

}son[110],king;

int main(){
    int n;
    freopen("king.in","r",stdin);
    freopen("king.out","w",stdout);
    scanf("%d%d%d%d",&king.d,&king.m,&king.y,&n);
    for(int i=1;i<=n;i++){
	scanf("%d%d%d",&son[i].d,&son[i].m,&son[i].y);
	son[i].id=i;
    }
    sort(son+1,son+n+1);
    king.y-=18;
    int isok=1;
    for(int i=n;i>=1;i--){
	if(son[i]<king||son[i]==king){
	    printf("%d\n",son[i].id);
	    isok=0;
	    break;
	}
    }
    if(isok) printf("-1\n");
    return 0;
}

