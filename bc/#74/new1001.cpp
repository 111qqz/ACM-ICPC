/* ***********************************************
Author :111qqz
Created Time :2016年03月05日 星期六 20时25分11秒
File Name :code/bc/#74/new1001.cpp
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
int pos[6];
int n,m;
long long answer;
int dist[6][6];
int search(int x,int y){
    if(y == x + 3){
	if(pos[y] != pos[x])return (dist[x][y] = 1);
	else return (dist[x][y] = 0);
    }
    if(dist[x][y] != inf)return dist[x][y];
    int px = pos[x],py = pos[y];
    if(px > py)swap(px,py);
    for(int i = 0; i < 3; i++){
	if(pos[i] >= px && pos[i+3] <= py){
	    dist[x][y] = min(dist[x][y],search(i,i+3)+pos[i] -px + py - pos[i+3]);
	}
    }
    return dist[x][y];
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	//freopen("code/in.txt","r",stdin);
  #endif
    int T,aa,bb,ans;scanf("%d",&T);
    while(T--){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d%d",&pos[0],&pos[3],&pos[1],&pos[4],&pos[2],&pos[5]);
	answer = 0;
	ans = inf;
	memset(dist,0x3f,sizeof(dist));
	for(int i = 0; i < 3; i++)if(pos[i] > pos[i+3])swap(pos[i],pos[i+3]);
	for(int i = 0; i < 6; i++){
	    for(int j = i+1; j < 6; j++){
		dist[i][j] = abs(pos[j] - pos[i]);
		search(i,j);
		//printf("dist from %d to %d = %d\n",i,j,dist[i][j]);
	    }
	}
	for(int i = 1; i <= m; i++){
	    scanf("%d%d",&aa,&bb);
	    if(aa > bb)swap(aa,bb);
	    if(aa == bb)continue;
	    ans = bb-aa;
	    for(int j = 0; j <= 2; j++){
		for(int k = 3; k <= 5; k++){
		    ans = min(ans,abs(pos[j]-aa)+abs(pos[k]-bb)+dist[j][k]);
		}
	    }
	    answer = answer + (long long)(ans) * (long long)(i);
	}
	printf("%lld\n",answer);
}
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
