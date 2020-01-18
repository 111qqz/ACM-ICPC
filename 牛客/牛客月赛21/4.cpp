#include <bits/stdc++.h>
using namespace std;
const int N = 7E5+7;
typedef long long LL;
LL H[N][9];
const LL MOD = 20010905LL;
string S,T;

int numDistinct(string S, string T) {
        int m = S.length();
        int n = T.length();
        if(m == 0)
            return 0;
        H[0][0] = 1;
        for(int i=1;i<=m;i++)
            H[i][0] = 1;
        for(int i=1;i<=n;i++)
            H[0][i] = 0;
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                H[i][j] = (H[i-1][j] + ((S[i-1] == T[j-1])?H[i-1][j-1]:0))%MOD;
        return H[m][n];
}
int main()
{
    cin>>S;
    T = "iloveyou";
    std::transform(S.begin(), S.end(), S.begin(),
    [](unsigned char c){ return std::tolower(c); });
    LL ans = numDistinct(S,T);
    cout<<ans<<endl;


    
    return 0;
    
} // namespace std;

