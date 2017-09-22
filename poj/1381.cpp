/* ***********************************************
Author :111qqz
Created Time :2016年08月28日 星期日 01时07分57秒
File Name :code/poj/1381.cpp
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
const int N=105;
int a,b,c,d;
bool ok;
int dep;
int path[N];
int fm;
void dfs(int real,int img,int depth)
{
    if (ok) return ;
    if (depth>100) return;
    if (real==0&&img==0)
    {
	ok = true;
	dep = depth-1;
	return ;
    }
    for ( int i = 0 ; i*i < fm ; i++)
    {
	path[depth] = i;
	int nreal = (real-i)*c+img*d;
	int nimg  = img*c-(real-i)*d;
	if (nreal%fm==0&&nimg%fm==0) dfs(nreal/fm,nimg/fm,depth+1);
	if (ok) return;
    }
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
  int T;
  cin>>T;
  while (T--)
  {
      ms(path,0);
      scanf("%d%d%d%d",&a,&b,&c,&d);
      fm = c*c+d*d;
      ok = false;
      dfs(a,b,0);
      if (ok)
      {
	for (int i = dep ; i >=1 ; i--) printf("%d,",path[i]);
	printf("%d\n",path[0]);
      }
      else
	  puts("The code cannot be decrypted.");
  }
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
