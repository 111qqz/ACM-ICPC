/* ***********************************************
Author :111qqz
Created Time :2016年01月26日 星期二 15时47分36秒
File Name :code/uva/10194.cpp
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
const int N=1E3+5;

string game[N];
map<string,int>TeamToId;
struct Team
{
    string nam;
    string lowname;
    int a,b,c,d,e,f,g,h,i;

    bool operator<(Team p)const
    {
	if (b>p.b) return true;
	if (b==p.b&&d>p.d) return true;
	if (b==p.b&&d==p.d&&g>p.g) return true;
	if (b==p.b&&d==p.d&&g==p.g&&h>p.h) return true;
	if (b==p.b&&d==p.d&&g==p.g&&h==p.h&&c<p.c) return true;
	if (b==p.b&&d==p.d&&g==p.g&&h==p.h&&c==p.c&&lowname<p.lowname) return true; //把第一个p.b写成p.d。。
	return false;
    }

}team[35];
int g,n;
string touname;

void init()
{
    for ( int i = 0 ; i<=30 ; i++)
    {
	team[i].a=0;
	team[i].b=0;
	team[i].c=0;
	team[i].d=0;
	team[i].e=0;
	team[i].f=0;
	team[i].g=0;
	team[i].h=0;
	team[i].i=0;
    }
}

string tolow( string x)
{
    int len = x.length();
    for ( int i = 0 ; i < len ; i++) x[i]=tolower(x[i]);
    return x;
}
int main()
{
	#ifndef  ONLINE_JUDGE 
	freopen("code/in.txt","r",stdin);
  #endif

	int T;
	cin>>T;
	getchar();
	while (T--)
	{
	    getline(cin,touname);
	    cout<<touname<<endl;
	    TeamToId.clear();
	    scanf("%d",&n);
	    getchar();
	    init();
	    for ( int i = 0 ; i < n ; i++)
	    {
		getline(cin,team[i].nam);
		team[i].lowname=tolow(team[i].nam); //一开始没看到大小写比较字典序的时候不敏感这条...
		TeamToId[team[i].nam]=i;
	    }

	    //check teamname input
	  //  for ( int i = 0 ; i < n ; i++) cout<<i<<" "<<team[i].lowname<<endl;
	    //check map of teamtoid
	  //  for ( int i = 0 ; i < n ; i++) cout<<i<<""<<TeamToId[team[i].nam]<<endl;
	    scanf("%d",&g);
	    getchar();
	    for (  int i = 0 ; i < g ; i++)
	    {
		getline(cin,game[i]);
	    }
	    //check game input
	   // for ( int i = 0 ; i < g ; i++) cout<<i<<" "<<game[i]<<endl;
	    for ( int i = 0 ; i < g ; i++)
	    {

		int p1 = game[i].find('#');
		int p2 = game[i].find('@');
		int p3 = game[i].find('#',p2+1);
		string sformers = game[i].substr(p1+1,p2-p1-1);
		string slatters = game[i] .substr(p2+1,p3-p2-1);
		int formers,latters;
		sscanf(sformers.c_str(),"%d",&formers);
		sscanf(slatters.c_str(),"%d",&latters);
		string formerteam = game[i].substr(0,p1);
		string latterteam = game[i].substr(p3+1);
		int formerid = TeamToId[formerteam];
		int latterid = TeamToId[latterteam];

	//	cout<<"i:"<<i<<" "<<formerteam<<" "<<latterteam<<endl;
		if (formers==latters)
		{
		    team[formerid].e++;
		    team[latterid].e++;  //平局次数++

		    team[formerid].b++;
		    team[latterid].b++; //平局各得1分
		}
		 if(formers>latters)
		{
		    team[formerid].d++;
		    team[latterid].f++;
		    team[formerid].b+=3;
		}
		if (formers<latters)
		{
		    team[formerid].f++;
		    team[latterid].d++;
		    team[latterid].b+=3;
		}
		team[formerid].h+=formers;
		team[latterid].h+=latters;
		team[formerid].c++;
		team[latterid].c++;
		team[formerid].i+=latters;
		team[latterid].i+=formers;

		//check each game
	//	cout<<"formteam:"<<formerid<<" "<<formerteam<<endl;
	//	cout<<"latterteam:"<<latterid<<" "<<latterteam<<endl; ok.
	//	cout<<"formers:"<<formers<<endl;
	//	cout<<"lattets:"<<latters<<endl;                      ok.
	    }
	    for ( int i = 0 ; i < n ; i++) team[i].g=team[i].h-team[i].i;

	    sort(team,team+n);
	    for ( int i = 0 ; i < n ; i++) team[i].a=i+1;
	    

	    for ( int i = 0 ; i < n ; i++)
	    {
		printf("%d) ",team[i].a);
		cout<<team[i].nam<<" ";
		printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",team[i].b,team[i].c,team[i].d,team[i].e,team[i].f,team[i].g,team[i].h,team[i].i);
	    }


	    if (T)
	    {
		puts("");
	    }
	}

  #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
    return 0;
}
