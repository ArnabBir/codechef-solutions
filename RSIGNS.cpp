#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007

using namespace std;

ull modular_pow(ull base, ull exponent, ull modulus) {
    
    ull result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	ull k;
	ull f;
	cin>>t;
	while(t--) {
        cin>>k;
        cout<< (ull)((((ull)10) * ((ull) modular_pow(2, k-1, MOD))) % MOD) <<endl;
	}
	return 0;
}