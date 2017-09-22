#include <iostream>  
#include <cstring>  
#include <stdio.h>  
using namespace std;  
const int N=16000005; //题目给出子串的最大和不超过16M  
const int NUM=257;  
bool Hash[N];  
int m[NUM];  
char str[1000000];

int n,nc,i,j,sum,seed=0,ans=0;  
int main()  
{
  //  freopen("code/in.txt","r",stdin);
    memset(Hash,false,sizeof(Hash));  
    memset(m,0,sizeof(m));  
    memset(str,'\0',sizeof(str));  
    cin>>n>>nc>>str;
    int len = strlen(str);
    for(int i = 0 ; i < len; ++i)  
    {  
        if(!m[str[i]]) //将每个字符赋值为相应进制的数  
            m[str[i]]=++seed;  
        if(seed == nc)  
            break;  
    }  
    for(i=0;i<=len-n;++i)  
    {  
        sum=0;  
        for(j=0;j<n;++j) //将字符串str[i],..,str[i+n-1]变为一个nc进制的整数,来判断是否重复出现过  
            sum=sum*nc+m[str[i+j]]-1;  
	
        if(!Hash[sum])  
        {  
            Hash[sum]=true;  
            ++ans;  
        }  
    }  
    cout<<ans<<endl;  
    return 0;  
}  
