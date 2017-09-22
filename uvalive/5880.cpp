/* ***********************************************
Author :111qqz
Created Time :2016年08月19日 星期五 21时13分52秒
File Name :code/uvalive/5880.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
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
const int N=1E5+7;
char key[N];
char txt[N];
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	while (~scanf("%s",key))
	{
	    if (key[0]=='0') break;
	    scanf("%s",txt);
	    int len = strlen(txt);
	    int len2 = strlen(key);
	    for ( int i = 0 ; i < len ; i++)
	    {
		int cur = i % len2;
		int v = txt[i]-'A';
		v = (v + key[cur]-'A'+1)%26;
		printf("%c",char(v+65));
	    }
	    printf("\n");
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
