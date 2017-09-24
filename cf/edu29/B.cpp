/* ***********************************************
Author :111qqz
Created Time :2017年09月24日 星期日 13时57分04秒
File Name :B.cpp
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
const int N=107;
int n;
int w[N];
bool single[N];
void print( vector<int> x)
{
    int siz = x.size();
    for ( int i = 0 ; i < siz ; i++) printf("%d ",x[i]);
    printf("\n");
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("./in.txt","r",stdin);
  #endif
	cin>>n;
	n*=2;
	ms(single,false);
	int ret = inf;
	int sum = 0;
	for ( int  i = 1 ; i <= n ; i++) scanf("%d",&w[i]);
	for ( int i = 1 ; i <= n  ; i++)
	{
	    single[i] = true;
	    for ( int j = i+1 ; j<= n ;j++)
	    {
		single[j] = true;
		vector<int>team;
		for ( int k = 1 ; k <= n ; k++)
		    if (!single[k]) team.push_back(w[k]);
		sort(team.begin(),team.end());
//		print(team);
		//cout<<"team_size:"<<team.size()<<endl;
		int siz = team.size();
		sum =  0;
		for ( int i = 0 ; i < siz ; i+=2)
		{
		    sum = sum + abs(team[i]-team[i+1]);
		}
		ret = min(ret,sum);
		single[j]=false;
	    }
	    single[i]=false;
	}
	printf("%d\n",ret);


  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
