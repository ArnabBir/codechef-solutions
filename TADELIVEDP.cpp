#include <bits/stdc++.h>
using namespace std;

long long int * dp;
long long int maxTip = 0;

void getMaxTip(vector<int> & a, vector<int> & b, int x, int y, int curr, int end) {
    
    if(curr == end) {
        maxTip = max(maxTip, dp[curr-1]);
        return;
    }
    int prevVal = dp[curr];
    if(x > 0) {
        if(curr == 0)   dp[curr] = a[curr];
        else dp[curr] = dp[curr-1] + a[curr];
        getMaxTip(a, b, x - 1, y, curr+1, end);
        dp[curr] = prevVal;
    }
    if(y > 0) {
        if(curr == 0)   dp[curr] = b[curr];
        else dp[curr] = dp[curr-1] + b[curr];
        getMaxTip(a, b, x, y - 1, curr+1, end);
        dp[curr] = prevVal;
    }
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, y;
	cin>>n>>x>>y;
	vector<int> a(n), b(n);
	dp = new long long int[n];
	memset(dp, 0, sizeof dp);
	for(int i = 0; i < n; ++i) {
	    cin>>a[i];
	}
	for(int i = 0; i < n; ++i) {
	    cin>>b[i];
	}
	getMaxTip(a, b, x, y, 0, n);
	cout<<maxTip<<endl;
	return 0;
}
