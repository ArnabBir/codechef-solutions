#include <bits/stdc++.h>
using namespace std;

int calcSmoke(vector<vector<int> > & dp, vector<vector<int> > & val, int low, int high) {
    
    if(dp[low][high] != INT_MAX)   return dp[low][high];
    if(low == high) {
        dp[low][high] = 0;
        return dp[low][high];
    }
    for(int i = low; i < high; ++i) {
        dp[low][high] = min(dp[low][high], calcSmoke(dp, val, low, i) + calcSmoke(dp, val, i+1, high) + val[low][i] * val[i+1][high]);
    }
    return dp[low][high];
}

int main() {
    
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N;
	while(cin>>N) {
	    int a[N];
	    for(int i = 0; i < N; ++i) {
	        cin>>a[i];
	    }
	    vector<vector<int> > dp(N, vector<int> (N, INT_MAX));
	    vector<vector<int> > val(N, vector<int> (N, 0));
	    for(int i = 0; i < N; ++i) {
	        val[i][i] = a[i];
	        for(int j = i+1; j < N; ++j) {
	            val[i][j] = (val[i][j-1] + a[j]) % 100;
	        }
	    }
	    cout<<calcSmoke(dp, val, 0, N-1)<<endl;
	}
	return 0;
}
