#include <bits/stdc++.h>

#define MOD 1000000007;

using namespace std;

long long dp[1025][101];
long long  p[101];
int n;
vector < long long > a[101];

long long getCombos(long allotment, long i) {
    
    if (allotment == ((1<<n)-1))    return 1;
    if (i > 100) return 0;
    if (dp[allotment][i] != -1) return dp[allotment][i];
    long long w = getCombos(allotment,i+1);
    for (int j = 0; j < a[i].size(); ++j) {
        if (!(allotment & (1 << (a[i][j]-1)))) {
            w = ( w + getCombos(allotment | (1 << (a[i][j]-1)), i+1)) % MOD;
        }
    }
    return dp[allotment][i] = w;
}

int main()
{
   int t;
   cin>>t;

    while (t--)
    {
        cin>>n;
        long long int so;
        for(int i = 0; i < 101; ++i)   a[i].clear();
        memset(p,0,sizeof(p));
        memset(dp,-1,sizeof(dp));
        string s, tmp;
        getline(cin, s);
        for (int i = 1; i <= n; ++i) {
            getline(cin, s);
    		stringstream ss(s);
    		while (ss  >> tmp) {
    			stringstream x;
    			x << tmp;
    			x >> so;
    			a[so].push_back(i);
            }
        }
        cout<<getCombos(0, 1)<<endl;
    }
    return 0;
}
