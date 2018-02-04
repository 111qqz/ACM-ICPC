#include<stdio.h>
 #include<stdlib.h>
 #include<cmath>
typedef long long LL;
bool witness(long long a,long long  n)
 {
 long long t,d,x;
 d=1;
 int i=ceil(log(n-1.0)/log(2.0)) - 1;
 for(;i>=0;i--)
 {
 x=d; d=(d*d)%n;
 if(d==1 && x!=1 && x!=n-1) return true;
 if( ((n-1) & (1<<i)) > 0)
 d=(d*a)%n;
 }
 return d==1? false : true;
 }
bool miller_rabin(long long  n)
 {
 if(n==2) return true;
 if(n==1 || ((n&1)==0)) return false;
 for(int i=0;i<50;i++){
 long long  a=rand()*(n-2)/RAND_MAX +1;
 if(witness(a, n)) return false;
 }
 return true;
 }
int main()
 {
 int n,cnt;
 int  a;
 int T;
 scanf("%d",&T);
 cnt=0;
 while(T--)
 {
 scanf("%d",&a);
 if (a==4)
{
    printf("%d\n",2);
    continue;
}
 if(miller_rabin(a))
 {
     printf("%d\n",a-1);
 }
 else
{
    printf("%d\n",0);
}

 
 }
 return 0;
 }
