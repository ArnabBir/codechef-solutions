#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define MOD2 1000000007 * 1000000007

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	ll n, k, ans, a1, an, d, t1, t2, x, y;
	cin>>t;
	while(t--) {
        cin>>n>>k;
        
        if(k > n) {
            an = k-1;
            d = n-1;
            a1 = an % d;
            t1 = a1 + an;
            t2 = an + d - a1;
            if(t1 % 2 == 0) {
                t1 /= 2;
            }
            else {
                t2 /= 2;
            }
            while(d > 1) {
                x = __gcd(t1, d);
                y = __gcd(t2, d);
                if(x >= y) {
                    t1 /= x;
                    d /= x;
                }
                else {
                    t2 /= y;
                    d /= y;
                }
            }
            ans = ((t1  % MOD)* (t2 % MOD)) % MOD;
        }
        else {
            ans = (k-1) % MOD;
        }
        cout<<ans<<endl;
	}
	return 0;
}