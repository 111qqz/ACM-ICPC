/* ***********************************************
Author :111qqz
Created Time :2016年01月22日 星期五 03时25分16秒
File Name :code/uva/537.cpp
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
#define MP make_pair
using namespace std;
const double eps = 1E-8;
const int dx4[4]={1,0,0,-1};
const int dy4[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;
string str;
char cstr[20];
double i,p,u;
int pu,pp;
int pi;
int pv,pw,pa;
int beishu;
string tmp;
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif
	int T;
	int cas = 0;
	cin>>T;
	getchar();
	while (T--)
	{
	    beishu = 0;  //多组数据。。。忘记每次都初始化==
	    printf("Problem #%d\n",++cas);
	    getline(cin,str);
//	    cout<<"str:"<<str<<endl;
	    pu=str.find("U=");
	    pi=str.find("I=");
	    pp=str.find("P=");
//	    cout<<"pi:"<<pi<<" pu:"<<pu<<" pp:"<<pp<<endl;
	    if (pp==-1)
	    {
		pv=str.find('V',pu+1);
		pa=str.find('A',pi+1);

		if (str[pv-1]=='m'||str[pv-1]=='k'||str[pv-1]=='M')
		{
		    if (str[pv-1]=='m')
		    {    
			beishu-=3;
			tmp = str.substr(pu+2,pv-pu-3);
		    }
		    if (str[pv-1]=='k')
		    {
			beishu+=3;
			tmp = str.substr(pu+2,pv-pu-3);
		    }
		    if (str[pv-1]=='M')
		    {
			beishu+=6;
			tmp = str.substr(pu+2,pv-pu-3);
		    }
		}
		else
		{
		    tmp = str.substr(pu+2,pv-pu-2);
		}
	    
		strcpy(cstr,tmp.c_str());
		sscanf(cstr,"%lf",&u);
//		cout<<"u:"<<u<<endl;
		if (str[pa-1]=='m'||str[pa-1]=='k'||str[pa-1]=='M')
		{
		    if (str[pa-1]=='m')
		    {
			beishu-=3;
			tmp = str.substr(pi+2,pa-pi-3);
		    }
		    if (str[pa-1]=='k')
		    {
			beishu+=3;
			tmp = str.substr(pi+2,pa-pi-3);
		    }
		    if (str[pa-1]=='M')
		    {
			beishu+=6;
			tmp = str.substr(pi+2,pa-pi-3);
		    }
		}
		else
		{
		    tmp = str.substr(pi+2,pa-pi-2);
		}
		strcpy(cstr,tmp.c_str());
		sscanf(cstr,"%lf",&i);
//		cout<<"i:"<<i<<endl;

		p = 1.0;
		if (beishu<0)
		{
		    for ( int i = 1 ; i <= abs(beishu) ; i++)
		    {
			p = p*0.1;
		    }
		}
		else
		{
		    for ( int i = 1 ; i <= beishu ; i++)
		    {
			p = p * 10;
		    }
		}
		p = p*u*i;
		printf("P=%.2fW\n",p);
	    }
	    if (pi==-1)
	    {
		pv = str.find('V',pu+1);
		pw = str.find("W",pp+1);
		if (str[pv-1]=='m'||str[pv-1]=='k'||str[pv-1]=='M')
		{
		    if (str[pv-1]=='m')
		    {    
			beishu+=3;
			tmp = str.substr(pu+2,pv-pu-3);
		    }
		    if (str[pv-1]=='k')
		    {
			beishu-=3;
			tmp = str.substr(pu+2,pv-pu-3);
		    }
		    if (str[pv-1]=='M')
		    {
			beishu-=6;
			tmp = str.substr(pu+2,pv-pu-3);
		    }
		}
		else
		{
		    tmp = str.substr(pu+2,pv-pu-2);
		}
	    
		strcpy(cstr,tmp.c_str());
		sscanf(cstr,"%lf",&u);
//		cout<<"u:"<<u<<endl;

		if (str[pw-1]=='m'||str[pw-1]=='k'||str[pw-1]=='M')
		{
		    if (str[pw-1]=='m')
		    {
			beishu-=3;
			tmp = str.substr(pp+2,pw-pp-3);
		    }
		     if (str[pw-1]=='k')
		    {
			beishu+=3;
			tmp = str.substr(pp+2,pw-pp-3);
		    }
		    if (str[pw-1]=='M')
		    {
			beishu+=6;
			tmp = str.substr(pp+2,pw-pp-3);
		    }
		   
		}
		else
		{
		    tmp = str.substr(pp+2,pw-pp-2);
		}

		strcpy(cstr,tmp.c_str());
		sscanf(cstr,"%lf",&p);
//		cout<<"p:"<<p<<endl;
		
		i=1.0;
		if (beishu<0)
		{
		    for ( int i = 1 ; i <=abs(beishu) ; i++)
		    {
			i=i*0.1;
		    }
		}
		else
		{
		    for ( int i = 1 ; i <= beishu ; i++)
		    {
			i=i*10;
		    }
		}
		i = i*p/u;
		printf("I=%.2fA\n",i);	
	    }

	    if (pu==-1)
	    {
		pa = str.find('A',pi);
		pw = str.find('W',pp);
		if (str[pa-1]=='m'||str[pa-1]=='k'||str[pa-1]=='M')
		{
		    if (str[pa-1]=='m')
		    {
			beishu+=3;
			tmp = str.substr(pi+2,pa-pi-3);
		    }
		    if (str[pa-1]=='k')
		    {
			beishu-=3;
			tmp = str.substr(pi+2,pa-pi-3);
		    }
		    if (str[pa-1]=='M')
		    {
			beishu-=6;
			tmp = str.substr(pi+2,pa-pi-3);
		    }
		}
		else
		{
		    tmp = str.substr(pi+2,pa-pi-2);
		}
		strcpy(cstr,tmp.c_str());
		sscanf(cstr,"%lf",&i);
//		cout<<"i:"<<i<<endl;

		if (str[pw-1]=='m'||str[pw-1]=='k'||str[pw-1]=='M')
		{
		    if (str[pw-1]=='m')
		    {
			beishu-=3;
			tmp = str.substr(pp+2,pw-pp-3);
		    }
		     if (str[pw-1]=='k')
		    {
			beishu+=3;
			tmp = str.substr(pp+2,pw-pp-3);
		    }
		    if (str[pw-1]=='M')
		    {
			beishu+=6;
			tmp = str.substr(pp+2,pw-pp-3);
		    }
		   
		}
		else
		{
		    tmp = str.substr(pp+2,pw-pp-2);
		}

		strcpy(cstr,tmp.c_str());
		sscanf(cstr,"%lf",&p);
//		cout<<"p:"<<p<<endl;


		u = 1;
		if (beishu<0)
		{
		    for ( int i = 1 ; i <=abs(beishu) ; i++)
		    {
			u *=0.1;
		    }
		}
		else
		{
		    for ( int i = 1 ; i <= beishu ; i++)
		    {
			u *=10;
		    }
		}
		u = u*p/i;
		printf("U=%.2fV\n",u);


	    }
	    printf("\n");


	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
