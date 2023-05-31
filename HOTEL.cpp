#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    vector<pair<int,int>> times(n);
	    for (int i = 0; i < n; ++i) {
	        cin>>times[i].first;
	    }
	    for (int i = 0;  i < n; ++i) {
	        cin>>times[i].second;
	    }
	    int count = 1, maxcount = 1;
	    sort(times.begin(), times.end());
	    priority_queue<int> et;
	    et.push(times[0].second);
	    for (int i = 1; i < n; ++i) {
	        count = 1;
	        priority_queue<int> temp = et;
	        while (!temp.empty() && times[i].first < temp.top()) {
	            ++count;
	            temp.pop();
	        }
	        et.push(times[i].second);
	        maxcount = max(count, maxcount);
	    }
	    cout<<maxcount<<endl;
	}
	return 0;
}