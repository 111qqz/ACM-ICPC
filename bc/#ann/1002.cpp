#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int N=1E2+5;
int d[N];
int len;
string st,tar,s1,s2,s3;
bool flag;

void solve (string x,string y,string z)
{
    int lx = x.length();
    int ly = y.length();
    int lz = z.length();
    bool debug = false;
    if (x=="anniv"&&y=="er"&&z=="sary")
	debug = true;
    int p;
    int k = 0;
    for ( int i = 0 ; i  < len-lx+1 ; i++ )
    {
	string tmps = st.substr(i,lx);
//	if (debug) cout<<"tmaaaps:"<<tmps<<endl;
	if (tmps==x);
	{
	    p = i;
	   // cout<<"tmps1:"<<tmps<<endl;
	    k++;
	    break;
	}
    }
    if (k==0) return;

    for ( int i =  p+lx ;  i < len - ly +1 ;i++)
    {
	string tmps = st.substr(i,ly);
    //	if (debug) cout<<"tms2:"<<tmps<<endl;
	if (tmps==y)
	{
	    p = i ;
	  //  cout<<"tmps2:"<<tmps<<endl;
	    k++;
	    break;
	}
    }
    if (k==1) return ;
    for ( int i = p+ly;  i < len - lz +1 ; i ++)
    {
	string tmps = st.substr(i,lz);
	if (tmps==z)
	{
	//    cout<<"tmps3:"<<tmps<<endl;
	    k++;
	    break;
	}
    }
    if (k==3)
    {
	flag = true;
	return;
    }

}
int main()
{
    int T; 
    cin>>T;
    while (T--)
    {
	  flag = false;
	  cin>>st;
	  len = st.length();
	  int k = 0;
	  int num = 0;
	  tar="anniversary";
	  for ( int i = 1 ; i <=9 ;  i++ )
	  {
	    for ( int j = i+1 ; j <= 10 ; j++ )
		{
		    s1 = tar.substr(0,i);
		    s2 = tar.substr(i,j-i);
		    s3 = tar.substr(j);
		 //   cout<<i<<" "<<j<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
		    solve (s1,s2,s3);
		    if (flag)
		    {
			break;
		    }
		}
	    if (flag)
		break;
	  }
	  if (flag)
	    {
		cout<<"YES"<<endl;
	    }
	  else
	    {
		cout<<"NO"<<endl;
	    }

    }
  
	return 0;
}
