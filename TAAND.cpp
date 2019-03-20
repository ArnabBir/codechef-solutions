#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int> v(n), maxVals;
	int maxAnd = 0;
	for(int i = 0; i < n; ++i) {
	    cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n-1; ++i) {
	    maxAnd = max(maxAnd, v[i] & v[i+1]);
	}
 	cout<<maxAnd<<endl;
	return 0;
}
