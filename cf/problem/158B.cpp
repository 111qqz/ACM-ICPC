/* ***********************************************
Author :111qqz
Created Time :2015年12月06日 星期日 17时34分21秒
File Name :code/cf/problem/158B.cpp
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



using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
const int N=1E5+7;
int n;
int s[N];
int ans;
int cnt[5];

void print()
{
    printf("%d %d %d %d %d\n",cnt[1],cnt[2],cnt[3],cnt[4],ans);
}
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
#endif

    cin>>n;
    ms(cnt,0);
    ans  = 0 ;
    for ( int i = 0 ;i < n ;i++)
    {
	cin>>s[i];
	cnt[s[i]]++;
    }

  //  printf("%d %d %d %d\n",cnt[1],cnt[2],cnt[3],cnt[4]);  //贪心思路：人数少的优先取和优先多的拼车。
  //  cout<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<" "<<cnt[4]<<endl;
    ans += cnt[4];
    ans += cnt[3];
    cnt[1] -= cnt[3];
    cnt[1] = max(0,cnt[1]);
  //  print();

    int tmp = min(cnt[2],cnt[1]/2);
    ans += tmp;
    cnt[2] -= tmp;
    cnt[1] -= 2*tmp;
 //   print();
       
    cnt[1] = max(0,cnt[1]);
    if (cnt[2]==0)
    {
	ans +=cnt[1]/4;
	cnt[1] %= 4;
	if (cnt[1]>0) ans++;
    }
    else
    {
	ans += cnt[2]/2;
	cnt[2] %=2;
	if (cnt[1]||cnt[2])
	    ans++;
    }
    
    cout<<ans<<endl;


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
