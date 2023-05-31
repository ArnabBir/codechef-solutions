#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k;
	ll x;
	cin>>t;
	while(t--) {
        cin>>n;
        vector<ll> a(n), xa(n);
        for(int i = 0; i < n; ++i)  cin>>a[i];
        cin>>k>>x;
        ll sum = 0, sg = 0;
        int cg = 0, cz = 0, cl = 0;
        for(int i = 0; i < n; ++i)  {
            sum += (ll)a[i];
            xa[i] = (a[i]^x) - a[i];
            if(xa[i] > 0) {
                sg += (ll)xa[i];
                ++cg;
            }
            else if(xa[i] == 0) {
                ++cz;
            }
            else {
                ++cl;
            }
        }
        sort(xa.begin(), xa.end(), comp);
        ll result = 0;
        if(cg == 0) {
           result = sum; 
        }
        else if(n == 1) {
            result = max(a[0], a[0]^x);
        }
        else if(k == 1 || cg%k == 0) {
            result = sum + sg;
        }
        else {
            int q = cg / k, r = cg % k;
            vector<ll> cxa(n+1, 0);
            for(int i = 0; i < n; ++i) {
                     cxa[i+1] = cxa[i] + (ll)xa[i];
            }
            if((q+1)*k <= n) {
                result = sum + max(cxa[q*k], cxa[(q+1)*k]);
            }
            else {
                result = sum + cxa[q*k];
            }
            if(r + cz >= k) {
                result = sum + cxa[cg];
            }
            else if(n == k) {
                result = sum + max((ll)0, cxa[n]);
            }
            else if(r%2 == 0) {
                result = sum + cxa[cg];
            }
            else if((r%2 == 1) && (k%2 == 1)) {
                result = sum + cxa[cg];
            }
            else {
                if(cg < n) {
                    result = max(result, sum + max(cxa[cg-1], cxa[cg+1]));
                }
                else {
                    result = max(result, sum + cxa[cg-1]);
                }
            }
        }
        cout<<result<<endl;
	}
	return 0;
}