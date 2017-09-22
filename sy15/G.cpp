/* ***********************************************
Author :111qqz
Created Time :Fri 14 Oct 2016 03:19:54 PM CST
File Name :code/sy15/G.cpp
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
int main()
{
#ifndef  ONLINE_JUDGE 
    freopen("code/in2","r",stdin);
#endif
    int T;
    double t,v1,v2;
    scanf("%d",&T);
    for(int i = 1 ; i <= T; i++){
	scanf("%lf%lf%lf",&t,&v1,&v2);
	if(v1==v2){
	    printf("Case #%d: Yes\n",i);
	    continue;
	}
	if(v1*v1*2 > v2*v2){
	    double l = 300.0, r = 600.0;
	    while(r-l>eps){
		double mid = (l+r)/2;
		if(mid/v2 > sqrt((mid-300)*(mid-300)+90000)/v1){
		    r=mid;
		}
		else l=mid;
	    }
//	    printf("R = %f\n",r);
	    double t1 = 900/v1+sqrt((r-300)*(r-300)+90000)/v1;
	    double t2 = t+1200/v2;
	    printf("Case #%d: %s\n",i,(t2>=t1)?"Yes":"No");
	}
	else if(v1*v1*9 > v2*v2){
	    double l = 600.0, r = 900.0;
	    while(r-l>eps){
		double mid = (l+r)/2;
		if(mid/v2 > sqrt((900-mid)*(900-mid)+90000)/v1){
		    r=mid;
		}
		else l=mid;
	    }
//	    printf("R = %f\n",r);
	    double t1= 900/v1+sqrt((900-r)*(900-r)+90000)/v1+sqrt((r-600)*(r-600)+90000)/v1;
	    double t2 = t+1200/v2;
//	    printf("T1 = %f, T2 = %f\n",t1,t2);
	    printf("Case #%d: %s\n",i,(t2>=t1)?"Yes":"No");
	}
	else printf("Case #%d: No\n",i);
    }
#ifndef ONLINE_JUDGE  
    fclose(stdin);
#endif
    return 0;
}
