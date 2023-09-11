// Link : https://www.codechef.com/problems/MERGEBS

#include <bits/stdc++.h>
using namespace std;

long long calculateMinInversions(string& a, string&b, int n) {
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, INT_MAX));
    dp[0][0] = 0;
    vector<int> az(n+1,0);
    vector<int> bz(n+1,0);
    for (int i = 1; i <= n; ++i) {
        az[i] = az[i-1] + (a[i-1] == '1');
    }
    for (int i = 1; i <= n; ++i) {
        bz[i] = bz[i-1] + (b[i-1] == '1');
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0];
        if (a[i-1] == '0') {
            dp[i][0] += az[i-1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dp[0][i-1];
        if (b[i-1] == '0') {
            dp[0][i] += bz[i-1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int ones = az[i] + bz[j];
            int as = dp[i-1][j];
            int bs = dp[i][j-1];
            if (a[i-1] == '0') {
                as += ones;
            }
            if (b[j-1] == '0') {
                dp[i][j] += ones;
            }
            dp[i][j]
        }
    }
    return dp[n][n];
}

int main() {
	int t, n;
	string a, b;
	cin>>t;
	while (t--) {
	    cin>>n;
	    cin>>a;
	    cin>>b;
	    int maxinv = 0;
	    string curr = "";
	    unordered_map<string, unordered_map<int,long long>> dp;
	    cout<<calculateMinInversions(a, b, n)<<endl;
	}
	return 0;
}
