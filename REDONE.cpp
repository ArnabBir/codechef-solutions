#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;


int main() {
	
	int t, n;
	vector<unsigned long long int> fact(1000002);
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= 1000001; ++i)   fact[i] = (fact[i-1] * i) % MOD;
	cin>>t;
	while(t--) {
	    cin>>n;
	    cout<<fact[n+1]-1<<endl;
	}
	return 0;
}
