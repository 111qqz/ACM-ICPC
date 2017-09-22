/* ***********************************************
Author :111qqz
Created Time :2016年02月25日 星期四 22时26分16秒
File Name :code/hdu.1085.cpp
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
const int N=9E3+7;
int num_1,num_2,num_5;
int a[N],tmp[N];
int main()
{
    #ifndef  ONLINE_JUDGE 
    freopen("code/in.txt","r",stdin);
  #endif
 
    while (~scanf("%d%d%d",&num_1,&num_2,&num_5))
    {
        if (num_1==0&&num_2==0&&num_5==0) break; 
        ms(a,0);
        int total = num_1+2*num_2+5*num_5;
        for ( int i = 0 ; i <= num_1; i++)
        {
        a[i] = 1;
        tmp[i] = 0;
        }
        
        for ( int j = 0 ; j <= num_1 ; j++)
        {
        for ( int k =  0; k <=num_2 ; k++)
        {
            tmp[j+2*k] += a[j];
        }
        }
        
        for ( int j = 0 ; j <= num_1 +2*num_2 ; j++)
        {
        a[j] = tmp[j];
        tmp[j] = 0 ;
        }
 
        for ( int j = 0 ; j <= num_1+2*num_2 ; j++)
        {
        for ( int k =  0;  k <= num_5 ; k++)
        {
            tmp[j+5*k]+=a[j];
        }
        }
        for ( int j = 0 ; j <= total ; j++)
        {
        a[j] = tmp[j];
        tmp[j] =  0 ;
        }
 
        for ( int i = 0 ; i <= total +1 ; i ++)
        {
        if (a[i]==0)
        {
            printf("%d\n",i);
            break;
        }
        }
    }
 
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}

