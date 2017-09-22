#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
typedef long long LL ;
#define pi acos(-1.0)
const int mod=1e9+7;
const int INF=1e9;
const double eqs=1e-9;
const int N=310;
LL mat[N][N], a[N], equ, var, prime[N];
LL c[N];
LL gauss()
{
    LL i, j, k, h, max_r, tmp;
    for(i=0,j=0;i<equ&&j<var;i++,j++){
	max_r=i;
	for(k=i+1;k<equ;k++){
	    if(mat[k][j]>mat[max_r][j]) max_r=k;
	}
	if(max_r!=i){
	    for(k=j;k<=var;k++){
		swap(mat[i][k],mat[max_r][k]);
	    }
	}
	if(mat[i][j]==0){
	    i--;
	    continue ;
	}
	for(k=i+1;k<equ;k++){
	    if(mat[k][j]==0) continue ;
	    for(h=j;h<=var;h++){
		mat[k][h]^=mat[i][h];
	    }
	}
    }
    tmp=i;
    //printf("%d\n",tmp);
    for(;i<equ;i++){
	if(mat[i][var]){
	    return 0;
	}
    }
    return var-tmp;
}
void output(int k)
{
    LL i, j, x, y, tmp;
    memset(c,0,sizeof(c));
    c[0]=1;
    x=0;
    for(i=0;i<k;i++){
	for(j=0;j<=80;j++){
	    y=(c[j]*2+x)%10;
	    x=(c[j]*2+x)/10;
	    c[j]=y;
	}
    }
    for(i=80;i>=0;i--){
	if(c[i]){
	    tmp=i;
	    break;
	}
    }
    c[0]--;
    for(i=tmp;i>=0;i--){
	printf("%lld",c[i]);
    }
    puts("");
}
void init()
{
    LL i, j, cnt=0, flag;
    for(i=2;;i++){
	flag=0;
	for(j=2;j*j<=i;j++){
	    if(i%j==0){
		flag=1;
		break;
	    }
	}
	if(!flag){
	    prime[cnt++]=i;
	}
	if(cnt==305) return ;
    }
}
LL ksm(LL a,LL b)
{
    LL res = 1LL;
    while (b>0)
    {
	if (b&1)
	    res = (res*a)%MOD;
	b = b/2;
	a = (a*a)%MOD;
    }

    return res;
}

int main()
{

  //  freopen("code/in.txt","r",stdin);
    LL t, n, i, j, x, cnt, ans;
    int T;
    cin>>T;
    int cas = 0 ;
    while (T--){
	printf("Case #%d:\n",++cas);
	init();	
	scanf("%lld",&n);
	t = 305;
	for(i=0; i<n; i++) {
	    scanf("%lld",&a[i]);
	}
	for(i=0; i<n; i++) {
	    x=a[i];
	    for(j=0;j<t;j++){
		cnt=0;
		while(x%prime[j]==0){
		    cnt++;
		    x/=prime[j];
		}
		mat[j][i]=(cnt&1);
	    }
	}
	for(i=0;i<t;i++){
	    mat[i][n]=0;
	}
	equ=t;
	var=n;
	ans=gauss();
	if(ans)
	    printf("%lld\n",ksm(2,ans)-1);
	else puts("0");
    }
	    return 0;
}
