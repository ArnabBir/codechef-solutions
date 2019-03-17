#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

long long int nCr(int n,int r) {
    
     long long int num = 1, din = 1, m;
     while(r) {
         num *= n;
         din *= r;
         m = (long long int) __gcd(num, din);
         num /= m;
         din /= m;
         --n;
         --r;
     }
     return num; 
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t, n, k;
	cin>>t;
	while(t--) {
	    cin>>n>>k;
	    --k; --n;
	    if (n-k < k)  k = n-k;
	    cout<<nCr(n, k)<<endl;
	}
	return 0;
}
