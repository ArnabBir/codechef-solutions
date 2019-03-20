#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x, y;
    long long int maxTip = 0;
	cin>>n>>x>>y;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) {
	    cin>>a[i];
	}
	for(int i = 0; i < n; ++i) {
	    cin>>b[i];
	}
	vector<pair<int, int>> diffPair;
	
	for(int i = 0; i < n; ++i) {
	    diffPair.push_back(make_pair(abs(a[i]-b[i]), i));
	}
	sort(diffPair.begin(), diffPair.end());
	for(int i = n-1; i >= 0; --i) {
	    int index = diffPair[i].second;
	    if(a[index] > b[index]) {
	        if(x > 0) {
	            maxTip += a[index];
	            --x;
	        }
	        else {
	            maxTip += b[index];
	            --y;
	        }
	    }
	    else {
	        if(y > 0) {
	            maxTip += b[index];
	            --y;
	        }
	        else {
	            maxTip += a[index];
	            --x;
	        }
	    }
	}
	cout<<maxTip<<endl;
	return 0;
}
