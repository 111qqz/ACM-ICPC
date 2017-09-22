#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int N=80;
const double eps = 1E-8;
char s[N][N];
bool vis[N][N];
bool ok=false;
long long sum;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n,m;
long long tar;

bool good ( int x,int y)
{
    if (x>=0&&x<n&&y>=0&&y<m) return true;
    return false;
}
void dfs(int i,int j,double sum,char ch) {
    if (fabs(sum-tar)<1e-8) ok=true;
    if (ok) return;
    if (vis[i][j]) return;
    vis[i][j]=true;
    double val=s[i][j]-'0';
    double ns=sum;
//    if (ch=='+') ns=sum+nv;
  //  else if (ch=='-') ns=sum-nv;
   //else if (ch=='*') ns=sum*nv;
   // else if (ch=='/') ns=sum/nv;
    
    for (int k=0;k<4;k++) {
        int ni=i+2*dx[k];
        int nj=j+2*dy[k];
     //   if (ni<0||nj<0||ni>=n||nj>=m) continue;
	if (!good(ni,nj)) continue;
	char opt = s[i+dx[k]][j+dy[k]];
	if (opt=='+')
	{
	    ns = sum+val;
	}
	if (opt=='-')
	{
	    ns = sum - val;
	}
	if (opt=='*')
	{
	    ns = sum *val;
	}
	if (opt=='/')
	{
	    ns = sum/val;
	}
        char nch=s[i+dx[k]][j+dy[k]];
        dfs(ni,nj,ns,nch);
    }
    vis[i][j]=false;
}
int main () {
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++) {
        cin>>n>>m>>tar;
        for (int i=0;i<n;i++)
            scanf("%s",s[i]);
        ok=false;
        for (int i=0;i<n&&!ok;i+=2) {
            for (int j=0;j<m&&!ok;j+=2) {
                memset(vis,false,sizeof vis);
                dfs(i,j,s[i][j]-'0','#');
            }
        }
        if (ok) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
