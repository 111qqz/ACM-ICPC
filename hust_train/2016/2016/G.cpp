/* ***********************************************
Author :111qqz
Created Time :2016年05月28日 星期六 12时33分32秒
File Name :code/hust/2016/G.cpp
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
const int N=1E3+7;
int n;
int a[N];
int main()
{
// 	#ifndef  ONLINE_JUDGE 
//	freopen("code/in.txt","r",stdin);
//  #endif

	while (scanf("%d",&n)!=EOF)
	{
	    for ( int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
	
	    if (next_permutation(a,a+n))
	    {
		for ( int i = 0 ; i < n ; i++) printf("%d ",a[i]);
		printf("\n");
		
	    }
	    else
	    {
	    	puts("WTF!");
	    //	printf("WTF!");
	    }
	}

//  #ifndef ONLINE_JUDGE  
//  fclose(stdin);
//  #endif
    return 0;
}
