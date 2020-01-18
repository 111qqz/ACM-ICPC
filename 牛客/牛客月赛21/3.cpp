#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t1,t2;
LL total;
LL ans = 0;
int main()
{
    while(cin>>t1>>t2)
    {
        //  把节目和休息算成整体
        LL time1 = (t1-1)/60 + 1;
        LL time2 = (t2-1)/60 + 1;
        // cout<<"time1:"<<time1<<" time2:"<<time2<<endl;

        if (time1 == time2)
        {
            ans = min(t2,time2*60-10) - t1;
            ans = max(ans,0LL);
        }
        else
        {
            ans = max(0LL,time1*60-10-t1+1) + (time2-time1)*50 + (min(t2,time2*60-10) - (time2*60-10));
        }
        cout<<ans<<endl;
    }

    return 0;
    
} // namespace std;

