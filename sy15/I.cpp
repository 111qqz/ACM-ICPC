/* ***********************************************
Author :111qqz
Created Time :Fri 14 Oct 2016 01:56:18 PM CST
File Name :code/sy15/I.cpp
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
const int maxn = 1e5+10;
int n,m,c1[maxn],c2[maxn],m1[maxn],m2[maxn];
int tot1,tot2;

struct Sing{
    int a,cnt;
    Sing(int par1=0,int par2=0):
	a(par1),cnt(par2){

	}
}
struct Doub{
    int a,b,cnt;
    Doub(int par1=0,int par2=0,int par3=0):
	a(par1),b(par2),cnt(par3){

	}
}A[maxn],MA[maxn],MB[maxn];
struct Trip{
    int c,d,e,cnt;
    Trip(int par1=0,int par2=0,int par3=0,int par4=0):
	c(par1),d(par2),e(par3),cnt(par4){

	}
}B[maxn];

bool operator < (Doub a,Doub b){
    if(a.b != b.b)return a.b<b.b;
    else return a.a<b.a;
}
bool operator < (Trip a,Trip b){
    if(a.e != b.e)return a.e<b.e;
    else{
	return (a.c==b.c)?(a.d<b.d):(a.c<b.c);
    }
}

void Update(int px,int de,int* c,int n){
    while(px<=n){
	c[px]+=de;
	px+=lowbit(px);
    }
}
int Sum(int px,int* c){
    int res = 0;
    while(px >= 0){
	res += c[px];
	px -= lowbit(px);
    }
    return res;
}
void init(){
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    memset(MA,0,sizeof(MA));
    memset(MB,0,sizeof(MB));
}
void input(){
    int x,y,z;
    scanf("%d%d",&n,&m);
    int c=1;
    A[1] = Doub(0,0,0);
    B[1] = Trip(0,0,0,0);
    for(int i = 1; i <= n; i++){
	scanf("%d%d",&x,&y);
	if(x==A[c].a && y==A[c].b){
	    A[c].cnt ++;
	}
	else{
	    A[++c] = Doub(x,y,1);
	}
    }
    c=1;
    for(int j = 1; j <= m; j++){
	scanf("%d%d%d",&x,&y,&z);
	if(x==B[c].c && y==B[c].d && z==B[c].e){
	    B[c].cnt ++;
	}
	else{
	    B[++c] = Trip(x,y,z,1);
	}
    }
}

void work(){
    init();
    input();
    sort(A+1,A+tot1+1);
    sort(B+1,B+tot2+1);

    int tx=1;
    for(int i = 2; i <= tot1; i++){
	if(A[i].b != A[i-1].b){
	    MA[A[i-1].b] = Doub(tx,i-1);
	    tx = i;
	}
    }
    if(tx<=tot1){
	MA[A[tot1].b] = Doub(tx,tot1);
    }
    tx = 1;
    for(int i = 2; i <= tot2; i++){
	if(B[i].e != B[i-1].e){
	    MB[B[i-1].e] = Doub(tx,i-1);
	    tx = i;
	}
    }
    if(tx<=tot2){
	MB[B[tot2].e] = Doub(tx,tot2);
    }
    for(int i = 1; i <= 100000; i++){
	if(MA[i] == MB[i])solve(i);
	res += 1LL*(m1[i]*(MB[i].b-MB[i].a+1) + m2[i]*(MA[i].b-MA[i].a+1));
	res -= 1LL*m1[i]*m2[i];
    }
    long long res = 0;
    
    
}
int main(){
  #ifndef  ONLINE_JUDGE 
  freopen("code/in.txt","r",stdin);
  #endif
  
  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
