
/* ***********************************************
Author :111qqz
Created Time :Wed 12 Oct 2016 08:43:02 PM CST
File Name :code/poj/1061.cpp
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

int n;
char str[505][2005];
int len[505];
int nxt[505][2005];

int ans,minid;

void getnxt(){
    memset(nxt,0,sizeof(nxt));
    int i,j,k;
    minid=-1;
    ans=-1;
    for(i=0;i<n;i++) len[i]=strlen(str[i]);
   // for(i=0;i<n;i++) cout<<len[i]<<endl;

    for(i=0;i<n-1;i++){
	nxt[i][0]=-1;
	j=0;k=-1;
	while(j<len[i]){
	    if(k==-1||str[i][j]==str[i][k]) nxt[i][++j]=++k;
	    else k=nxt[i][k];
	}
    }
/*    for(i=0;i<n;i++)
    {
	for(j=0;j<len[i];j++)
	    cout<<nxt[i][j]<<' ';
	cout<<endl;
    }
*/

}

bool kmp(int x,int y){
    int i,j;
    i=0;j=0;
    while(i<len[x]){
	if(j==-1||str[x][i]==str[y][j]) ++i,++j;
	else j=nxt[y][j];
	if(j==len[y]) return true;
    }
    return false;
}


bool dfs(int x){
   // printf("%d\n",x);
    for(int i=x-1;i>=0;i--){
//	printf("%d\n",i);
	if(minid!=-1&&minid!=i) continue;
	if(kmp(x,i)){
	    if(i==0) return true;
	    minid=-1;
	    if(dfs(i)) return true;
	}
	else{
	    ans=ans>x?ans:x;
	    minid=i;
	    break;
	}
    }
    return false;
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int t;
	int cas=1;
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)scanf("%s",str[i]);
//	    printf("%d\n",n);
//	    for(int i=0;i<n;i++) printf("%s\n",str[i]);
	    getnxt();

	    dfs(n-1);
	    if(ans!=-1) ans+=1;

	    printf("Case #%d: %d\n",cas++,ans);
	}



  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
