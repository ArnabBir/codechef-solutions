#include <bits/stdc++.h>
using namespace std;

unordered_map<long long , long long> m;

long long getCoin(long long n) {
    
    if(m.find(n)!=m.end()) return m[n];
	if(m.find(n)==m.end())
    m[n] = max( n, getCoin(n/2) + getCoin(n/3) + getCoin(n/4));
    return m[n];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	m[1] = 1;
	m[2] = 2;
	m[3] = 3;
	m[4] = 4;
	long long  n;
	while(scanf("%d", &n) != -1) {
	    cout<< getCoin(n) <<endl;
	}
	return 0;
}
