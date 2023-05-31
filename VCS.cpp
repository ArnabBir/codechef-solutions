#include <bits/stdc++.h>

using namespace std;

pair<int,int> count_files(unordered_set<int> ignored, unordered_set<int> tracked, int n) {
    pair<int,int> result;
    result.first = 0;
    result.second = 0;
    for (int i = 1; i <= n; ++i) {
        if ( (ignored.find(i) != ignored.end()) && (tracked.find(i) != tracked.end())) {
            ++result.first;
        } else if ( (ignored.find(i) == ignored.end()) && (tracked.find(i) == tracked.end())) {
            ++result.second;
        }
    }
    return result;
}

int main() {
	int t, n, m, k;
	cin>>t;
	while (t--) {
	    cin>>n>>m>>k;
	    unordered_set<int> ignored(m);
	    unordered_set<int> tracked(k);
	    int readint;
	    for (int i = 0; i < m; ++i) {
	        cin>>readint;
	        ignored.insert(readint);
	    }
	    for (int i = 0; i < k; ++i) {
	        cin>>readint;
	        tracked.insert(readint);
	    }
	    pair<int,int> result = count_files(ignored, tracked, n);
	    cout<<result.first<<" "<<result.second<<endl;
	}
	return 0;
}