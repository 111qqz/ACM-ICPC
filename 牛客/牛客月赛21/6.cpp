#include <bits/stdc++.h>
using namespace std;
const int N = 70;
int n;
double score[N]={0.0};
double xuefen[N] = {0.0};
double totalxuefen = 0.0;
int main()
{
    cin>>n;
    for ( int i = 0 ; i < n ;i++)
    {
        int xz;
        double  xf,score1,rate1,score2,rate2,score3,rate3;
        cin>>xz>>xf>>score1>>rate1>>score2>>rate2>>score3>>rate3;
        if (xz==2) continue;
        xuefen[i] = xf;
        totalxuefen += xf;
        score[i] = score1 * rate1 + score2 * rate2 + score3 * rate3;
    }

    double ans = 0;
    for ( int i = 0 ; i < n ; i++)
    {
        if (xuefen[i] == 0) continue;
        double rate = xuefen[i] / totalxuefen;
        ans = ans + round(score[i])*rate;
    }
    printf("%.2f\n",round(ans*100)/100);
    return 0;
    
} // namespace std;

