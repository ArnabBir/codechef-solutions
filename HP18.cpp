#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        swap(a,b);
    }
    int rem;
    while (a%b) {
        rem = a%b;
        a = b;
        b = rem;
    }
    return b;
}

int lcm(int a, int b) {
    return (a*b)/(gcd(a,b));
}

int main() {
	int t, n, a, b;
	cin>>t;
	while (t--) {
	    cin>>n>>a>>b;
	    vector<int> arr(n);
	    for (int i = 0; i < n; ++i) {
	        cin>>arr[i];
	    }
	    //int c = lcm(a,b);
	    int acount = 0, bcount = 0, ccount = 0;
	    for (int i = 0; i < n; ++i) {
	        if (arr[i]%a==0 && arr[i]%b==0) {
	            ++ccount;
	        } else if (arr[i]%b==0) {
	            ++bcount;
	        } else if (arr[i]%a==0) {
	            ++acount;
	        }
	    }
	    cout << (acount > bcount - (ccount > 0) ? "BOB\n" : "ALICE\n");
	}
	return 0;
}