#include <bits/stdc++.h>
using namespace std;
const int N = 95800;
int n;
int a[N]= {},pcnt=0;
int ispri[N]= {},prime[N];
void getprime()
{
    pcnt = 0;
    ispri[0]=ispri[1]=1;
    for (long long i=2; i<N; i++)
        if (ispri[i]==0)
        {
            prime[++pcnt]=i;
            for (long long j=i*i; j<N; j+=i)
                ispri[j]=1;
        }
}
void pdec(int n)
{
    pcnt = 0;
    for (int i=1; prime[i]*prime[i]<=n; i++)
        if (n%prime[i]==0)
        {
            a[++pcnt]=prime[i];
            n/=prime[i];
            i--;
        }
    if (n!=1) a[++pcnt]=n;
}

int main()
{
    cin>>n;
    if (n==1)
    {
         puts("Nancy");
         return 0;
    }
    getprime();
    pdec(n);
    // for ( int i = 1 ; i <= n ; i++)
    // {
    //     pcnt = 0;
    //     pdec(i);
    //     cout<<i <<" "<<pcnt<<endl;
    // }
    if (pcnt%2==0)
    {
        puts("Johnson");
    }
    else
    {
        puts("Nancy");
    }
    

    return 0;
   
    
} // namespace std;

