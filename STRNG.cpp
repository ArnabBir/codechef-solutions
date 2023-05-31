#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> dpr;

int gcd(int a, int b) {
    if (a > b) {
        swap(a,b);
    }
    while(a%b) {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return b;
}

int gcd_arr(vector<int> a) {
    int n = a.size();
    if (n < 1) return 1;
    int ans = a[0];
    dp[0] = ans;
    for (int i = 1; i < n; ++i) {
        ans = gcd(ans, a[i]);
        dp[i] = ans;
    }
    return ans;
}

int gcd_arr_rev(vector<int> a) {
    int n = a.size();
    if (n < 1) return 1;
    int ans = a[n-1];
    dpr[n-1] = ans;
    for (int i = n-2; i >= 0; --i) {
        ans = gcd(ans, a[i]);
        dpr[i] = ans;
    }
    return ans;
}

int gcd_arr_pos(int x) {
    int n = dp.size();
    if (x == 0) {
        return dpr[1];
    }
    if (x == n-1) {
        return dp[n-2];
    }
    return gcd(dp[x-1], dpr[x+1]);
}

int main() {
	int t, n;
	cin>>t;
	while (t--) {
	    cin>>n;
	    dp.resize(n);
	    dpr.resize(n);
	    vector<int> a(n);
	    for (int i = 0; i < n; ++i) {
	        cin>>a[i];
	    }
	    sort(a.begin(), a.end());
	    int arrgcd = gcd_arr(a);
	    gcd_arr_rev(a);
	    if (arrgcd > 1) {
	        cout<<n<<endl;
	        continue;
	    }
	    int count = 0;
	    for (int i = 0; i < n; ++i) {
	       int gcdpos = gcd_arr_pos(i);
	       if (gcdpos > 1) {
	           ++count;
	       }
	    }
	    cout<<count<<endl;
	}
	return 0;
}