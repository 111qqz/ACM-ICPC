/* ***********************************************
Author :111qqz
Created Time :2016年03月08日 星期二 22时25分14秒
File Name :code/class/algorithm/merge.cpp
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
int n ;
int a[N];

void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1],R[n2];

    for ( int i = 0 ; i < n1; i ++)
    {
	L[i] = arr[l+i];
    }

    for ( int j = 0 ; j <= n2 ; j++)
    {
	R[j] = arr[m+1+j];
    }

    i = 0 ;
    j = 0 ;
    k = l;

    while (i<n1&&j<n2)
    {
	if (L[i]<=R[j])
	{
	    arr[k] = L[i];
	    i++;
	}
	else
	{
	    arr[k] = R[j];
	    j++;
	}
	k++;
    }

    while (i<n1)
    {
	arr[k] = L[i];
	i++;
	k++;
    }

    while (j<n2)
    {
	arr[k] = R[j];
	j++;
	k++;
    }

}

void mergesort(int arr[],int l,int r)
{
    if (l<r)
    {
	int m = l +(r-l)/2 ; 
	mergesort(arr,l,m);
	mergesort(arr,m+1,r);
	merge(arr,l,m,r);
    }
}

int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	cin>>n;
	for ( int i = 0 ; i  <n ; i++) cin>>a[i];
	for ( int i = 0 ; i < n ; i++) cout<<a[i]<<" ";
	    
	    puts("");
	mergesort(a,0,n-1);


	for ( int i = 0 ; i < n; i++) cout<<a[i]<<" " ;

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
