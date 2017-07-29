/* ***********************************************
Author :111qqz
Created Time :2017年07月25日 星期二 13时19分39秒
File Name :1001.cpp
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
int m;
int main()
{
        #ifndef  ONLINE_JUDGE 
//        freopen("./in.txt","r",stdin);
  #endif
    int p = 1;
    int cas = 0 ;
    while (~scanf("%d",&m))
    {
	// k<= m *ln(2)/ln(10)
	int ans = int(1.0*m*log(2)/log(10));
	printf("Case #%d: %d\n",++cas,ans);

    }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
