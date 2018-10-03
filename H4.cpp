#include <bits/stdc++.h>

using namespace std;

int exp(int x, long long p, int m) {

	if(m == 1) return 0;
	x %= m;
	if(p == 1) return x;
	int result = exp(x, p/2, m);
	if(p % 2 == 0) {
		return ((result % m) * (result % m)) % m;
	} 
	else {
		return ((result % m) * (result % m) * x) % m;
	}	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, m;
	long long n;
	int result;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		result = 0;
		for(long long i = 1; i <= n; ++i) {
			result = (result + exp((i%m), i, m)) % m;
		}
		cout<<result<<endl;
	}

	return 0;
}
