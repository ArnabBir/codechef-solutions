#include <bits/stdc++.h>
using namespace std;

vector<long long int> bitAND(30, 0);

int main() {
    
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	vector<int> v(N);
	long long int sum = 0;
	for(int i = 0; i < N; ++i) {
	    cin>>v[i];
	    for(int j = 0; j < 30; ++j) {
	        bitAND[j] += (v[i] & 1<<j) ? 1 : 0;
	    }
	}
	for(int i = 0; i < 30; ++i) {
	    sum += (long long int) bitAND[i] * (bitAND[i]-1) / 2 * (1<<i);
	}
	cout<<sum<<endl;
	return 0;
}
