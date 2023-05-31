#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	ll n, x, s, a, b, k;
	ull f;
	cin>>t;
	while(t--) {
        cin>>n;
        x = n;
        s = 0;
        while(x) {
            s += x % 10;
            s %= 10;
            x /= 10;
        }
        k = ((-s % 10) + 10) % 10;
        //cout<<n<<" : ";
        f = (ull)(10 * (ull)n) + k;
        cout<< f <<endl;
	}
	return 0;
}